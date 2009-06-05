#include<iostream>
using namespace std;
// Wrong Answer, there is something that I haven't taken it into consideration.
enum {
    SIZ = 6,
    LEN = 208,
};
const double MaxN = 1e15;
int N, L;
int low[SIZ], hi[SIZ];
double price[SIZ];
int color[SIZ];
double cost[2][LEN];

void init(double *v, int len){
    while(len--){
        *v++ = -1.00;
    }
}
double fun(){
    int i, j, d;
    double v;
    double *pre, *cur, *tmp;
    double ret = -1.00;
    do {
        pre = cost[0];
        cur = cost[1];
        init(pre, LEN);
        pre[0] = 0.0;
        for(i=0; i<N; i++){
            init(cur, LEN);
            for(j=LEN; j>=0; j--){
                if(pre[j] < 0.0) continue;
                for(d=low[i]; d<=hi[i]&&j+d<=L; d++){
                    v = pre[j] + d*d*price[color[i]];
                    if(cur[j+d] < 0.0 || cur[j+d] > v){
                        cur[j+d] = v;
                    }
                }
            }
            tmp = cur, cur = pre, pre = tmp;
        }
        if(pre[L] < 0) return ret;
        if(ret < 0 || ret > pre[L]){
            ret = pre[L];
        }
    } while(next_permutation(color, color+N));
    return ret;
}
int readIn(){
    if(scanf("%d%d",&N, &L)< 0)
        return 0;
    int i;
    for(i=0; i<N; i++){
        scanf("%lf",&price[i]);
        color[i] = i;
    }
    for(i=0; i<N; i++){
        scanf("%d%d",&low[i],&hi[i]);
    }
    return 1;
}
int main(){
    double v;
    while(readIn() > 0){
        v = fun();
        if( v < 0 ){
            printf("Impossible\n");
        } else {
            printf("%.3lf\n", v);
        }
    }
    return 0;
}

