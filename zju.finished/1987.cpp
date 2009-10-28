#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

enum {
    SIZ = 38,
};

int N, K;
vector<int> m[SIZ];
struct a_greater_v {
    bool operator ()(const vector<int> &a, const vector<int> &b) const{
        if (a.empty()) return false;
        if (b.empty()) return true;
        return a.size() >= b.size();
    }
}greater_v;

void merge(vector<int> &out, vector<int> &a, vector<int> &b){
    vector<int>::iterator ia = a.begin();
    vector<int>::iterator ib = b.begin();
    while(ia!=a.end() && ib!=b.end()){
        if (*ia == *ib){
            out.push_back(*ia);
            ++ia, ++ib;
        } else if (*ia < *ib){
            ++ia;
        } else {
            ++ib;
        }
    }
}

void dfs(int d, int s, vector<int> &v){
    if (v.empty() || v.size() <= d){
        if (!v.empty() && K < v.size()) K = v.size();
        return ;
    }
    for ( ; s<SIZ; ++s){
        if (m[s].empty() || m[s].size() <= K) continue;
        vector<int> vt;
        merge(vt, m[s], v);
        dfs(d+1, s+1, vt);
    }
}

void fun(){
    K = 1;
    for (int i=0; i<SIZ; ++i){
        if (m[i].empty() || m[i].size() <= K) continue;
        dfs(1, i+1, m[i]);
    }
    printf("%d\n", K);
}

void readIn(){
    for (int i=0; i<SIZ; ++i)
        m[i].clear();
    scanf("%d", &N);
    int a, b;
    for (int i=0; i<N; ++i){
        scanf("%d%d", &a, &b);
        m[a].push_back(b);
    }
    for (int i=0; i<SIZ; ++i)
        if (!m[i].empty())
            sort(m[i].begin(), m[i].end());
    sort(m, m+SIZ, greater_v);
}

int main(){
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        fun();
    }

    return 0;
}

