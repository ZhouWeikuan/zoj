#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
enum {
    SZ = 804,
};
struct Node {
    int p, v;
};
bool cmp_p(const Node&a, const Node&b){
    return a.p < b.p;
}
bool cmp_v(const Node&a, const Node&b){
    return a.v >= b.v;
}

int num;
Node tree[SZ];
vector<int> tab[SZ];
int mat[SZ];
int vis[SZ];

int dfs(int p){
    int i, t, g;
    for(i=0;i<tab[p].size();++i) {
        g = tab[p][i];
        if(!vis[g]){
            vis[g] = 1;
            t = mat[g];
            mat[g] = p;
            if(t==-1)
                return g;
            int v = dfs(t);
            if (v >= 0) {
                return v;
            }
            mat[g] = t;
        }
    }
    return -1;
}

void fun(){
    sort(tree, tree+num, cmp_v);
    memset(mat, -1, sizeof(mat));
    for (int i=0; i<num; ++i){
        memset(vis, 0, sizeof(vis));
        int t = dfs(tree[i].p);
        if (t == -1){
            tree[i].v = 0;
        } else {
            tree[i].v = t - num + 1;
        }
    }

    sort(tree, tree+num, cmp_p);
    for (int i=0; i<num; ++i){
        if (i) printf(" ");
        printf("%d", tree[i].v);
    }
    printf("\n");
}

void readIn(){
    int i,t;
    int a,b;
    for (i=0; i<SZ; ++i)
        tab[i].clear();
    cin>>num;
    for (i=0; i<num; ++i){
        tree[i].p = i;
        scanf("%d ", &tree[i].v);
    }
    for (i=0; i<num; ++i){
        scanf("%d ", &t);
        while(t--){
            scanf("%d ", &a);
            a += num - 1;
            tab[i].push_back(a);
            tab[a].push_back(i);
        }
    }
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
        if (tst){
            printf("\n");
        }
    }

    return 0;
}

