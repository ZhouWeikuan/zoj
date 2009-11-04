#include<iostream>

enum {
	P = 40,
	N = 40,	
};

using namespace std;

int relate[P][N];
int pos[P];
int cno;
int match[N];
int visit[N];
int card[2][N];

int dfs(int p){
	int i,t;
	int s;
	for(i=0;i<pos[p];i++){
		s = relate[p][i];
		if(0== visit[s]){
			visit[s] = 1;
			t = match[s];
			match[s] = p;
			if(t==-1 || dfs(t))
				return 1;
			match[s] = t;
		}
	}
	return 0;
}

int fun(){
    int i,res = 0;
    memset(match,-1,sizeof(int)*cno);
    for(i=0; i<cno; i++){
		memset(visit,0,sizeof(int)*cno);
		if(dfs(i))
			res++;
	}
	return res;
}

int getValue(char *s){
	int t;
	if(s[0] <='9' && s[0] >='2'){
		t = s[0] - '0';
	}else {
		t = 10;
		switch(s[0]){
			case 'A':
				t++;
			case 'K':
				t++;
			case 'Q':
				t ++;
			case 'J':
				t ++;
			case 'T':
				break;
		}
	}
	t <<= 8;
	switch(s[1]){
		case 'H':
			t ++;
		case 'S':
			t++;
		case 'D':
			t++;
		case 'C':
			break;
	}
	return t;
}

int main(){
    int tstcase;
    int i,j;
    int num;
	char buffer[4];
    
    cin>>tstcase;
    while(tstcase --){
		cin>>cno;		
		for(i=0;i<cno;i++){
			cin>>buffer;
			card[1][i] = getValue(buffer);
		}
		for(i=0;i<cno;i++){
			cin>>buffer;
			card[0][i] = getValue(buffer);
		}
		for(i=0;i<cno;i++){
			pos[i] = 0;
			for(j=0;j<cno;j++){
				if(card[0][i] > card[1][j]){
					relate[i][pos[i]] = j;
					pos[i] ++;
				}
			}
		}
		
		i = fun();		
		cout<<i<<endl;
	}
    
    return 0;
}
