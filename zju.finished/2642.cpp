#include<iostream>
using namespace std;
enum {
    SIZ = 100004,
};
typedef long long u64_t;
// store in [0, num-1]
// 相当于求矩形的面积
int val[SIZ];
int l[SIZ];
int r[SIZ];
u64_t sum[SIZ];
int num;

void readIn(){
    int i,j,t;
    for(i=0;i<num;i++){
        scanf("%d",&val[i]);
        if(i){
            sum[i] = sum[i-1] + val[i];
        } else {
            sum[i] = val[i];
        }
    }
    l[0] = 0;
    for(i=1;i<num;i++){
        t=i-1;
        while(t>=0&&val[t]>=val[i]){
            t = l[t] - 1;
        }
        l[i] = t + 1;
    }
    r[num-1] = num-1;
    for(i=num-2;i>=0;i--){
        t = i + 1;
        while(t<num&&val[t]>=val[i]){
            t = r[t] + 1;
        }
        r[i] = t - 1;
    }
}
void fun(){
    u64_t v = -1, t;
    int cur;
    for(int i=0;i<num;i++){
        t = sum[r[i]] - sum[l[i]] + val[l[i]];
        t *= val[i];
        if(t > v){
            v = t;
            cur = i;
        }
    }
    printf("%lld\n", v);
    printf("%d %d\n", l[cur] + 1, r[cur] + 1);
}
int main(){
    while(scanf("%d",&num) > 0){
        readIn();
        fun();
    }
    return 0;
}

