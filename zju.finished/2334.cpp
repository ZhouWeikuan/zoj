#include<cstdio>

using namespace std;
enum {
    SIZ = 100004,
};

struct Node {
    int key;
    int left,right,parent;
    int dist;
};
Node tree[SIZ];
int num;

// a heap with big head 
int cmp(Node &a, Node &b){
    return b.key - a.key;
}

// merge two tree and return the root
int merge(int a, int b){
    if(a == -1)
        return b;
    if(b == -1)
        return a;
    int t;
    if(cmp(tree[a], tree[b]) > 0){
        t = a; a= b; b= t;
    }
    int l,r;
    r = merge(tree[a].right, b);
    tree[a].right = r;
    tree[r].parent = a;
    
    l = tree[a].left;
    if(tree[r].dist > tree[l].dist){
        t = tree[a].left; tree[a].left = tree[a].right; tree[a].right = t;
    }
    
    r = tree[a].right;
    tree[a].dist = tree[r].dist + 1;
    return a;
}

// return the root of the tree node lives
int get_root(int node){
    while(tree[node].parent != -1){
        node = tree[node].parent;
    }
    return node;
}

// decrease node's key
int decrease(int node){
    int l,r;
    l = tree[node].left; r = tree[node].right;
    tree[node].key /= 2;

    tree[l].parent = tree[r].parent = -1;
    tree[node].left = tree[node].right = -1;
    l = merge(l,r);
    node = merge(l,node);
    return node;
}

int readIn(){
    if(scanf("%d ",&num) < 0)
        return 0;
    for(int i=0; i<num; i++){
        scanf("%d ", &tree[i].key);
        tree[i].dist = 0;
        tree[i].parent = tree[i].left = tree[i].right = -1;
    }

    return 1;
}

void fun(){
    int tstcase;
    int a, b;

    scanf("%d ", &tstcase);
    while(tstcase --){
        scanf("%d %d ", &a, &b);
        a --, b--;
        a = get_root(a);  b = get_root(b);
        if(a == b){
            printf("-1\n");
        } else {
            a = decrease(a);  b = decrease(b);
            a = merge(a, b);
            printf("%d\n", tree[a].key);
        }
    }
}

int main(){
    
    while(readIn()){
        fun();
    }

	return 0;
}
