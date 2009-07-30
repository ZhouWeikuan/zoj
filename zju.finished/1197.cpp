#include<iostream>
#include<cstring>
#include<cstdlib>
// perfect match for biparty
using namespace std;
enum {
    SIZ = 108,
};
struct Rect{
    int lx, ly, hx, hy;
    bool in(int x, int y){
        return x>min(lx,hx)&&x<max(lx,hx) && y>min(ly, hy) && y<max(ly, hy);
    }
};
int num;
Rect r[SIZ];
int tab[SIZ][SIZ];
int mat[SIZ];
int vis[SIZ];

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

void fun(){
    get_match();
    int t;
    bool ok = false;
    for (int i=0; i<num; ++i){
        t = mat[i];
        if (t == -1) continue;
        memset(vis, 0, sizeof(vis));
        mat[i] = -1;
        tab[i][t] = 0;
        if (!dfs(t)){
            if (ok) printf(" ");
            ok = true;
            mat[i] = t;
            printf("(%c,%d)", i+'A', t+1);
        }
        tab[i][t] = 1;
    }
    if (!ok){
        printf("none");
    }
    printf("\n");
}

int readIn(){
    scanf("%d", &num);
    int i,j;
    int x, y;
    for(i=0; i<num; i++){
        scanf("%d%d%d%d", &r[i].lx, &r[i].hx, &r[i].ly, &r[i].hy);
    }
    memset(tab, 0, sizeof(tab));
    for(i=0; i<num ;i++){
        scanf("%d%d", &x, &y);
        for(j=0;j<num;j++){
            tab[j][i] = r[j].in(x, y);
        }
    }
    return num;
}
int main(){
    int tst = 0;
    while( readIn() > 0){
        printf("Heap %d\n", ++tst);
        fun();
        printf("\n");
    }
    return 0;
}

