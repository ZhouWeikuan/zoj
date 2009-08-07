#include<iostream>
using namespace std;
enum {
    SIZ = 32,
};

long long sum[SIZ+1][SIZ+1];
long long ans = 0;
long long N, L, P;

void init(){
    int i, j;
    sum[0][0] = 1;
    for (i=1; i<SIZ; ++i){
        sum[i][0] = 1;
        for (j=1; j<SIZ; ++j){
            sum[i][j] = sum[i-1][j] + sum[i-1][j-1];
        }
    }
    for (i=0; i<SIZ; ++i){
        for (j=1; j<SIZ; ++j){
            sum[i][j] += sum[i][j-1];
        }
    }
}

int findLevel(){
    int i;
    for (i=0; i<SIZ; ++i){
        if (P<sum[i][L]){
            return i;
        } else {
            P-=sum[i][L];
        }
    }
    return -1;
}

void fun(){
    if (P == 1){
        printf("0\n");
        return;
    }
    ans = 0;
    --P;
    while(L-->0 && P-->0){
        int f = findLevel();
        if (f >= 0)
            ans |= 1llu<<(f);
        else
            break;
    }

    printf("%lld\n", ans);
}

int main(){
    init();

    while(scanf("%lld%lld%lld", &N,&L,&P) > 0){
        fun();
    }

    return 0;
}

