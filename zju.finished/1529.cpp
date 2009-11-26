#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
};

double getF1(int N){
    int x = N-1;
    double u = 0, d = 0, v=1;
    for (int i=1; i<=N; ++i){
        v *= x;
        u += v * i;
        d += v;
    }
    u /= d;
    return u;
}

double getF2(int N){
    int x = N-1;
    double u = 0, d = 0, v=1;
    for (int i=1; i<=N; ++i){
        v *= x;
        u += v * i;
        d += v;
        --x;
    }
    u /= d;
    return u;
}

double getF3(int N){
    --N;
    int x = N-1;
    double u = 0, d = 0, v=1;
    for (int i=2; i<=N; ++i){
        v *= x;
        u += v * (i + 1);
        d += v;
        --x;
    }
    u /= d;
    return u;
}

void fun(int N){
    printf("%.4lf %.4lf %.4lf\n", getF1(N), getF2(N), getF3(N));
}

int main(){
    int N;

    scanf("%d", &N);
    while(N > 0){
        fun(N);
        scanf("%d", &N);
    }

    return 0;
}

