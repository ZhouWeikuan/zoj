#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
};
struct Point {
    int x, y;
    void readIn(){
        scanf("%d%d", &x,&y);
    }
    double dist(const Point&o)const{
        double r = (x-o.x)*(x-o.x);
        r += (y-o.y)*(y-o.y);
        r = sqrt(r);
        return r;
    }
};

const double eps = 1e-7;
Point bob[SIZ];
Point dog[SIZ];
bool tab[SIZ][SIZ];
bool vis[SIZ];
int mat[SIZ];
int RN, DM;

int dfs(int p){
  int i,t;
  for(i=0;i<RN;i++)
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
  for(i=0;i<DM;i++){
      memset(vis,0,sizeof(vis));
      if(dfs(i))
         res++;
  }

  return res;
}

void fun(){
    int s = get_match() + RN + 1;
    printf("%d\n", s);
    printf("%d %d", bob[0].x, bob[0].y);
    for (int i=1; i<=RN; ++i){
        if (mat[i-1] != -1) {
            printf(" %d %d", dog[mat[i-1]].x, dog[mat[i-1]].y);
        }
        printf(" %d %d", bob[i].x, bob[i].y);
    }
    printf("\n");
}

void readIn(){
    scanf("%d%d",&RN,&DM);
    int i;
    for (i=0; i<RN; ++i){
        bob[i].readIn();
    }
    for (i=0; i<DM; ++i){
        dog[i].readIn();
    }
    memset(tab, 0, sizeof(tab));
    double s, a, b;
    --RN;
    for (i=0; i<RN; ++i){
        s = bob[i].dist(bob[i+1]);
        for (int j=0; j<DM; ++j){
            a = bob[i].dist(dog[j]);
            b = bob[i+1].dist(dog[j]);
            if (s*2 + eps >= a + b){
                tab[i][j] = true;
            }
        }
    }
}

int main(){
    int tst;

    scanf("%d",&tst);
    while(tst-- > 0){
        readIn();
        fun();
        if (tst)
            printf("\n");
    }

    return 0;
}

