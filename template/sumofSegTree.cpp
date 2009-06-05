#include<iostream>
using namespace std;
enum {
    SIZ = 200000,
    MAX = 30008,
    MIN = -MAX,
    NUM = SIZ,
};
typedef long long llong;
struct Seg{
    int a,b;
    llong sum;
    Seg *l,*r;
};
Seg tree[NUM];
int num,M;
Seg *next, *head;
bool first;
llong origSum;

void putNode(Seg *t){
    t->l = next;
    next = t;
}
Seg *getNode(){
    Seg * t = next; next = next->l;
    memset(t, 0, sizeof(*t));
    return t;
}
void initHead(){
    head = getNode();
    head->a = MIN, head->b = MAX;
    head->sum = 0;
}
void init(){
    next = head =  0;
    for(int i=0;i<NUM;i++){
        tree[i].l = next;
        next = &tree[i];
    }
}
void FreeAll(Seg *t){
    if(t->l)
        FreeAll(t->l);
    if(t->r)
        FreeAll(t->r);
    putNode(t);
}

inline Seg * allocNode(int s, int e){
    Seg *p = getNode();
    p->a = s, p->b = e;
    return p;
}
llong calc(Seg *t){
    return t==0?0:t->sum;
}
llong countFrom(Seg *t, int v){
    if(t==0){
        return 0;
    } else if(t->l == 0 && t->r ==0){ // leaf;
        llong tmp = t->sum;
        tmp /= (t->b -t->a);
        tmp *= (t->b - v);
        return tmp;
    }
    if(v<(t->b+t->a)/2){
        return calc(t->r)+countFrom(t->l,v);
    } else {
        return countFrom(t->r,v);
    }
}
llong countTo(Seg *t, int v){
    if(t==0){
        return 0;
    } else if(t->l == 0 && t->r ==0){ // leaf;
        llong tmp = t->sum;
        tmp /= (t->b -t->a);
        tmp *= (v-t->a);
        return tmp;
    }
    if(v>(t->b+t->a)/2){
        return calc(t->l) + countTo(t->r,v);
    } else {
        return countTo(t->l,v);
    }
}
// count the number of dots in range [s,e)
llong countRange(Seg *t, int s, int e){
    if(t==0){
        return 0;
    } else if(t->r==0 &&  t->l == 0){ // leaf
        llong tmp = t->sum;
        tmp /= (t->b-t->a);
        tmp *= (e -s);
        return tmp;
    }
    if(s >= (t->a+t->b)/2){
        return countRange(t->r, s, e);
    } else if(e <=(t->a+t->b)/2){
        return countRange(t->l, s,e);
    }
    return countFrom(t->l, s) + countTo(t->r, e);
}

// the range is [s,e)
llong updateRange(Seg *t, int s, int e, int v){
    if(t==0) return 0;
    if(e==t->b && s==t->a){ // overlap the node.
        if(t->r) FreeAll(t->r);
        if(t->l) FreeAll(t->l);
        t->r = t->l = 0;
        llong tmp = v; 
        tmp *= (e-s);
        llong ret = tmp - t->sum;
        t->sum = tmp;
        return ret;
    } else if(t->l==0&&t->r==0){ // we should split the orig node;
        int m = (t->b+t->a)/2;
        t->l=allocNode(t->a, m);
        t->r=allocNode(m,t->b);
        llong tmp = t->sum / (t->b-t->a);
        t->l->sum = tmp * (m - t->a);
        t->r->sum = tmp * (t->b - m);
    }
    llong var = 0;
    int m = (t->b + t->a)/2;
    if(s>=m){
        if(t->r ==0){
            t->r = allocNode(m, t->b);
        }
        var = updateRange(t->r, s, e, v);
        t->sum += var;
        return var;
    } else if(e<=m){
        if(t->l ==0)
            t->l = allocNode(t->a,m);
        var = updateRange(t->l, s, e, v);
        t->sum += var;
        return var;
    }
    if(t->l==0)
        t->l = allocNode(t->a,m);
    if(t->r==0)
        t->r = allocNode(m,t->b);
    var += updateRange(t->l, s, m, v);
    var += updateRange(t->r, m, e, v);
    t->sum += var;
    return var;
}

// [s,e)
void add(Seg *t, int s,int e, int v){
    if(t->b-t->a==1){
        t->sum = v;
        return;
    }
    t->sum += v * (e-s);
    int m = (t->a+t->b)/2;
    if(s>=m){
        if(t->r == 0){
            t->r = allocNode(m, t->b);
        }
        return add(t->r, s, e, v);
    } else if(e<=m){
        if(t->l == 0){
            t->l = allocNode(t->a,m);
        }
        return add(t->l, s, e, v);
    }
    if(t->r == 0){
        t->r = allocNode(m,t->b);
    }
    if(t->l == 0){
        t->l = allocNode(t->a,m);
    }
    add(t->l, s, m, v);
    add(t->r, m, e, v);
}

void operate(int s, int e){
    llong part = countRange(head,s,e);
    llong t = (e-s);
    if(part % t != 0){
        t = part / t;
        if(head->sum <= origSum){ // perform up...
            if(part >= 0) // positive
                t++;
        } else {
            if(part < 0){ // perform down...
                t--;
            }
        }
    } else {
        t = part / t;
    } 
    updateRange(head, s, e, (int)t);
}

void visit(Seg *t);
int readIn(){
    if(scanf("%d%d",&num,&M) <= 0)
        return 0;
    initHead();
    int i,t;
    origSum = 0;
    for(i=0;i<num;i++){
        scanf("%d",&t);
        add(head, i, i+1, t);
        origSum += t;
    }
    while(M--){
        scanf("%d%d",&i,&t);
        --i;
        operate(i,t); // range [i,t)
        //first = true;
        //visit(head);
        //printf("\n");
    }
    return 1;
}

void visit(Seg *t){
    if(t->a>=num)
        return;
    if(t->r ==0 && t->l ==0){
        int v = t->sum/(t->b-t->a);
        for(int i=t->a;i<t->b && i<num;i++){
            if(first){
                printf("%d", v);
                first = false;
            } else {
                printf(" %d", v);
            }
        }
    } else {
        if(t->l)
            visit(t->l);
        if(t->r)
            visit(t->r);
    }
}

void fun(){
    first = true;
    visit(head);
    printf("\n\n");
}
int main(){
    init();

    while(readIn()){
        fun();
        FreeAll(head);
    }

    return 0;
}
