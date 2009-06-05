#include<iostream>
// DFS + 剪枝，剪枝条件为奇偶性和数量
using namespace std;
enum {
    SIZ = 7,
};
int tab[SIZ][SIZ];
int N,M,T;
int tx,ty,sx,sy, occupy;

int readIn(){
    if(scanf("%d%d%d",&N,&M,&T) <= 0 || N + M + T ==0)
        return 0;
    char ch;
    occupy = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf(" %c", &ch);
            tab[i][j] = 0;
            switch(ch){
            case 'X':
                tab[i][j] = 2;
                occupy++;
                break;
            case 'S':
                sx = i; sy = j;
                break;
            case 'D':
                tx = i, ty = j;
                break;
            }
        }
    }
    return 1;
}
int test(int x, int y, int step){
    if(step == T){
        return (x == tx && y == ty);
    }
    tab[x][y] = 1;
    if(x>0 && tab[x-1][y]==0 && test(x-1,y,step+1))
        return 1;
    if(x<N-1&&tab[x+1][y]==0 && test(x+1,y,step+1))
        return 1;
    if(y >0&&tab[x][y-1]==0 && test(x,y-1,step+1))
        return 1;
    if(y<M-1&&tab[x][y+1]==0&&test(x,y+1,step+1))
        return 1;
    return tab[x][y] = 0;
}
int fun(){
    int step = tx - sx + ty - sy + T;
    if(step % 2 == 1 || N*M - occupy <= T)
        return 0;
    return test(sx, sy, 0);
}
int main(){
    const char *ans[2] = {"NO", "YES"};
    while(readIn() > 0){
        printf("%s\n", ans[fun()]);
    }
    return 0;
}

