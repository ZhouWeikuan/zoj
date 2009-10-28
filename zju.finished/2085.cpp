#include<iostream>
#include<cstdio>
using namespace std;
enum {
    SIZ = 104,
};
int N;
double eps = 1e-8;
double p;
double tab[2][SIZ];

void fun(){
    double *pre, *cur, t;
    memset(tab[0], 0, sizeof(tab[0]));
    pre = tab[0], cur=tab[1];
    pre[N] = 1.0;
    N *= 2;
    while(1 - pre[0] - pre[N] >= eps){
        memset(cur, 0, sizeof(tab[0]));
        cur[0] = pre[0], cur[N] = pre[N];
        for (int i=1; i<N; ++i){
            t = pre[i] * p;
            cur[i+1] += t;
            cur[i-1] += pre[i] - t;
        }
        swap(pre, cur);
    }
    printf("%.06lf\n", pre[N]);
}

int main(){

    while(scanf("%d%lf", &N, &p) > 0){
        fun();
    }

    return 0;
}

