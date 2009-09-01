#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
enum {
    SIZ = 400,
};
struct Node {
    int p, l, r, v;
    int a, b;
};

int num;
Node tree[SIZ];
int dat[SIZ];
bool first;

void postOrder(int r){
    if (tree[r].l >= 0){
        postOrder(tree[r].l);
    }
    if (tree[r].r >=0 ){
        postOrder(tree[r].r);
    }
    if (!first){
        printf(" ");
    }
    printf("%d", tree[r].v);
    first = false;
}

void fun(){
    int pos = 0, lvl, v;
    char ch;
    deque<int> tab[2], *va, *vb, *vt;
    va = &tab[0];
    vb = &tab[1];
    memset(tree, -1, sizeof(tree));
    tree[0].a = 0, tree[0].b = num;
    va->push_back(pos++);
    scanf("%d", &lvl);
    while(--lvl > 0){
        while(!va->empty()){
            int p = va->front(); va->pop_front();
            int l, r;
            scanf("%d%d", &l, &r);
            tree[p].v = dat[tree[p].a + l];
            if (l){
                tree[pos].p = p;
                tree[p].l = pos;
                tree[pos].a = tree[p].a;
                tree[pos].b = tree[p].a + l;
                if (l==1){
                    tree[pos].v = dat[tree[pos].a];
                    ++pos;
                } else {
                    vb->push_back(pos++);
                }
            }
            if (r){
                tree[pos].p = p;
                tree[p].r = pos;
                tree[pos].a = tree[p].a + l + 1;
                tree[pos].b = tree[p].b;
                if (r == 1){
                    tree[pos].v = dat[tree[pos].a];
                    ++pos;
                } else {
                    vb->push_back(pos++);
                }
            }
        }
        vt=va; va=vb; vb=vt;
    }
    while(!va->empty()){
        int p = va->front(); va->pop_front();
        tree[p].v = dat[tree[p].a];
    }
    first = true;
    postOrder(0);
    printf("\n");
}

int readIn(){
    if (scanf("%d", &num) < 0) return 0;
    int i;
    for (i=0; i<num; ++i)
        scanf("%d", &dat[i]);
    sort(dat, dat+num);
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

