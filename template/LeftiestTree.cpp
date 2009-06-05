/*
 * A leftiest tree is that the parent has the least key and 
 *  dist(right) <= dist(left)  and
 *  dist(parent) = dist(right) + 1
 */
struct Node {
    int key;
    int left,right,parent;
    int dist;
};
enum {
    SIZ = 100,
};
Node tree[SIZ];

int cmp(Node &a, Node &b){
    return a.key - b.key;
}

// init a node as a root
void init(Node &n){
    n.dist = 0;
    n.left = n.right = n.parent = -1;
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

// insert p into root
int insert(int root, int node){
    return merge(root, node);
}

// return the root of the tree node lives
int get_root(int node){
    while(tree[node].parent != -1){
        node = tree[node].parent;
    }
    return node;
}

// delete the root and return the new root
int delete_min(int root){
    int l,r;
    l = tree[root].left; r = tree[root].right;
    tree[root].left = tree[root].right = tree[root].parent = -1;
    return merge(l,r);
}

// delete the node in the tree and return the newly occupied node
void delete_node(int node){
    int p,l,r,t;
    p = tree[node].parent; tree[node].parent = -1;
    l = tree[node].left;  tree[node].left = -1;
    r = tree[node].right; tree[node].right = -1;
    r = merge(l,r);
    tree[r].parent = p;
    if(p != -1){
        if(tree[p].left == node){
            tree[p].left = r;
        } else {
            tree[p].right = r;
        }
    }
    p = r;
    while(p != -1){
        l = tree[p].left; r = tree[p].right;
        if(tree[l].dist < tree[r].dist){
            t = tree[p].left; tree[p].left = tree[p].right; tree[p].right = t;
        }
        r = tree[p].right;
        if(tree[p].dist == tree[r].dist + 1)
            return;
        tree[p].dist = tree[r].dist + 1;
        p = tree[p].parent;
    }
}

// decrease node's key
int decrease(int node, int count){
    int l,r;
    l = tree[node].left; r = tree[node].right;
    tree[node].key -= count;

    tree[l].parent = tree[r].parent = -1;
    tree[node].left = tree[node].right = -1;
    l = merge(l,r);
    node = merge(l,node);
    return node;
}
