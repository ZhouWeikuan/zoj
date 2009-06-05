#include<iostream>
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

void fun(){
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

