#include<iostream> 
using namespace std;

enum {
    SIZ = 32, // number of digitals
    MIN_KEY = -99999999,
    MAX_KEY = 99999999,
};
template<typename Key, typename Value = int>
struct FibNode {
    Value *val;
    Key key;
    int degree;
    bool mark;

    FibNode *parent;
    FibNode *child;
    FibNode *left;
    FibNode *right;
};

FibNode<int> *A[SIZ];

template<typename Key, typename Node>
class FibHeap{
    Node *head;
    int num;
  private:
    FibHeap& operator=(const FibHeap &);
    FibHeap(const FibHeap &);
    void consolidate();
    void link(Node*y, Node*x); // link y to x
  public:
    FibHeap();
    void insert(Node *x);
    Node * minimum();
    Node * extract_min();
    void cascading_cut(Node *y);
    void cut(Node *x, Node *y);
    void join(FibHeap *bh);
    void decrease_key(Node *x, Key k);
    void remove(Node *x);
    void dump();
};

template<typename Key, typename Node>
FibHeap<Key, Node>::FibHeap(){
    head = 0;
    num = 0;
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::insert(Node *x){
    x->degree = 0;
    x->parent = 0;
    x->child = 0;
    x->left = x->right = x;
    x->mark = false;

    if(head == 0){
        head = x;
    } else {
        x->right = head->right;
        head->right->left = x;
        x->left = head;
        head->right = x;
    }
    if(head->key > x->key)
        head = x;

    ++num;
}

template<typename Key, typename Node>
Node * FibHeap<Key, Node>::minimum(){
    return head;
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::join(FibHeap * fh){
    if(fh->num == 0)
        return;
    if(num == 0){
        num = fh->num;
        head = fh->head;
        return 0;
    }
    num += fh->num;

    // chains two double lists
    head->right->left = fh->head->left;
    fh->head->left->right = head->right;
    head->right = fh->head;
    fh->head->left = head;

    if(head->key > fh->head->key)
        head = fh->head;
}

template<typename Key, typename Node>
Node * FibHeap<Key, Node>::extract_min(){
    if(head == 0) return head;
    Node *z = head;
    Node *x = z->child;
    while(x!=0){
        Node *y = x->right;
        y->parent = 0;
        if(x==y){
            x = 0;
        } else {
            x->right = y->right;
            x->right->left = x;
        }
        // put y into root list
        y->right = z->right;
        z->right->left = y;
        y->left = z;
        z->right = y;
    }
    // remove z
    z->left->right = z->right;
    z->right->left = z->left;
    --num;
    if(z==z->right)
        head = 0;
    else {
        head = z->right;
        consolidate();
    }
    return head;
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::consolidate(){
    memset(A, 0, sizeof(A));
    int d;
    Node *x=0, *y=0;
    while(head){
        // get out of a node
        x = head->right;
        if(x==head){
            head = 0;
        }else {
            head->right = x->right;
            head->right->left = head;
        }

        // integrate same degree
        d = x->degree;
        while(A[d]!=0){
            y = A[d];
            A[d] = 0;
            if(x->key > y->key){
                Node *t = x;
                x=y;
                y=t;
            }
            link(y, x);
            ++d;
        }
        A[d] = x;
    }
    for(d=0; d<SIZ; d++){
        if(A[d] == 0) continue;
        if(head == 0){
            head = A[d];
            head->left = head->right = head;
        } else {
            A[d]->right = head->right;
            head->right->left = A[d];
            A[d]->left = head;
            head->right = A[d];
            if(head->key > A[d]->key)
                head = A[d];
        }
    }
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::link(Node*y, Node*x){
    y->parent = x;
    if(x->child == 0){
        x->child = y;
        y->left = y->right = y;
    } else {
        y->right = x->child->right;
        x->child->right->left = y;
        y->left = x->child;
        x->child->right = y;
    }
    ++x->degree;
    y->mark = false;
}

template<typename Node>
void print_tree(FILE *fp, Node *h){
    Node *x = h;
    do {
        fprintf(fp, "%d -> %d [color=\"blue\"] \n", x->key, x->right->key);
        fprintf(fp, "%d -> %d [color=\"green\"] \n", x->right->key, x->key);
        if(x->child){
            fprintf(fp, "%d -> %d [color=\"red\"] \n", x->key, x->child->key);
            fprintf(fp, "%d -> %d \n", x->child->key, x->key);
            print_tree(fp, x->child);
        }
        x = x->right;
    } while(x!=h);

    fprintf(fp, "{\n rank=same\n");
    x = h;
    do {
        fprintf(fp, " %d", x->key);
        x = x->right;
    } while(x!=h);
    fprintf(fp, "\n}\n");
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::dump(){
    static char cmd[100];
    static char buf[100];
    static int  n = 0;
    ++n;
    snprintf(buf, 100, "test%03d.dot", n);
    FILE *fp = fopen(buf, "w");
    fprintf(fp, "digraph G {\n");
    fprintf(fp, "{\n");
    fprintf(fp, "   rank=same\n");
    Node *x = head;
    if(x){
        do {
            fprintf(fp, "%d ", x->key);
            x = x->right;
        }while(x!=head);
    }
    fprintf(fp, "\n");
    fprintf(fp, "}\n");
    if(head)
        print_tree(fp, head);
    fprintf(fp, "}\n");
    fclose(fp);

    snprintf(cmd, 100, "dot -Tjpg test%03d.dot -o test%03d.jpg", n, n);
    system(cmd);
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::decrease_key(Node *x, Key k){
    if (k>x->key)
        throw "new key is greater than current key.";
    x->key = k;
    Node *y = x->parent;
    if (y!=0 && x->key < y->key){
        cut(x, y);
        cascading_cut(y);
    }
    
    if (x->key < head->key)
        head = x;
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::cut(Node *x, Node *y){
    //remove x from y's child list
    --y->degree;
    if(x->right == x){ // y has only one child
        y->child = 0;
    } else {
        if(y->child == x){
            y->child = x->right;
        }
        x->right->left = x->left;
        x->left->right = x->right;
    }
    // put x into root list
    x->parent = 0;
    x->mark = false;
    x->right = head->right;
    head->right->left = x;
    x->left = head;
    head->right =x ;
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::cascading_cut(Node *y){
    Node *z = y->parent;
    if (z!=0){
        if (y->mark == false)
            y->mark = true;
        else {
            cut(y, z);
            cascading_cut(z);
        }
    }
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::remove(Node *x){
    decrease_key(x, MIN_KEY);
    extract_min();
}

/*
template<typename Key, typename Node>
void FibHeap<Key, Node>::cut(Node *x, Node *y){
}

template<typename Key, typename Node>
void FibHeap<Key, Node>::cut(Node *x, Node *y){
}
template<typename Key, typename Node>
void FibHeap<Key, Node>::cut(Node *x, Node *y){
}
*/

int main(){
    int arr[SIZ], i;
    for(i=0; i<SIZ; i++){
        arr[i] = i + 1;
    }
    srand(time(0));
    random_shuffle(arr, arr+SIZ);

    FibHeap<int, FibNode<int> >  fh;
    for(i=0; i<SIZ; i++){
        FibNode<int> *x = new FibNode<int>();
        x->val = 0;
        x->key = arr[i];
        fh.insert(x);

        if(i%5==4)
            fh.extract_min();

        fh.dump();
    }

    return 0;
}
