#include<iostream>
using namespace std;
enum {
    SIZ = 7,
};
int T;
int cnt[SIZ];
int pv[SIZ];

int calc(int v){
    int ret = 1;
    for(int i=0; i<T; i++){
        ret *= v;
    }
    return ret;
}
void init(){
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<SIZ; i++){
        pv[i] = calc(i-3);
    }
}
void fun(){
    int sum = 0;
    for(int i=0; i<SIZ; i++){
        if(pv[i] <= 0) continue;
        sum += cnt[i] * pv[i];
    }
    printf("%d\n", sum);
}

int readIn(){
    int n, v;
    if(scanf("%d", &n)<0) return 0;
    scanf("%d", &T);
    init();
    for(;n>0; n--){
        scanf("%d", &v);
        cnt[v+3]++;
    }
    return 1;
}
int main(){

    while( readIn() > 0){
        fun();
    }
    return 0;
}

