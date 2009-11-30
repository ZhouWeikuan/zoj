#include<iostream>
#include<cstdio>
#include<ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
enum {
    SIZ = 10,
    OFF = 8,
};

typedef unsigned long long ull;
struct hf_str {
    int operator()(const ull s) const {
        return  s % 1313131;
    }
};
struct eq {
    bool operator()(const ull&a, const ull&b)const {
        return a == b;
    }
};

int N;
double gob;
double fac[SIZ];
hash_map<ull, bool, hf_str, eq> tab;
const double eps = 1e-7;

bool dfs(double f, ull key){
    if (f<=1.0 + eps) return false;
    hash_map<ull, bool, hf_str, eq>::iterator it = tab.find(key);
    if (it!=tab.end()){
        return it->second;
    }
    bool ret = false;
    for (int i=0; i<N; ++i){
        key += (1llu<<(i*OFF));
        if (!dfs(f * fac[i], key)){
            ret = true;
            break;
        }
        key -= (1llu<<(i*OFF));
    }
    tab.insert(make_pair(key, ret)); 
    return ret;
}

bool fun(){
    tab.clear();
    ull key = 0llu;
    return dfs(gob, key);
}

void readIn(){
    scanf("%lf%d", &gob, &N);
    for (int i=0; i<N; ++i){
        scanf("%lf", &fac[i]);
    }
    sort(fac, fac+N);
}

int main(){
    const char *ans[2] = {  "Mikael", "Nils" };
    int gn;
    scanf("%d", &gn);
    while(gn-- > 0){
        readIn();
        int t = fun();
        printf("%s\n", ans[t]);
    }

    return 0;
}

