#include<iostream>

enum {
	P = 108,
	N = 308,	
};

using namespace std;

int course[P][N];
int pos[P];
int sno;
int cno;
int match[N];
int visit[N];

int dfs(int p){
	int i,t;
	int s;
	for(i=0;i<pos[p];i++){
		s = course[p][i];
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
    memset(match,-1,sizeof(int)*sno);
    for(i=0; i<cno; i++){
		memset(visit,0,sizeof(int)*sno);
		if(dfs(i))
			res++;
	}
	return res;
}

int main(){
    int tstcase;
    int i;
    int num;
    
    cin>>tstcase;
    while(tstcase --){
		cin>>cno>>sno;		
		for(i=0;i<cno;i++){
			cin>>pos[i];
			num = 0;
			while(num < pos[i]){
				cin>>course[i][num];
				course[i][num]--;
				num ++;
			}			
		}
		i = fun();		
		if(i== cno){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
    
    return 0;
}
