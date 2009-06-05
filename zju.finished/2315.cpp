#include<iostream>
using namespace std;
// 注意 Bill Hates 一定不能拿奖，不然就错了...
enum {
    SIZ = 500004,
};
struct Node {
    int p;
    int u;
    int v0;
    int v1;
    int m;
};
int num;
Node tree[SIZ];

void fun(){
    int p, u;
    for(int i=num-1;i>=0;i--){
        tree[i].v1++; // self occupy
        p = tree[i].p;
        if(p == -1){
            continue;
        }
        // if chief use it
        tree[p].v1 += tree[i].v0;
        // if chief not use it
        u = tree[p].u;
        if(u == -1 || tree[i].v1 + tree[u].v0 > tree[u].v1 + tree[i].v0){
            tree[p].v0 += tree[i].v1;
            tree[p].u = i;
        } else {
            tree[p].v0 += tree[i].v0;
        }
    }
    p = tree[0].v0;
    tree[0].m = 0;

    printf("%d\n", p * 1000);
    bool bPrint = false;
    for(u=0; u<num; u++){
        if(tree[u].m == -1){
            p = tree[u].p;
            if(tree[p].m == 1){
                tree[u].m = 0;
            } else if(tree[p].u == u){
                tree[u].m = 1;
            } else {
                tree[u].m = 0;
            }
        }
        if(tree[u].m == 0)
            continue;
        if(bPrint){
            printf(" %d", u+1);
        } else {
            printf("%d", u + 1);
            bPrint = true;
        }
    }
    printf("\n");
}

void readIn(){
    tree[0].p = -1;
    tree[0].u = -1;
    tree[0].m = -1;
    int t;
    for(int i=1;i<num;i++){
        scanf("%d",&t);
        --t;
        tree[i].p = t;
        tree[i].u = -1;
        tree[i].m = -1;
    }
}

int main(){
    int tstcase;
    scanf("%d",&tstcase);

    while(tstcase --){
        scanf("%d",&num);
        memset(tree, 0, sizeof(Node)*num);
        readIn();
        fun();
    }

    return 0;
}

