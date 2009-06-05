#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};
int tstnum;
int N,M;
int t[2][SIZ];
int v[2][SIZ];

int inline getVal(int n){
    return t[0][n]*v[0][n] + t[1][n]*v[1][n];
}

void init(){
    int l = M, j;
    for(int i=0; i<N;i++){
        j = l / (N-i);
        v[0][i] = v[1][i] = j;
        l -= j;
    }
}

int findmax() {
    int r=0,s=getVal(0), j;
    for(int i=1; i<N; i++){
        j = getVal(i);
        if( s< j){
            r = i;
            s = j;
        }
    }
    return r;
}

bool adjust(int n, int d){
    if(v[d][n]<=0)
        return false;
    int s = getVal(n), p=-1, dif,pre,cur;
    for(int i=0; i<N; i++){
        if(i==n) continue;
        pre = getVal(n) + getVal(i);
        --v[d][n];
        ++v[d][i];
        if(s>=getVal(n) && s>=getVal(i)){
            cur = getVal(n) + getVal(i);
            if(p==-1||pre-cur>=dif){
                p = i;
            }
        }
        ++v[d][n];
        --v[d][i];
    }
    if(p!=-1){
        --v[d][n];
        ++v[d][p];
        return true;
    }
    return false;
}

void fun(){
    int i;
    bool ch = true;
    init();

    while(ch){
        i = findmax();
        ch = adjust(i, 0);
        i = findmax();
        ch = adjust(i, 1) || ch;
    }
    i = findmax();
    printf("%d\n", t[0][i]*v[0][i] + t[1][i]*v[1][i]);
}

int readIn(){
    int i;
    scanf("%d%d ", &N,&M);
    for(i=0; i<N;i++){
        scanf("%d%d ", &t[0][i], &t[1][i]);
    }

    return N;
}

int main(){

    scanf("%d ", &tstnum);
    while(tstnum--){
        readIn();
        fun();
    }

    return 0;
}

