#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
struct Node{
    int a, b, c;
};
int N, C, H;
Node way[SIZ];
int mat[12][12];
bool mark[12];

int dfs(int city, int color, int deep, int cnt){
    if(deep == H) 
        return cnt;
    int ret = -1, t, v, nc;
    for(int i=0; i<N; i++){
        v = mat[city][i];
        if(v == -1 || mark[v] == true) continue;
        mark[v] = true;
        t = dfs(i, way[v].c, deep+1, cnt + (way[v].c!=color));
        if(ret == -1 || ret > t){
            ret = t;
        }
        mark[v] = false;
    }
    return ret;
}
int fun(){
    memset(mark, false, sizeof(mark));
    int i, t, ret = -1;
    for(i=0; i<N; i++){
        t = dfs(i, -1, 0, 0);
        if(ret==-1 || (t!=-1 && ret > t)){
            ret = t;
        }
    }
    return ret;
}
int readIn(){
    scanf("%d%d%d", &N, &C, &H);
    if(N + C + H == 0) return 0;
    memset(mat, -1, sizeof(mat));
    int i;
    for(i=0; i<H; i++){
        scanf("%d%d%d", &way[i].a, &way[i].b, &way[i].c);
        mat[way[i].a][way[i].b] = mat[way[i].b][way[i].a] = i;
    }
    return 1;
}
int main(){
    int t;

    while(readIn() > 0){
        t = fun();
        if(t < 0){
            printf("No\n");
        } else {
            t--;
            printf("%d\n", t);
        }
    }
    return 0;
}

