#include<cstdio>
#include<set>
#include<queue>

using namespace std;
int num;
set<char> mat[200][200];
char buf[32];
set<int> edge[200];
int bitmask[200]= {0};

int make(int a,int b, char c){
	if(a == b)
		return 1;
	int ret = 0;
	bitmask[a] = 1;
	for(set<int>::iterator it = edge[a].begin();
		it != edge[a].end(); it++){
		if(mat[a][*it].find(c)!= mat[a][*it].end() && bitmask[*it]==0	){
			bitmask[*it] =1;
			ret = make(*it,b,c);
			bitmask[*it] = 0;
			if(ret)
				break;
		}
	}
	if(ret ){
		edge[a].insert(b);
		mat[a][b].insert(c);
	}
	bitmask[a] = 0;
	return ret;
}

void getInput(){
	int a,b;
	int i;
	set<char> q;
	scanf("%d%d",&a,&b);
	while(a){
		a --, b --;
		scanf("%s",buf);
		for(i=0;buf[i];i++){
			mat[a][b].insert(buf[i]);
			q.insert(buf[i]);
		}
		edge[a].insert(b);
		q.insert((a<<8)+b);
		scanf("%d%d",&a,&b);
	}
	for(set<char>::iterator it=q.begin();
		it!=q.end();it++){
		for(a=0;a<num;a++){
			for(b=0;b<num;b++){
				make(a,b,*it);
			}
		}
	}
}

void query(){
	int a,b;
	
	scanf("%d%d",&a,&b);
	while(a){
		a--,b--;
		if(mat[a][b].size() ==0){
			printf("-\n");
		} else {
			for(set<char>::iterator it = mat[a][b].begin();
				it != mat[a][b].end(); it++){
				printf("%c",*it);
			}
			printf("\n");
		}
		scanf("%d%d",&a,&b);
	}
	for(a=0;a<num;a++){
		for(b=0;b<num;b++)
			mat[a][b].clear();
	}
	for(a=0;a<num;a++)
		edge[a].clear();

	printf("\n");
}

int main(){
	
	scanf("%d",&num);
	while(num){
		getInput();
		query();
		scanf("%d",&num);
	}

	return 0;
}
