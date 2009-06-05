#include<iostream>
using namespace std;
enum {
    SIZ = 10000,
};
struct Node {
    unsigned short a, b, v, f; // (a,b], v->least, f=1 all same
    Node *l, *r;
};
int num;
Node *head, *next;
Node *getNode(){
    Node *p;
    if(next == 0){
        p = (Node *)malloc(sizeof(Node)*SIZ);
        for(int i=0; i<SIZ; i++){
            p[i].l = &p[i+1];
        }
        p[SIZ-1].l = 0;
    } else {
        p = next;
    }
    next = p->l;
    p->l = p->r = 0;
    return p;
}
void putNode(Node *p){
    p->l = next; next = p;
}
void clear(Node *h){
    if(h->l){
        clear(h->l);
    }
    if(h->r) clear(h->r);
    putNode(h);
}

//[s, e]
unsigned short getMin(Node *h, int s, int e){
    if(h->f || (h->a+1==s && h->b==e)){
        return h->v;
    }
    int m = (h->a + h->b)/2;
    if(e <= m){
        return getMin(h->l, s, e);
    } else if(s>m){
        return getMin(h->r, s, e);
    }
    s = getMin(h->l, s, m);
    e = getMin(h->r, m+1, e);
    return min(s,e);
}

//[s, e]
unsigned short setMin(Node *h, int s, int e, int v){
    if(h->f){
        if(h->v <= v) return h->v;
        if(h->a+1==s && h->b==e){
            h->v = v;
            return v;
        }
    }
    int m = (h->a + h->b)/2;
    if(h->f){
        Node *p;
        h->f = 0;
        p = getNode();
        p->a = h->a, p->b = m; p->v = h->v; p->f = 1;
        h->l = p;
        p = getNode();
        p->a = m, p->b = h->b; p->v = h->v; p->f = 1;
        h->r = p;
    }
    if(e <= m){
        h->v = min(setMin(h->l, s, e, v), h->v);
    } else if(s > m){
        h->v = min(setMin(h->r, s, e, v), h->v);
    } else {
        h->v = min(setMin(h->l, s, m, v), h->v);
        h->v = min(setMin(h->r, m+1, e, v), h->v);
    }
    if(h->l->f && h->r->f && h->l->v == h->r->v){
        h->f = 1;
        clear(h->l);
        clear(h->r);
        h->l = h->r = 0;
    }
    return h->v;
}

void fun(){
    int s, e;
    unsigned short v;
    for(;num>0;num--){
        scanf("%d%d",&s,&e);
        v = getMin(head, s, e);
        if(v != (unsigned short)-1)
            setMin(head, s, e, v+1);
    }
    v = getMin(head, head->b, head->b);
    printf("%d\n", (int)v);
}

int readIn(){
    int v;
    if(scanf("%d%d",&v,&num)<0)
        return 0;
    head = getNode();
    head->a = 0, head->b = v;
    head->f = 1; head->v = -1;
    setMin(head, 1, 1, 0);
    return 1;
}
int main(){
    next = 0;
    while(readIn()>0){
        fun();
        clear(head);
    }
    return 0;
}

