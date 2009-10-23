#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
enum {
    SIZ = 1001,
};

int N, M;
vector<short> ed[SIZ];
bool vis[SIZ];

int dfs(int p){
    vis[p] = true;
    int r = 1, t;
    for (int i=0; i<ed[p].size(); ++i){
        t = ed[p][i];
        if (vis[t]) continue;
        t = 1 + dfs(t);
        if (t > r){
            r = t;
        }
    }
    return r; 
}

int calc(int p){
    int a=0, b=0, t;
    memset(vis, false, sizeof(vis));
    vis[p] = true;
    for (int i=0; i<ed[p].size(); ++i){
        t = ed[p][i];
        if (vis[t]) continue;
        t = dfs(t);
        if (t > a){
            b = a; a = t;
        } else if (t > b){
            b = t;
        }
    }
    t = a + b + 1;
    return t;
}

void fun(){
    int i, m=0, t;
    for (i=0; i<N; ++i){
        t = calc(i);
        m = max(t, m);
    }
    if (m>7){
        printf("%d\n", m);
    } else {
        printf("Impossible\n");
    }
}

int readIn(){
    if (scanf("%d%d", &N, &M) < 0) return 0;
    int i, a, b;
    for (i=0; i<N; ++i)
        ed[i].clear();
    for (i=0; i<M; ++i){
        scanf("%d%d",&a,&b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

