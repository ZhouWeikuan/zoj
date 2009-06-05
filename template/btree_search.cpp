#include<iostream>

// 1442 in pku
using namespace std;
enum {
    SIZ = 30008,
};
struct Node {
    int u; // used ?
    int v; // value of this node
    int l,r;
    int cnt; // number that <= this node
};
int input[SIZ];
int tmp[SIZ];
int N,M, pos;
Node tree[SIZ];
int next;

int build_tree(int s, int e){
    if(e <= s)
        return -1;
    int m = (s + e) / 2;
    int ret = next ++;
    Node *tptr = &tree[ret];
    tptr->v = tmp[m];
    tptr->u = tptr->cnt = 0;
    tptr->l = build_tree(s, m);
    tptr->r = build_tree(m+1,e);
    return ret;
}
int insert_tree(int r, int v){
    if(r < 0)
        return -1;
    if(tree[r].v == v){ // special for equals, first left, second right, last itself
        int t = insert_tree(tree[r].l, v);
        if(t == -1){
            t = insert_tree(tree[r].r, v);
        } else {
            tree[r].cnt ++;
        }
        if(t != -1)
            return 0;
        if(tree[r].u == 1){
            return -1;
        }
        tree[r].u = 1;
        return 0;
    }
    if(tree[r].v > v){
        int t = insert_tree(tree[r].l, v);
        if(t != -1){
            tree[r].cnt ++;
        }
        return t;
    }
    return insert_tree(tree[r].r, v);
}
int find_tree(int r, int p){
    if(tree[r].cnt > p){
        return find_tree(tree[r].l, p);
    }
    p -= tree[r].cnt;
    if(p ==0 && tree[r].u){
        return tree[r].v;
    }
    p -= tree[r].u;
    return find_tree(tree[r].r, p);
}

int readIn(){
    int i;
    if(scanf("%d%d",&N,&M) <= 0)
        return 0;
    for(i=0;i<N;i++){
        scanf("%d", &input[i]);
        tmp[i] = input[i];
    }
    sort(tmp, tmp+N);
    next = 0;
    build_tree(0, N);
    return 1;
}

void fun(){
    int cur, i=0, t;
    pos = 0;
    while(M --){
        scanf("%d", &cur);
        while(i < cur){
            insert_tree(0, input[i]);
            i ++;
        }
        t = find_tree(0, pos);
        printf("%d\n", t);
        pos ++;
    }
}

int main(){
    int tstcase = 0;

    while( readIn() ){
        if(tstcase ++){
            printf("\n");
        }
        fun();
    }

	return 0;
}
