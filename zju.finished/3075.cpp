#include<iostream>
#include<set>
using namespace std;

enum {
    SIZ = 100004,
};
long long MAX = 1llu<<50;
long long N, P, Q, F;
long long pri[SIZ];
long long sum[SIZ];

int readIn(){
    if (scanf("%lld%lld%lld%lld", &N, &P, &Q, &F) < 0)
        return 0;
    ++P, ++Q;
    int i;
    for (i=0; i<N; ++i){
        scanf("%lld", &pri[i]);
    }
    sum[N] = 0;
    long long m = MAX,v;
    for (i=N-1; i>=0; --i){
        v = pri[i] + F;
        m = min(m, v);
        sum[i] = m;
        m += F;
    }
    return 1;
}

void fun(){
    int day, i;
    multiset<long long> tab;
    multiset<long long>::iterator it;
    for (i=P; i<=Q; ++i){
        tab.insert(pri[i]);
    }
    long long m=MAX, v;
    int q;
    for (day=0, q=Q+1; day+P < N; ++day, ++q){
        v = *tab.begin();
        if (q < N){
            v = min(v, sum[q]);
        }
        v += pri[day];
        m = min(m, v);
        
        it = tab.find(pri[day+P]);
        if (it!=tab.end())
            tab.erase(it);
        if (q < N){
            tab.insert(pri[q]);
        }
    }
    printf("%lld\n", m);
}

int main(){

    while(readIn() > 0){
        fun();
    }
}

