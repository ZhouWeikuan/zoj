#include<cstdio>
#include<cstring>
#include<set>

using namespace std;
enum {
    SZ = 502,
};
struct Node {
    int pos;
    int ptr[SZ];
};

Node tab[SZ];
int mat[SZ];
int vis[SZ];
int num;

int dfs(int p){
  int i,t;
  for(int it = 0; it<tab[p].pos; it++){
      i = tab[p].ptr[it];
      if(vis[i])
          continue;
      vis[i] = 1;
      t = mat[i];
      mat[i] = p;
      if(t ==-1 || dfs(t))
          return 1;
      mat[i] = t;
  }
  return 0;
}
void readIn(){
    int i,t;
    int a,b;
    memset(tab, 0, sizeof(tab));
    for(i=0; i<num; i++){
        tab[i].pos = 0;
        scanf("%d: (%d)", &a, &t);
        while(t--){
            scanf("%d", &b);
            tab[a].ptr[tab[a].pos++] = b;
        }
    }
}

int get_match(){
  int i,res=0;
  memset(mat,-1,sizeof(mat));
  for(i=0;i< num;i++){
      memset(vis,0,sizeof(vis));
      if(dfs(i))
         res++;
  }

  res /= 2;
  return num - res;
}

int main(){

    while(scanf("%d", &num) > 0){
        readIn();
        printf("%d\n", get_match());
    }

	return 0;
}
