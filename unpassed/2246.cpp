#include<iostream>
#include<queue>
// TLE
using namespace std;
enum {
    SIZ = 20,
    LEN = 1<<20,
    LIM = 7 * 60,
};
int num;
unsigned short vis[SIZ];
unsigned short mat[SIZ][SIZ];
unsigned short best[LEN], out, cnt;

void dfs(int s, int p, int val){
    if(val>LIM || val >= best[s]) return;
    best[s] = val; 
    if(cnt > out) out=cnt;
    for(int np=0, ns=1; np<num; ++np, ns<<=1){
        if(ns&s) continue;
        ++cnt;
        dfs(s|ns, np, val+vis[np]+mat[p][np]);
        --cnt;
    }
}

void fun(){
    out = 0;
    memset(best, -1, sizeof(best));
    for(int i=0, s=1; i<num; i++, (s<<=1)){
        cnt = 1;
        dfs(s, i, vis[i]);
    }
    printf("%d\n", out);
}

int readIn(){
    scanf("%d", &num);
    int i,j;
    for(i=0; i<num; i++){
        scanf("%d", &vis[i]);
    }
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    return num;
}
int main(){

    while(readIn()>0){
        fun();
    }
    return 0;
}

