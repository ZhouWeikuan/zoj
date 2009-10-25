#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
// Least Common Ancesstor
using namespace std;
enum {
    SIZ = 50004,
    LOG = 16,
};

struct Node {
    int par;
    int lvl;
    int dis;
};

int num;
Node tree[SIZ];
int P[SIZ][LOG];
multimap<int, unsigned> edge;
typedef pair<multimap<int, unsigned>::iterator, multimap<int, unsigned>::iterator> PIT;

void dfs(int cur){
    PIT pir = edge.equal_range(cur);
    for ( ;pir.first!=pir.second; ++pir.first){
        int d = pir.first->second >>16;
        int n = pir.first->second & 0x0ffff;
        if (tree[n].par != num) continue;
        tree[n].par = cur;
        tree[n].lvl = tree[cur].lvl + 1;
        tree[n].dis = tree[cur].dis + d;
        dfs(n);
    }
}

void build_tree(){
    int i;
    for (i=0; i<num; ++i){
        tree[i].par = num;
    }
    tree[0].par = -1;
    tree[0].lvl = 0;
    tree[0].dis = 0;
    dfs(0);
}

void preprocess(){
    int i, j;
    memset(P, -1, sizeof(P));
    for (i=0; i<num; ++i){
        P[i][0] = tree[i].par;
    }
    for (j=1; (1<<j)<num; ++j){
        for (i=0; i<num; ++i){
            if (P[i][j-1] < 0) continue;
            P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}

// return the common ancesstor of the passed parameters
int query(int p, int q){
    int lv;
    if (tree[p].lvl < tree[q].lvl){
        swap(p, q);
    }
    for (lv=1; (1<<lv)<=tree[p].lvl; ++lv)
        ;
    --lv;
    for (int i=lv; i>=0; --i){
        if (tree[p].lvl - (1<<i) >= tree[q].lvl)
            p = P[p][i];
    }
    // p and q has the same level;
    if (p == q) return p;
    for (int i=lv; i>=0; --i){
        if (P[p][i] !=-1 && P[p][i]!=P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }
    return tree[p].par;
}

int findParentAtLevel(int p, int lvl){
    int lv;
    for (lv=1; (1<<lv)<=tree[p].lvl; ++lv)
        ;
    --lv;
    for (int i=lv; i>=0; --i){
        if (tree[p].lvl - (1<<i) >= lvl)
            p = P[p][i];
    }
    return p;
}

int do_query(int x, int y, int z){
    int ret = 0, t;
    int p = query(x, y);
    ret = tree[x].dis - tree[p].dis + tree[y].dis - tree[p].dis;
    if (z == p) 
        return ret;
    int t1 = query(x, z);
    int t2 = query(y, z);
    if (tree[t1].lvl <= tree[t2].lvl)// use the nearer one
        t1 = t2;
    if (tree[t1].lvl <= tree[p].lvl){
        ret += tree[z].dis - tree[t1].dis;
        ret += tree[p].dis - tree[t1].dis;
    } else {
        ret += tree[z].dis - tree[t1].dis;
    }

    return ret;
}

int main(){
    int gn = 0;
    while (scanf("%d", &num) > 0) {
        if (gn++)
            printf("\n");
        int qn, x, y,z;
        edge.clear();
        for (qn=1; qn<num; ++qn){
            scanf("%d%d%d", &x, &y, &z);
            y |= (z<<16);
            edge.insert(make_pair(x, y));
        }
        build_tree();
        preprocess();
        scanf("%d", &qn);
        while(qn--){
            scanf("%d%d%d", &x, &y, &z);
            if (tree[x].lvl < tree[z].lvl)
                swap(x, z);
            if (tree[y].lvl < tree[z].lvl)
                swap(y, z);
            printf("%d\n", do_query(x, y, z));
        }
    }

    return 0;
}

