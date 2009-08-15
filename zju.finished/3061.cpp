#include<iostream>
using namespace std;
enum {
    SIZ = 21,
};

unsigned low[SIZ];
unsigned hih[SIZ];
unsigned unit[SIZ];

void init(){
    unsigned i = 1;
    unsigned a = 2;
    unsigned b = 2;
    unsigned c = 3;
    low[0] = hih[0] = 0;
    unit[0] = 1;
    for (i=1; i<SIZ; ++i){
        low[i] = a;
        hih[i] = b;
        unit[i] = c;
        a *= 3;
        b *= 3;
        b += 2;
        c *= 3;
    }
}

unsigned num, mod, ans;
unsigned d[SIZ];

void dfs(unsigned v, int p){
    if (p < 0) {
        return;
    }
    v *= 3;
    // current
    if (v){
        unsigned a = v * unit[p] + low[p];
        unsigned b = v * unit[p] + hih[p];
        if (num >= a){
            if (num <= b){
                ans += (num-a+1)*v;
            } else {
                ans += (b-a+1)*v;
            }
            ans %= mod;
        }
    }
    // next 0
    dfs(v, p-1);
    v += 1;
    if (v){
        unsigned a = v * unit[p] + low[p];
        unsigned b = v * unit[p] + hih[p];
        if (num >= a){
            if (num <= b){
                ans += (num-a + 1)*v;
            } else {
                ans += (b - a + 1)*v;
            }
            ans %= mod;
        }
    }
    // next 1
    dfs(v, p-1);
}

void fun(){
    unsigned pos = 0, t=num;
    while(num){
        d[pos++] = num%3;
        num/=3;
    }
    num = t;
    ans = 0;
    dfs(0, pos-1);
    ans %= mod;
    printf("%u\n", ans);
}

int readIn(){
    if (scanf("%u%u", &num, &mod) < 0)
        return 0;
    return 1;
}

int main(){
    init();
    while(readIn() > 0){
        fun();
    }

    return 0;
}

