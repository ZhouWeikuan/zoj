#include<iostream>
#include<cstdio>
using namespace std;
enum {
    SIZ = 104,
};
int N, M;
unsigned way[SIZ][SIZ];
unsigned mat[SIZ][SIZ];
unsigned cnt[SIZ];
unsigned num[SIZ];
unsigned fac[SIZ];
void init(){
    for (int i=0; i<SIZ; ++i){
        way[0][i] = 1;
        if (i){
            fac[i] = fac[i-1];
            fac[i] *= i;
        } else {
            fac[i] = 1;
        }
    }
    for (int i=1; i<SIZ; ++i){
        way[i][0] = 1;
        for (int j=1; j<SIZ; ++j){
            way[i][j] = 0;
            for (int k=0; k<=i; ++k){
                way[i][j] += way[k][j-1];
            }
        }
    }
}

void fun(){
    cnt[1] = 1;
    num[1] = 0;
    for (int i=2; i<=M; ++i){
        cnt[i] = cnt[i-1] * fac[mat[i][i-1]]; 
        num[i] = num[i-1] + mat[i][i-1];
        for (int j=i-2; j>0; --j){
            if (mat[i][j]==0) continue;
            cnt[i] *= fac[mat[i][j]] * way[num[i]-num[j]][mat[i][j]];
            num[i] += mat[i][j];
        }
    }
    printf("%u\n", cnt[M]);
}

void readIn(){
    memset(mat, 0, sizeof(mat));
    int a, b;
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; ++i){
        scanf("%d%d",&a,&b);
        ++mat[b][a];
    }
}

int main(){
    init();
    int gn;
    scanf("%d", &gn);
    while(gn-- > 0){
        readIn();
        fun();
    }

    return 0;
}

