#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

enum {
    INCSIZ = 2000,
    NOVAL = 0,
};

int dat[50004];
int minVal, maxVal;

typedef int val_t;
typedef unsigned pos_t;
// position count from 0 
struct Splay {
    pos_t cnt;
    val_t val;
    Splay *left, *right, *par;
  public:
    static Splay * next;
    static void putNode(Splay *r){
        memset(r, 0, sizeof(*r));
        r->par = next;
        next = r;
    }

    static Splay *getNode(Splay *p, int v){
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
        r->par = p;
        r->cnt = 1;
        r->val = v;
        return r;
    }

    static void clear(Splay * r){
        if(r==0) return;
        if (r->left) clear(r->left);
        if (r->right) clear(r->right);
        putNode(r);
    }
};
Splay * Splay::next = NULL;

int inline getLcnt(Splay *r){
    return (r->left == 0?0:r->left->cnt);
}
int inline getRcnt(Splay *r){
    return (r->right==0?0:r->right->cnt);
}

void travel(Splay *r){
    if(r==0) return;
    travel(r->left);
    printf("%d\n", r->val);
    travel(r->right);
}

void zig(Splay *x, Splay *y){ // y->left == x 
    y->left = x->right;
    if(y->left) 
        y->left->par = y;
    x->right= y;
    x->par = y->par;
    y->par = x;
    if (x->par){
        if (x->par->left == y){
            x->par->left = x;
        } else {
            x->par->right = x;
        }
    }
    y->cnt = 1 + getLcnt(y) + getRcnt(y);
    x->cnt = 1 + getLcnt(x) + getRcnt(x);
}

void zag(Splay *x, Splay *y){ // y->right == x
    y->right = x->left;
    if(y->right) 
        y->right->par = y;
    x->left  = y;
    x->par = y->par;
    y->par = x;
    if (x->par){
        if (x->par->left == y){
            x->par->left = x;
        } else {
            x->par->right = x;
        }
    }
    y->cnt  = 1 + getLcnt(y) + getRcnt(y);
    x->cnt  = 1 + getLcnt(x) + getRcnt(x);
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
    if(y->right) 
        y->right->par = z;

    y->right = z;
    z->par = y;
    y->left = x->right;
    if(x->right) 
        x->right->par = y;
    x->right = y;
    y->par = x;

    z->cnt = 1 + getLcnt(z) + getRcnt(z);
    y->cnt = 1 + getLcnt(y) + getRcnt(y);
    x->cnt = 1 + getLcnt(x) + getRcnt(x);
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
    if(z->right) 
        z->right->par = z;

    x->left  = z;
    z->par = x;
    y->left  = x->right;
    if(y->left) 
        y->left->par = y;

    x->right = y;
    y->par = x;
    z->cnt  = 1 + getLcnt(z) + getRcnt(z);
    y->cnt  = 1 + getLcnt(y) + getRcnt(y);
    x->cnt  = 1 + getLcnt(x) + getRcnt(x);
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
    if(z->right) z->right->par = z;

    y->left  = z;
    z->par = y;
    y->right = x->left;
    if(y->right) y->right->par = y;

    x->left  = y;
    y->par = x;

    z->cnt  = 1 + getLcnt(z) + getRcnt(z);
    y->cnt  = 1 + getLcnt(y) + getRcnt(y);
    x->cnt  = 1 + getLcnt(x) + getRcnt(x);
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
    if(z->left) z->left->par = z;

    x->right = z;
    z->par = x;

    y->right = x->left;
    if(y->right) y->right->par = y;

    x->left  = y;
    y->par = x;

    z->cnt  = 1 + getLcnt(z) + getRcnt(z);
    y->cnt  = 1 + getLcnt(y) + getRcnt(y);
    x->cnt  = 1 + getLcnt(x) + getRcnt(x);
}

Splay *shift_up(Splay *r){
    Splay *y, *z;
    while(r->par){
        y = r->par;
        int lc = getLcnt(y);
        int rc = getRcnt(y);
        if (lc <= rc){
            if (rc-lc < 10){
                r = r->par;
            } else if (rc >= 4*lc){ // r == y->right
                r = y->right;
                zag(r, y);
            } else {
                r = r->par;
            }
        } else {
            if (lc-rc < 10){
                r = r->par;
            } else if (lc >= 4*rc){
                r = y->left;
                zig(r, y);
            } else {
                r = r->par;
            }
        }
/*        z = y->par;
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
        } */
    }
    return r;
}

Splay * insertVal(Splay *r, val_t v){
    if (r == 0){
        r = Splay::getNode(r, v);
        return r;
    }
    while(1){
        if(r->val >= v){
            ++r->cnt;
            if (r->left){
                r = r->left;
            } else {
                r->left = Splay::getNode(r, v);
                r = r->left;
                break;
            }
        } else {
            ++r->cnt;
            if (r->right){
                r = r->right;
            } else {
                r->right = Splay::getNode(r, v);
                r = r->right;
                break;
            }
        }
    }
    r = shift_up(r);
    return r;
}

Splay * insertPos(Splay *r, int p, int v){
    if(r==0){
        r = Splay::getNode(r, v);
        return r;
    }
    while(!(getLcnt(r)==p && r->val==NOVAL) ){
        if(getLcnt(r) >= p){
            if(r->left == 0){
                ++r->cnt;
                r->left = Splay::getNode(r, v);
                r = r->left;
                break;
            }
            r = r->left;
        } else {
            if(r->right == 0){
                ++r->cnt;
                r->right = Splay::getNode(r, v);
                r = r->right;
                break;
            }
            p -= getLcnt(r) + 1;
            r = r->right;
        }
    }
    r = shift_up(r);
    return r;
}

Splay* removeSplayNode(Splay *r){
    if (r==0) return 0;
    while(r->left || r->right){ // nonleaf
        if(getLcnt(r) > getRcnt(r)){
            zig(r->left, r);
        } else {
            zag(r->right, r);
        }
    }
    if(r->par){
        if(r->par->left == r){
            r->par->left = 0;
        } else {
            r->par->right = 0;
        }
    }
    Splay *t = r->par;
    Splay::putNode(r);
    if (t==0) return t;
    --t->cnt;
    while(t->par) {
        t=t->par;
        --t->cnt;
    }
    return t;
}

Splay* findPos(Splay *r, pos_t p){
    while(r && getLcnt(r)!=p){
        if(getLcnt(r) >= p){
            r = r->left;
        } else {
            p -= getLcnt(r) + 1;
            r = r->right;
        }
    }
    return r;
} 

Splay* findVal(Splay *r, val_t v, pos_t *pos){
    if(r == 0) return r;
    *pos = 0;
    while(r && r->val!=v){
        if(v < r->val){
            r = r->left;
        } else {
            *pos += getLcnt(r) + 1;
            r = r->right;
        }
    }
    return r;
} 

Splay * removeVal(Splay *tree, int v){
    if (tree == 0) return tree;
    Splay *r = tree;
    while(r && r->val!=v){
        if(v < r->val){
            r = r->left;
        } else {
            r = r->right;
        }
    }
    if (r){
        tree = removeSplayNode(r);
    }
    return tree;
}

// return [a, b) to indicate v's range in SplayTree r
pair<pos_t, pos_t> findRange(Splay *r, val_t v, val_t &sb){
    pos_t a, base=0; 
    Splay *t = r;
    r = findVal(r, v, &base);
    pair<int, int> duo(base,base+1);
    if (r == 0) {
        if (base >= t->cnt){
            sb = -1;
        } else {
            r = findPos(t,  base);
            if (r)
                sb = r->val;
            else 
                sb = -1;
        }
        return duo;
    }

    t = r->left;
    a = base;
    while(t){
        if (t->val == v){
            t = t->left;
        } else {
            a += getLcnt(t) + 1;
            t = t->right;
        }
    }
    duo.first = a;

    t = r->right;
    a = base + getLcnt(r) + 1;
    while(t){
        if (t->val == v){
            a += getLcnt(t) + 1;
            t = t->right;
        } else {
            t = t->left;
        }
    }
    duo.second = a;
    sb = -1;
    return duo;
}

struct Seg{
    int a,b;
    Splay *st;
    Seg *l,*r;

  public:
    static Seg *next;
    static void putNode(Seg *t){
        memset(t, 0, sizeof(*t));
        t->l = next;
        next = t;
    }
    static Seg *getNode(){
        if (next == 0){
            next = (Seg*)malloc(sizeof(Seg)*INCSIZ);
            for (int i=0; i<INCSIZ; ++i){
                next[i].l = &next[i+1];
            }
            next[INCSIZ-1].l = 0;
        }
        Seg * t = next; next = next->l;
        memset(t, 0, sizeof(*t));
        return t;
    }
    static void clear(Seg *t){
        if (t->l) clear(t->l);
        if (t->r) clear(t->r);
        Splay::clear(t->st);
        putNode(t);
    }
};
Seg * Seg::next = 0;

pair<int,int> calcSeg(Seg *t, int v, int &sb, pair<int,int>& que){
    pair<int, int> res, tmp;
    if (t->a>=que.first&&t->b<=que.second){
        res = findRange(t->st, v, sb);
        return res;
    }
    int m = (t->a+t->b)/2;
    if (que.first >=m ){
        res = calcSeg(t->r, v, sb, que);
    } else if(que.second <= m){
        res = calcSeg(t->l, v, sb, que);
    } else {
        int nv;
        res = calcSeg(t->r, v, sb, que);
        tmp = calcSeg(t->l, v, nv, que);
        res.first += tmp.first;
        res.second += tmp.second -1;
        if (sb==-1) sb = nv;
        else if (nv!=-1 && nv < sb) sb = nv;
    }
    return res;
}

void inline makeSure(Seg*&t, int a, int b){
    if (t == 0){
        t = Seg::getNode();
        t->a = a; t->b = b;
    }
}

void removeSeg(Seg*t, int p, int v){
    Splay *s;
    pos_t lp = 0;
    while(t->a + 1 != t->b){
        t->st = removeVal(t->st, v);
        int m = (t->a + t->b)/2;
        if (p >= m){ // right
            makeSure(t->r, m, t->b);
            t = t->r;
        } else { // left
            makeSure(t->l, t->a, m);
            t = t->l;
        }
    }
    t->st = removeVal(t->st, v);
}

void addSeg(Seg *t, int p, int v){
    while(t->a + 1 != t->b){
        t->st = insertVal(t->st, v);
        int m = (t->a + t->b)/2;
        if (p >= m){ // right
            makeSure(t->r, m, t->b);
            t = t->r;
        } else { // left
            makeSure(t->l, t->a, m);
            t = t->l;
        }
    }
    t->st = insertVal(t->st, v);
}

Seg *head;
int N, M;

int Query(pair<int,int> que, int pos){
    int l=minVal, h=maxVal+1, m, sb;
    pair<int, int> res; 
    while(l < h){
        m = (l+h)/2;
        res = calcSeg(head, m, sb, que);
        if (pos < res.first){
            h = m - 1;
        } else if (pos >= res.second){
            l = m + 1;
        } else if (sb == -1){
            return m;
        } else {
            res = calcSeg(head, sb, m, que);
            if (pos < res.first){
                h = min(h, sb) - 1;
            } else if(pos>=res.second){
                l = max(sb, l) + 1;
            } else {
                return sb;
            }
        }
    }
    res = calcSeg(head, l, sb, que);
    if (pos < res.first){
        --l;
    }
    return l;
}

void fun(){
    char op;
    int pos;
    pair<int,int> duo;
    int cnt = 0;
    
    while(M--){
        scanf(" %c ", &op);
        if (op == 'C'){
            scanf("%d%d", &duo.first, &duo.second);
            // printf("%c %d %d\n", op, duo.first, duo.second);
            --duo.first;
            removeSeg(head, duo.first, dat[duo.first]);
            dat[duo.first] = duo.second;
            addSeg(head, duo.first, duo.second);
            if (minVal > duo.second) minVal = duo.second;
            if (maxVal < duo.second) maxVal = duo.second;
        } else {
            scanf("%d%d%d", &duo.first, &duo.second, &pos);
            // printf("%c %d %d %d\n", op, duo.first, duo.second, pos);
            --duo.first;
            --pos;
            ++cnt;
            int v = Query(duo, pos);
            printf("%d\n", v);
        }
    }
}

void readIn(){
    scanf("%d%d",&N,&M);
    if (head){
        Seg::clear(head);
    }
    head = Seg::getNode();
    head->a = 0; head->b = N;

    minVal = 1000000000;
    maxVal = 0;
    int i;
    for (i=0; i<N; ++i){
        scanf("%d",&dat[i]);
        if (dat[i] < minVal) minVal = dat[i];
        if (dat[i] > maxVal) maxVal = dat[i];
        addSeg(head, i, dat[i]);
    }
}

int main(){
    int tst;
    scanf("%d",&tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0;
}

