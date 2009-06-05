#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_KEY 999999
#define MIN_KEY -999999
template<typename key_t, typename val_t = int>
struct BinoNode {
    BinoNode *parent;
    BinoNode *child;
    BinoNode *sib;
    key_t key;
    int degree;
    val_t *val;
};

template<typename key_t, typename node_t>
class BinoHeap{
  private:
    BinoHeap& operator=(const BinoHeap&);
    BinoHeap(const BinoHeap&);
    void link(node_t *y, node_t *z);
    node_t *    trim_min();
    node_t *    reverse_child(node_t *x);
    node_t *    merge(BinoHeap *bh);

    node_t *    head; // pointer to the root list
  public:
    BinoHeap();
    ~BinoHeap(){}
    void insert(node_t *x);
    node_t * minimum();
    node_t * extract_min();
    void join(BinoHeap *bh);
    void decrease_key(node_t *x, key_t k);
    void remove(node_t *x);
    void dump();
};

template<typename key_t, typename node_t>
BinoHeap<key_t, node_t>::BinoHeap(){
    head = 0;
}

template<typename key_t, typename node_t>
node_t * BinoHeap<key_t, node_t>::minimum(){
    node_t *y = 0; 
    node_t *x = head; 
    key_t m = MAX_KEY;
    while(x!=0){
        if(x->key < m){
            m = x->key;
            y = x;
        }
        x = x->sib;
    }
    return y;
}

template<typename key_t, typename node_t>
void BinoHeap<key_t, node_t>::link(node_t *y, node_t *z){
    y->parent = z;
    y->sib = z->child;
    z->child = y;
    ++z->degree ;
}

template<typename key_t, typename node_t>
node_t * BinoHeap<key_t, node_t>::merge(BinoHeap *bh){
    if(head==0 || bh->head == 0) 
        return head?head:bh->head;

    node_t *nh, *nt;
    if(head->degree <= bh->head->degree){
        nh = head; head = head->sib;
    } else{
        nh = bh->head; bh->head = bh->head->sib;
    }
    nt = nh;
    while(head && bh->head){
        if(head->degree <= bh->head->degree){
            nt->sib = head; 
            head = head->sib;
        } else{
            nt->sib = bh->head; 
            bh->head = bh->head->sib;
        }
        nt = nt->sib;
    }
    if(head == 0){
        nt->sib = bh->head;
    } else {
        nt->sib = head;
    }

    return nh;
}

template<typename key_t, typename node_t>
void BinoHeap<key_t, node_t>::join(BinoHeap *bh){
    head = merge(bh);
    if(head==0)
        return ;

    node_t *px = 0, *x=head, *nx=head->sib;
    while(nx != 0){
        if ( x->degree != nx->degree
            || (nx->sib!=NULL && nx->sib->degree == x->degree) ){
            px = x;
            x = nx;
        } else if(x->key <= nx->key){
            x->sib = nx->sib;
            link(nx, x);
        } else {
            if(px == 0){
                head = nx;
            } else {
                px->sib = nx;
            }
            link(x, nx);
            x = nx;
        }

        nx = x->sib;
    }

}

template<typename key_t, typename node_t>
void BinoHeap<key_t, node_t>::insert(node_t *x){
    BinoHeap bh;
    x->parent = 0;
    x->child = 0;
    x->sib = 0;
    x->degree = 0;
    bh.head = x;
    join(&bh);
}

template<typename key_t, typename node_t>
node_t * BinoHeap<key_t, node_t>::trim_min(){
    if(head==0) 
        return 0;
    node_t *px = head;
    node_t *x  = px->sib;
    node_t *sx = px;
    key_t m = px->key;

    while(x){
        if(x->key < m){
            sx = px;
            m = x->key;
        }
        px = x;
        x = x->sib;
    }
    if( m == sx->key){ // the first one;
        x = sx;
        head = sx->sib;
    } else {        // in the middle or end;
        x = sx->sib;
        sx->sib = x->sib;
    }

    return x;
}

template<typename key_t, typename node_t>
node_t * BinoHeap<key_t, node_t>::reverse_child(node_t *x){
    if(x==0) 
        return 0;
    node_t *h = x->child;
    node_t *n; 
    if(h == 0)
        return h;
    n = h->sib; h->sib = 0;
    while(n){
        node_t *s = n->sib;    
        n->sib = h;
        h = n;
        n = s;
    }

    return h; 
}

template<typename key_t, typename node_t>
node_t * BinoHeap<key_t, node_t>::extract_min(){
    node_t *x = trim_min();
    BinoHeap bh;
    bh->head = reverse_child(x);
    join(bh);
    return x;
}

template<typename key_t, typename node_t>
void BinoHeap<key_t, node_t>::decrease_key(node_t *x, key_t k){
    if(k>x->key){
        throw "new key is greater than current key";
    }
    x->key = k;
    node_t *y = x;
    node_t *z = x->parent;
    while(z!=0 && y->key < z->key){
        swap(y->key, z->key);
        swap(y->val, z->val);
        // update pointer information
        if(y->val){
            y->val->ptr = y;
            z->val->ptr = z;
        }

        y = z;
        z = y->parent;
    }
}

template<typename key_t, typename node_t>
void BinoHeap<key_t, node_t>::remove(node_t *x){
    decrease_key(x, MIN_KEY);
    extract_min();
}

template<typename Node>
void print_tree(FILE *fp, Node *x){
    Node *c = x->child;
    while(c!=0){
        print_tree(fp, c);
        fprintf(fp, "%d -> %d\n", x->key, c->key);
        c = c->sib;
    }
}

template<typename key_t, typename node_t>
void BinoHeap<key_t, node_t>::dump(){
    static int n = 0;
    static char buf[20];
    n++;
    snprintf(buf, 20, "test%03d.dot", n);

    FILE*fp=fopen(buf, "w");
    fprintf(fp, "digraph G {\n");
    fprintf(fp, "   {\n");
    fprintf(fp, "       rank=same\n");
    node_t *x = head;
    while(x!=NULL){
        fprintf(fp, " %d", x->key);
        x = x->sib;
    }
    fprintf(fp, "\n");
    fprintf(fp, "   }\n");
    x = head;
    while(x!=NULL){
        if(x->sib)
            fprintf(fp, "%d -> %d\n", x->key, x->sib->key);
        print_tree(fp, x);
        x = x->sib;
    }
    fprintf(fp, "}\n");
    fclose(fp);
    
    char cmd[100];
    snprintf(cmd, 100, "dot -Tjpg %s -o test%03d.jpg", buf, n);
    system(cmd);
}

int main(){
    int N = 20;
    int arr[N], i;

    for(i=0; i<N; i++){
        arr[i] = 20 - i;
    }

    srand(time(0));
    random_shuffle(arr, arr+N);
    BinoHeap<int, BinoNode<int> > bh;
    for(i=0; i<N; i++){
        BinoNode<int> *x = new BinoNode<int>();
        x->val = 0;
        x->key = arr[i];
        bh.insert(x);
        bh.dump();
    }

    return 0;
}
