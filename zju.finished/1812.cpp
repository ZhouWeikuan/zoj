#include<iostream>
using namespace std;
enum {
    SIZ = 108,
};
int num;
int dat[SIZ];
int sav[6], st[6];
int kind, cnt, last, tie;

void output(int p){
    if(kind == -1){
        printf("%d ---- none\n", p);
        return;
    }
    printf("%d (%d):", p, kind);
    if(tie){
        printf(" tie\n");
        return ;
    }
    for(int i=0; i<cnt; i++){
        printf(" %d", sav[i]);
    }
    printf("\n");
}

void dfs(int v, int k, int c, int l, int s){
    if(c > 4) return;
    if(v == 0){
        if(k > kind || (k==kind&&c<cnt) 
                || (k==kind&&c==cnt && dat[l]>dat[last])){
            kind = k, cnt = c, last = l;
            memcpy(sav, st, sizeof(st));
            tie = 0;
        } else if(k==kind && c==cnt&&dat[l]==dat[last]){
            tie = 1;
        }
        return;
    }
    while(s<num){
        if(v>=dat[s]) {
            st[c] = dat[s];
            dfs(v-dat[s], k+(l!=s), c+1, s, s);
        }
        s++;
    }
}
void fun(){
    int t;
    scanf("%d", &t);
    while(t!=0){
        kind = -1; tie = 0;
        dfs(t, 0, 0, -1, 0);
        output(t);
        scanf("%d", &t);
    }
}

int readIn(){
    num = 0;
    if(scanf("%d", &dat[num]) < 0) return 0;
    while(dat[num]!=0){
        num++;
        scanf("%d", &dat[num]);
    }
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

