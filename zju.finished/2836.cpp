#include<iostream>
using namespace std;
// 一开始求最小公倍数求错了，WA一次，改完就好了
enum {
    SIZ = 12,
    LIM = 3000,
};
int d[SIZ];
int cnt[LIM];
int num, lim;

int gcd(int a, int b){
    int t;
    if(a < b){
        t = a; a=b; b=t;
    }
    while(b > 0){
        t = a % b;
        a = b; 
        b = t;
    }
    return a;
}
int lcm(int a, int b){
    int t = gcd(a,b);
    int r = a / t;
    a = b / t;
    r *= a;
    r *= t;
    return r;
}

int fun(){
    if(d[0] == 1){
        return lim;
    }
    int l = 1, i, sum = 0;
    for(i=0;i<num;i++){
        l = lcm(l, d[i]);
    }
    cnt[0] = 0;
    bool flag = false;
    for(i=1;i<=l;i++){
        flag = false;
        for(int j=0;j<num;j++){
            if(i % d[j] == 0){
                flag = true;
                break;
            }
        }
        cnt[i] = cnt[i-1];
        if(flag){
            cnt[i]++;
        }
    }
    i = lim % l;
    sum = cnt[i];
    i = lim / l;
    sum += i * cnt[l];
    return sum;
}

int main(){
   
    while(scanf("%d%d",&num,&lim) > 0){
        for(int i=0;i<num;i++){
            scanf("%d",&d[i]);
        }
        sort(d, d + num);
        printf("%d\n",fun());
    }
    return 0;
}

