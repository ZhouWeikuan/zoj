#include<iostream>
using namespace std;
// too much time, need optimising.
enum {
    SIZ = 502,
};
int num, vex;
int mat[SIZ][SIZ];
unsigned val[SIZ];
bool mark[SIZ];
int st[SIZ], top;

int update(int p){
    unsigned v = 0;
    int s = -1;
    for(int i=0; i<num; i++){
        if(mark[i] || st[i]) continue;
        val[i] += mat[p][i];
        if(val[i] > v){
            v = val[i];
            s = i;
        }
    }
    return s;
}
unsigned min_cut(int &s, int &t){
    unsigned v = 0;
    int i;
    top = 1;
    memset(st, 0, sizeof(st));
    memset(val, 0, sizeof(val));
    for(i=0; i<num && mark[i]; i++)
        ;
    st[i] = top++;
    i = update(i);
    while(i!=-1){
        v = val[i];
        st[i] = top++;
        i = update(i);
    }
    for(i=0; i<num; i++){
        if(mark[i]) continue;
        if(st[i] == vex-1){
            s = i;
        } else if(st[i] == vex){
            t = i;
        }
    }
    return v;
}
void contract(int s, int t){
    mark[t] = true;
    for(int i=0; i<num; i++){
        if(mark[i]) continue;
        mat[s][i] += mat[t][i];
        mat[i][s] = mat[s][i];
    }
    mat[s][t] = mat[t][s] = 0;
}
int fun(){
    unsigned ret = -1, t;
    int a, b;
    vex = num;
    while(vex > 1){
        t = min_cut(a, b);
        ret = min(ret, t);
        contract(a, b);
        vex--;
    }
    return ret;
}
int readIn(){
    int M, a, b, c;
    if(scanf("%d%d",&num,&M) < 0) return 0;
    memset(mat,0,sizeof(mat));
    memset(val,0,sizeof(val));
    memset(mark, false, sizeof(mark));
    while(M--){
        scanf("%d%d%d", &a, &b, &c);
        mat[a][b] += c;
        mat[b][a] = mat[a][b];
    }
    return 1;
}
int main(){
    while(readIn()>0){
        printf("%d\n", fun());
    }
    return 0;
}

