#include<iostream>
using namespace std;
enum {
    INCSIZ = 2000,
    NOVAL = 0,
};
// position count from 0 
struct Splay {
    int lcnt, rcnt;
    int val;
    Splay *left, *right, *par;
};

Splay *next, *head;

void putNode(Splay *r){
    next->par = r;
    next = r;
}
Splay *getNode(){
    if(next == 0){
        next = (Splay*)malloc(sizeof(Splay)*INCSIZ);
        for(int i=0; i<INCSIZ; i++){
            next[i].par = &next[i+1];
        }
        next[INCSIZ-1].par = 0;
    }
    Splay *r = next;
    next = next->par;
    memset(r, 0, sizeof(Splay));
    return r;
}

void clear(Splay * r){
    if(r==0) return;
    clear(r->left);
    clear(r->right);
    putNode(r);
}

void travel(Splay *r){
    if(r==0) return;
    travel(r->left);
    printf("%d ", r->val);
    travel(r->right);
}

void zig(Splay *x, Splay *y){ // y->left == x 
    y->left = x->right;
    y->lcnt = x->rcnt;
    if(y->left) 
        y->left->par = y;
    x->right= y;
    x->rcnt = y->lcnt + y->rcnt + 1;
    x->par = y->par;
    y->par = x;
}

void zag(Splay *x, Splay *y){ // y->right == x
    y->right = x->left;
    y->rcnt  = x->lcnt;
    if(y->right) 
        y->right->par = y;
    x->left  = y;
    x->lcnt  = y->lcnt + y->rcnt + 1;
    x->par = y->par;
    y->par = x;
}

void zig_zig(Splay *x, Splay *y, Splay *z){ // z->left == y && y->left == x
    if(z->par){
        if(z->par->left == z){
            z->par->left = x;
        } else{
            z->par->right = x;
        }
    }
    x->par = z->par;

    z->left = y->right;
    z->lcnt = y->rcnt;
    if(y->right) 
        y->right->par = z;

    y->right = z;
    y->rcnt = z->lcnt + z->rcnt + 1;
    z->par = y;

    y->left = x->right;
    y->lcnt = x->rcnt;
    if(x->right) x->right->par = y;

    x->right = y;
    x->rcnt = y->lcnt + y->rcnt + 1;
    y->par = x;
}

void zig_zag(Splay *x, Splay *y, Splay *z){ // z->right==y && y->left == x
    if(z->par){
        if(z->par->left == z){
            z->par->left = x;
        } else {
            z->par->right= x;
        }
    }
    x->par = z->par;

    z->right = x->left;
    z->rcnt  = x->lcnt;
    if(z->right) 
        z->right->par = z;

    x->left  = z;
    x->lcnt  = z->lcnt + z->rcnt + 1;
    z->par = x;

    y->left  = x->right;
    y->lcnt  = x->rcnt;
    if(y->left) 
        y->left->par = y;

    x->right = y;
    x->rcnt  = y->lcnt + y->rcnt + 1;
    y->par = x;
}

void zag_zag(Splay *x, Splay *y, Splay *z){ // z->right==y && y->right == x
    if(z->par){
        if(z->par->left == z){
            z->par->left = x;
        } else {
            z->par->right =x ;
        }
    }
    x->par = z->par;
    z->right = y->left;
    z->rcnt  = y->lcnt;
    if(z->right) z->right->par = z;

    y->left  = z;
    y->lcnt  = z->lcnt + z->rcnt + 1;
    z->par = y;

    y->right = x->left;
    y->rcnt  = x->lcnt;
    if(y->right) y->right->par = y;

    x->left  = y;
    x->lcnt  = y->lcnt + y->rcnt + 1;
    y->par = x;
}

void zag_zig(Splay *x, Splay *y, Splay *z){ // z->left==y && y->right == x
    if(z->par){
        if(z->par->left == z){
            z->par->left = x;
        } else {
            z->par->right = x;
        }
    }
    x->par = z->par;

    z->left  = x->right;
    z->lcnt  = x->rcnt ;
    if(z->left) z->left->par = z;

    x->right = z;
    x->rcnt  = z->lcnt + z->rcnt + 1;
    z->par = x;

    y->right = x->left;
    y->rcnt  = x->lcnt;
    if(y->right) y->right->par = y;

    x->left  = y;
    x->lcnt  = y->lcnt + y->rcnt + 1;
    y->par = x;
}

Splay *insert(Splay *r, int p, int v){
    if(r==0){
        r = getNode();
        r->val = v;
        return r;
    }
    while( !(r->lcnt==p && r->val==NOVAL) ){
        if(r->lcnt >= p){
            if(r->left == 0){
                Splay *t = getNode();
                r->left = t;
                r->lcnt = 1;
                t->par = r;
                r = t;
                break;
            }
            r = r->left;
        } else {
            if(r->right == 0){
                Splay *t = getNode();
                r->right = t;
                r->rcnt = 1;
                t->par = r;
                r = t;
                break;
            }
            p -= r->lcnt + 1;
            r = r->right;
        }
    }
    r->val = v;
    Splay *y, *z;
    while(r->par){
        y = r->par;
        z = y->par;
        if(z == 0){
            if(y->left == r){
                zig(r, y);
            } else {
                zag(r, y);
            }
        } else if(z->left == y){
            if(y->left == r){
                zig_zig(r, y, z);
            } else {
                zag_zig(r, y, z);
            }
        } else { // right == y;
            if(y->left == r){
                zig_zag(r, y, z);
            } else {
                zag_zag(r, y, z);
            }
        }
    }
    return r;
}

void remove(Splay *r, int p){
    while(r->left || r->right){ // nonleaf
        if(r->lcnt > r->rcnt){
            zig(r->left, r);
        } else {
            zag(r->right, r);
        }
    }
    if(r->par){
        if(r->par->left == r){
            r->par->left = 0;
            r->par->lcnt = 0;
        } else {
            r->par->right = 0;
            r->par->rcnt = 0;
        }
    }
    putNode(r);
}

int getMax(Splay *r){
    while(r->right){
        r = r->right;
    }
    return r->val;
}

int getMin(Splay *r){
    while(r->left){
        r = r->left;
    }
    return r->val;
}

Splay* find(Splay *r, int p){
    if(r == 0) return r;
    while(r->lcnt!=p){
        if(r->lcnt >= p){
            r = r->left;
        } else {
            p -= r->lcnt + 1;
            r = r->right;
        }
    }
    return r;
} 

int firstPrint, maxVal;
int num;


void fun(){
    int p, v;
    v = 1;
    head = 0;
    firstPrint = 1;
    while(num--){
        scanf("%d", &p);
        --p;
        while(maxVal < p){
            head = insert(head, maxVal, NOVAL);
            maxVal++;
        }
        head = insert(head, p, v++);
        maxVal += (p>=maxVal);
    }
    printf("%d\n", head->lcnt + head->rcnt + 1);
    travel(head);
    printf("\n");
    clear(head);
}

int readIn(){
    int t;
    scanf("%d%d", &num, &t);
    maxVal = 0;
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst -- ){
        if(tst) printf("\n");
        readIn();
        fun();
    }
    return 0;
}

