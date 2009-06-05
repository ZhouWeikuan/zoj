#include<iostream>
#include<cmath>

using namespace std;
enum {
    SZ = 102,
};
const double eps= 1e-7;
int N,M,S,V;
struct Point {
    double x;
    double y;
};

Point gopher[SZ];
Point hole[SZ];

int tab[SZ][SZ];
int mat[SZ];
int vis[SZ];
int dfs(int p){
  int i,t;
  for(i=0;i< N;i++)
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
double getDis(Point &a, Point &b){
    double x = a.x - b.x;
    x *= x;
    x += (a.y-b.y)*(a.y-b.y);
    return sqrt(x);
}

void readIn(){
    int i,j;
    double t;
    double dis= S*V;
    memset(tab, 0, sizeof(tab));
    for(i=0;i<N;i++){
        cin>>gopher[i].x>>gopher[i].y;
    }
    for(i=0;i<M;i++){
        cin>>hole[i].x>>hole[i].y;
    }
    for(i =0;i<N;i++){
        for(j=0;j<M;j++){
            t  = getDis(gopher[i],hole[j]);
            if(t<= dis + eps){
                tab[i][j] = 1;
            }
        }
    }
}

int get_match(){
  int i,res=0;
  memset(mat,-1,sizeof(mat));
  for(i=0;i< M;i++){
      memset(vis,0,sizeof(vis));
      if(dfs(i))
         res++;
  }

  return N - res;
}

int main(){

    while(cin>>N>>M>>S>>V){
        readIn();
        cout<<get_match()<<endl;
    }

	return 0;
}
