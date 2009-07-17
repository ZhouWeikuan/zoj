#include<iostream>
#include<cmath>

using namespace std;
enum {
    SZ = 132,
};

int tab[SZ][SZ];
int mat[SZ];
int vis[SZ];
int num;

int dfs(int p){
  int i,t;
  for(i=0;i< num;i++)
    if(tab[i][p] && !vis[i]){
      vis[i]=1;
      t=mat[i];
      mat[i]=p;
      if(t==-1 || dfs(t))
          return 1;
      mat[i]=t;
    }
  return 0;
}

int get_match(){
  int i,res=0;
  memset(mat,-1,sizeof(mat));
  for(i=0;i< num;i++){
      memset(vis,0,sizeof(vis));
      if(dfs(i))
         res++;
  }

  return num - res;
}

void readIn(){
    int i,t;
    int a,b;
    memset(tab, 0, sizeof(tab));
    cin>>num>>t;
    while(t--){
        cin>>a>>b;
        a --, b --;
        tab[a][b] = 1;
    }
}

int main(){
    int tstcase;

    cin>>tstcase;
    while(tstcase --){
        readIn();
        cout<<get_match()<<endl;
    }

	return 0;
}
