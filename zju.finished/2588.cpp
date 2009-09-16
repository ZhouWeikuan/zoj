#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
enum {
    SIZ = 10004,
};

int root, N, M;
int low[SIZ];
int dep[SIZ];
vector<int> bridge;
map<int, int> edge[SIZ]; // first -> another point,  second-> index,or -1

void dfs(int u,int fa,int depth) {
    dep[u] = low[u] = depth;
    int cnt=0;
    int tofa=0;// whether there are more than one edges between u and v
    int v;
    for(map<int,int>::iterator it=edge[u].begin();
            it!=edge[u].end(); ++it) {
        v=it->first;
        if(dep[v] == -1) { // not visited
            ++cnt;
            dfs(v,u,depth+1);
            low[u]=min(low[u],low[v]);
            // to get all cutting points
            /*
            if((u==root&&cnt>1)||(u!=root&&low[v]>=dep[u])){
                pnt.insert(u);
            }*/

            // to get all bridges
            if(low[v]>dep[u]) {
                int t = it->second;
                if (t)
                    bridge.push_back(t);
            }
        } else {
            if(v!=fa||tofa)
                low[u]=min(low[u],dep[v]);
            else
                tofa=1;
        }
    }
}

void fun(){
    dfs(1,-1,0);
    printf("%d\n", bridge.size());
    if (bridge.size()==0) return;
    sort(bridge.begin(), bridge.end());
    for (int i=0; i<bridge.size(); ++i){
        if (i) printf(" ");
        printf("%d", bridge[i]);
    }
    printf("\n");
}

void readIn(){
    memset(dep, -1, sizeof(dep));
    scanf("%d%d",&N,&M);
    bridge.clear();
    for (int i=1; i<=N; ++i){
        edge[i].clear();
    }
    int a, b;
    map<int,int>::iterator it;
    for (int i=1; i<=M; ++i){
        scanf("%d%d",&a,&b);
        it = edge[a].find(b);
        if (it!=edge[a].end()){
            it->second = 0;
        } else {
            edge[a].insert(make_pair(b,i));
        }

        it = edge[b].find(a);
        if (it!=edge[b].end()){
            it->second = 0;
        } else {
            edge[b].insert(make_pair(a,i));
        }
    }
}

int main() {
    root = 1;
    int tn;
    scanf("%d", &tn);
    while(tn--){
        readIn();
        fun();
        if (tn) printf("\n");
    }

    return 0;
}

