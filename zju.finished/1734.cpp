#include<iostream>
#include<cstring>
#include<set>
using namespace std;
enum {
    SIZ = 104,
};

int ed[SIZ][SIZ];
int need[SIZ];
int has[SIZ];
int pro[SIZ];
int flow[SIZ];
int pre[SIZ];
int num, nPow, nCon;
struct cmp {
    bool operator()(const int&a, const int&b)const{
        if (flow[a]!=flow[b])
            return flow[a] > flow[b];
        return a < b;
    }
};

int findPath(int s){
    memset(pre, -1, sizeof(pre));
    memset(flow, 0, sizeof(flow));
    set<int, cmp> tab;
    flow[s] = pro[s];
    tab.insert(s);
    int d;
    while(!tab.empty()){
        s = *tab.begin(); tab.erase(tab.begin());
        if (need[s])
            return s;
        for (int i=0; i<num; ++i){
            if (s == i || ed[s][i] == 0) continue;
            d = min(ed[s][i], flow[s]);
            if (flow[i] < d){
                if (flow[i] != 0){
                    tab.erase(i);
                }
                flow[i] = d;
                tab.insert(i);
                pre[i] = s;
            }
        }
    }
    return -1;
}

void fill(int s){
    while(pro[s] > 0){
        int e = findPath(s);
        if (e < 0) return;
        int d = min(flow[e], need[e]);
        pro[s] -= d;
        need[e] -= d;
        has[e] += d;
        while(pre[e] >= 0){
            ed[pre[e]][e] -= d;
            ed[e][pre[e]] += d;
            e = pre[e];
        }
    }
}

void fun(){
    int i;
    for (i=0; i<num; ++i){
        if (pro[i] == 0) continue;
        fill(i);
    }
    int sum = 0;
    for (i=0; i<num; ++i){
        sum += has[i];
    }
    printf("%d\n", sum);
}

int readIn(){
    if (scanf("%d %d %d",&num, &nPow, &nCon)<0) return 0;
    memset(need, 0, sizeof(need));
    memset(ed, 0, sizeof(ed));
    memset(has, 0, sizeof(has));
    memset(pro, 0, sizeof(pro));
    int m;
    scanf("%d ", &m);
    int a, b, c;
    char o;
    while(m--){
        scanf(" %c %d %c %d %c %d ", &o, &a, &o, &b, &o, &c);
        ed[a][b] = c;
    }
    for (m=0; m<nPow; ++m){
        scanf(" %c %d %c %d ", &o, &a, &o, &b);
        pro[a] = b;
    }
    for (m=0; m<nCon; ++m){
        scanf(" %c %d %c %d ", &o, &a, &o, &b);
        need[a] = b;
    }
    return 1;
}

int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

