#include<iostream>
using namespace std;

int m, n, num; // m for sell, n for buy
double sa, ba; 
double dat[10008];
int state;  // 0, unknown, -1->1 for buy, 1->-1 for sell
const double eps = 1e-7;

void fun(){
    int d;
    state = 0;
    sa = ba = 0;
    for(d=0; d<num; d++){
        scanf("%lf", &dat[d]);
        if(d < m-1){
            ba += dat[d];
        } else if(d==m-1){
            ba += dat[d];
            ba /= m;
        } else if(d >= m){
            ba *= m;
            ba += dat[d] - dat[d-m];
            ba /= m;
        }
        if(d < n-1){
            sa += dat[d];
        } else if(d==n-1){
            sa += dat[d];
            sa /= n;
        } else if(d>=n){
            sa *= n;
            sa += dat[d] - dat[d-n];
            sa /= n;
        }
        if(d >= n-1){
            if(sa +eps <  ba){
                if(state <= 0){
                    state = 1;
                    printf("BUY ON DAY %d\n", d+1);
                }
            } else if(sa > eps + ba){
                if(state >= 0){
                    state = -1;
                    printf("SELL ON DAY %d\n", d+1);
                }
            }
        }
    }
}

int main(){

    while(scanf("%d%d%d",&m,&n,&num)>0){
        fun();
    }
    return 0;
}

