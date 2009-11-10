#include<iostream>

// bipart, need you to translate, hard to image.
using namespace std;
enum {
    SZ = 102,
};

int tab[SZ][SZ];
int mat[SZ];
int vis[SZ];
int n,m,k;
int dfs(int p){
  int i,t;
  for(i=1;i<= n;i++)
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

int readIn(){
    int i,t;
    int a,b;
    scanf("%d", &n);
    if(n ==0)
        return 0;
    memset(tab, 0, sizeof(tab));
    scanf("%d%d", &m,&k);
    for(i=0;i<k;i++){
        scanf("%d%d%d ", &t, &a,&b);
        tab[a][b] = 1;
    }
    return 1;
}

int get_match(){
  int i,res=0;
  memset(mat,-1,sizeof(mat));
  for(i=1;i<= m;i++){
      memset(vis,0,sizeof(vis));
      if(dfs(i))
         res++;
  }

  return res;
}

int main(){

    while(readIn()){
        printf("%d\n", get_match());
    }

	return 0;
}
