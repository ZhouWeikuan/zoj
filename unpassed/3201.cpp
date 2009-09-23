#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    unsigned char l, r, n;
};

struct Edge{
    unsigned short a, b;
};

int en, N, K;
Edge ed[SIZ];
vector<int> cld[SIZ];
unsigned val[SIZ];
unsigned tot[SIZ][SIZ];
Node tree[SIZ];

int createTree(int p){
    if (p < 0) return 0;
    int j = 0, t=-1;
    for (int i=0; i<en; ++i){
        if (ed[i].a == p || ed[i].b == p){
            int v = (ed[i].a==p?ed[i].b:ed[i].a);
            if (t == -1){
                t = v;
                tree[p].l = t;
            } else {
                tree[t].r = v;
                t = v;
            }
        } else {
            ed[j++] = ed[i];
        }
    }
    en = j;
    tree[p].n = 1;
    tree[p].n += createTree(tree[p].l);
    tree[p].n += createTree(tree[p].r);
    return tree[p].n;
}

void fun(){
    memset(tot, 0, sizeof(tot));
    memset(tree, -1, sizeof(tree));
    createTree(0);

}

int readIn(){
    if (scanf("%d%d", &N, &K) < 0)
        return 0;
    for (int i=0; i<N; ++i){
        scanf("%d", &val[i]);
    }
    for (int i=0; i<N-1; ++i){
        scanf("%hd%hd", &ed[i].a, &ed[i].b);
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

