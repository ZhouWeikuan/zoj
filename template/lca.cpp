#include<iostream>
#include<cstdio>
#include<cstring>
// Least Common Ancesstor
using namespace std;
enum {
    SIZ = 128,
    LOG = 8,
};

struct Node {
    int par;
    int lvl;
    int dis;
};

int num;
Node tree[SIZ];
int P[SIZ][LOG];

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

int main(){
    num = 13;
    tree[0].lvl = 0;
    int a, b;
    for (int i=0; i<num; ++i){
        scanf("%d%d", &a, &b);
        tree[i].par = b;
        if (b >= 0)
            tree[i].lvl = tree[b].lvl + 1;
    }
    preprocess();
    while(scanf("%d%d", &a, &b)>0){
        a = query(a, b);
        printf("%d\n", a);
    }
    return 0;
}

