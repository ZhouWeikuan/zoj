#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
enum {
    SIZ = 804,
};

int low[SIZ];
int dep[SIZ];
map<unsigned, int> cost;
vector<int> edge[SIZ];
unsigned bri, pos;
int N, M, A, B;

unsigned makeKey(int a, int b){
    if (a > b){
        swap(a, b);
    }
    a = (a<<16)+b;
    return a;
}

void updateBridge(unsigned k){
    if (pos == 0){
        bri = k; pos = 1;
        return;
    }
    map<unsigned, int>::iterator a, b;
    a = cost.find(k);
    b = cost.find(bri);
    if (a==cost.end() || b==cost.end()) return;
    if (a->second < b->second){
        bri = k; pos = 1;
    } else if (a->second == b->second){
        pos = 2;
    }
}

int dfs(int u,int fa,int depth) {
    dep[u] = low[u] = depth;
    int cnt=0;
    int tofa=0;// whether there are more than one edges between u and v
    int i,v;
    for(i=0;i<edge[u].size();i++) {
        v=edge[u][i];
        if(dep[v] == -1) { // not visited
            cnt++;
            dfs(v,u,depth+1);
            low[u]=min(low[u],low[v]);

            // to get all bridges
            if(low[v]>dep[u]) {
                if (dep[B] > dep[u]){
                    updateBridge(makeKey(u, v));
                }
            }
        } else {
            if(v!=fa||tofa)
                low[u]=min(low[u],dep[v]);
            else
                tofa=1;
        }
    }
    return 0;
}

int readIn(){
    scanf("%d%d%d%d",&N,&M,&A,&B);
    if (N == 0) return 0;
    --A, --B;
    int i,a,b,c;
    cost.clear();
    for (i=0; i<N; ++i)
        edge[i].clear();
    for (i=0; i<M; ++i){
        scanf("%d%d%d", &a,&b,&c);
        --a,--b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        a = makeKey(a,b);
        cost.insert(make_pair(a, c));
    }

    return 1;
}

int main()
{
    const char *ans[] = {
        "AMBIGUOUS", "UNIQUE"
    };
    while(readIn() > 0){
        bri = -1, pos = 0;
        memset(dep, -1, sizeof(dep));
        dfs(A,-1,0);
        printf("%s\n", ans[pos==1]);
    }
    return 0;
}

