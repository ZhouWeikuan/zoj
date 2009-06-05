#include<iostream>
using namespace std;
// 每次找距离为2的两个相邻结点，合并到它们的父结点中
// 并更新与其它相邻点的距离
enum {
    SIZ = 1008,
};
struct Node {
    int l, nl, r,nr;
    int mark;
};
Node tree[SIZ];
int num;
int s,e;

int fun(){
    if(s == e)
        return 0;
    int step = 0;
    tree[s].mark = tree[e].mark = 1;
    for(;;){
        for(int cur = 0; cur != -1; cur = tree[cur].r){
            if(tree[cur].nr  == 2) {
                int l = tree[cur].l;
                int r = tree[cur].r;
                int t = tree[cur].mark + tree[r].mark;
                if(t == 2)
                    return step + 2;
                step += t;
                if(l != -1){
                    tree[l].r = cur;
                    tree[l].nr --;
                }
                r = tree[r].r;
                if(r != -1){
                    tree[r].l = cur;
                    tree[r].nl --;
                }
                // 合并
                r = tree[cur].r;
                tree[cur].nl --;
                tree[cur].r = tree[r].r;
                tree[cur].nr = tree[r].nr-1;
                tree[cur].mark = t;
            }
        }
    }
    return 0;
}

void readIn(){
    int t;
    scanf("%d",&num);
    tree[0].l = -1, tree[0].nl = -1;
    tree[0].mark = 0;
    for(int i=1;i<num;i++){
        scanf("%d", &t);
        tree[i-1].r = i; tree[i-1].nr = t;
        tree[i].l = i-1; tree[i].nl = t;
        tree[i].mark = 0;
    }
    tree[num-1].r = -1, tree[num-1].nr = -1;
    scanf("%d%d ",&s, &e);
    s--, e--;
}
int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase --){
        readIn();
        printf("%d\n",fun());
    }

    return 0;
}

