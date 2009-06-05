#include<iostream>
#include<cmath>
#include<queue>
#include<map>
// 本题相当于求数x的因子个数，可以将n分解，再匹配若干素数。
// 注意重复匹配情况，即p匹配后，应该将它p^x方再加进去
using namespace std;
enum {
    SIZ = 10001,
};
int fac[SIZ] = {1,1,2,3};
int pl[1248] = {2,3}, pn=2;

void init(){
    bool p=true;
    for(int n=4; n<SIZ; n+=2)
        fac[n] = 2;
    for(int n=5; n<SIZ; n+=2){
        p = true;
        for(int i=0; i<pn&&pl[i]*pl[i]<=n; ++i){
            if(n%pl[i] == 0){
                p = false;
                fac[n] = pl[i];
                break;
            }
        }
        if(p){
            fac[n] = n;
            pl[pn++] = n;
        }
    }
//    printf("%d\n", pn);
}

void output(map<int, int> &m){
    bool f = true;
    for(map<int, int>::iterator it=m.begin();
            it!=m.end(); ++it){
        if(!f){
            printf(" * ");
        } else {
            f = false;
        }
        printf("%d^%d", it->first, it->second - 1);
    }
    printf("\n");
}

void fun(int n){ // what if n==0? n==1?
    if(n==0){
        printf("0\n"); return;
    }else if(n== 1){
        printf("2^0\n");
        return;
    }
    priority_queue<int, vector<int>, greater<int> > q; // prime
    priority_queue<int> f; // factor
    map<int, int> tab;
    int p = n, v;
    while(p > 1){
        f.push(fac[p]);
        p /= fac[p];
    }
    for(p=0; p<pn&&pl[p]<100; p++){
        q.push(pl[p]);
    }
    while(!f.empty()){
        p = f.top(); f.pop();
        v = q.top(); q.pop();
        if(0==tab[fac[v]]){
            tab[fac[v]] = p;
        } else {
            tab[fac[v]] *= p;
        }
        if(log((double)v)*p>=3.0){
            continue;
        }
        v = (int)pow((double)v, p);
        if(v < 100){
            q.push(v);
        }
    }
    output(tab);
}

int main(){
    init();
    int n;
    while(scanf("%d",&n) > 0){
        fun(n);
    }
    return 0;
}

