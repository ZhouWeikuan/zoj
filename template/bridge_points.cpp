#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
enum {
    SIZ = 104,
};

int root;
int low[SIZ];
int dep[SIZ];
set<int> pnt;
vector<pair<int, int> > bridge;
vector<int> edge[SIZ];

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
            // to get all cutting points
            if((u==root&&cnt>1)||(u!=root&&low[v]>=dep[u])){
                pnt.insert(u);
            }

            // to get all bridges
            if(low[v]>dep[u]) {
                pair<int, int> p;
                p.first = u, p.second = v;
                bridge.push_back(p);
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

int main()
{
    pnt.clear(); bridge.clear();
    memset(dep, -1, sizeof(dep));
    edge[0].push_back(1);
    edge[1].push_back(2);
    edge[1].push_back(3);
    dfs(0,-1,0);
    printf("============ points ================\n");
    for (set<int>::iterator it=pnt.begin(); it!=pnt.end(); ++it){
        printf("%d\n", *it);
    }
    printf("============ bridges ===============\n");
    for (int i=0; i<bridge.size(); ++i){
        printf("%d -> %d\n", bridge[i].first, bridge[i].second);
    }
    return 0;
}

