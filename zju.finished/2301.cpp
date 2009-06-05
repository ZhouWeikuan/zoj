#include<iostream>
using namespace std;
enum {
    SIZ = 2004,
    MIN = 0,
    MAX = 0x7fffffff,
    NUM = SIZ * 4,
    None  =-1,
    Black = 0,
    White = 1,
};
struct Seg{
    int a,b,c;
    Seg *l,*r;
};
struct Save {
    int a,b,c;
};
Seg tree[NUM];
Seg *next, *head, *pred;
int num, val, maxVal;
int start,end;
Save save[SIZ];

void putNode(Seg *t){
    t->l = next;
    next = t;
}
Seg *getNode(){
    Seg * t = next; next = next->l;
    memset(t, 0, sizeof(*t));
    return t;
}
void init(){
    next = pred = head =  0;
    for(int i=0;i<NUM;i++){
        tree[i].l = next;
        next = &tree[i];
    }
    head = getNode();
    head->a = MIN, head->b = MAX;
    head->c = None;
}
void countColor(Seg *t){
    if(t->l==0 && t->r==0){ // a node
        if(t->c == White){
            if(pred && (pred->c!=White || pred->b != t->a))
                val = 0;
            val += t->b - t->a;
            if(val > maxVal){
                maxVal = val;
                start = t->b - val;
                end = t->b;
            }
        }
        pred = t;
        return;
    }
    if(t->l)
        countColor(t->l);
    if(t->r)
        countColor(t->r);
}
// [s,e)
void add(Seg *t, int s,int e, int v){
    if(t->c!=-1)
        return;
    if(t->b-t->a==1){
        t->c = v;
        return;
    } else if(t->b==e && t->a == s){
        if(t->r ==0 && t->l==0){
            t->c = v;
            return;
        }
    }
    int m = (t->a+t->b)/2;
    if(s>=m){
        if(t->r == 0){
            Seg *p = getNode();
            p->a = m, p->b = t->b;
            p->c = -1;
            t->r = p;
        }
        return add(t->r, s, e, v);
    } else if(e<=m){
        if(t->l == 0){
            Seg *p = getNode();
            p->a = t->a, p->b = m;
            p->c = -1;
            t->l = p;
        }
        return add(t->l, s, e, v);
    }
    if(t->r == 0){
        Seg *p = getNode();
        p->a = m, p->b = t->b;
        p->c = -1;
        t->r = p;
    }
    if(t->l == 0){
        Seg *p = getNode();
        p->a = t->a, p->b = m;
        p->c = -1;
        t->l = p;
    }
    add(t->l, s, m, v);
    add(t->r, m, e, v);
}

int readIn(){
    if(scanf("%d",&num) <= 0)
        return 0;
    init();
    int i;
    char ch;
    for(i=0;i<num;i++){
        scanf("%d%d %c ",&save[i].a, &save[i].b, &ch);
        if(ch == 'w'){
            save[i].c = White;
        } else {
            save[i].c = Black;
        }
        save[i].b++;
    }
    for(i=num-1;i>=0;i--){
        add(head, save[i].a, save[i].b, save[i].c);
    }
    return 1;
}

void fun(){
    start = end = 0;
    maxVal = val = 0;
    countColor(head);

    if(maxVal <= 0){
        printf("Oh, my god\n");
    } else {
        printf("%d %d\n", start, end-1);
    }
}
int main(){

    while(readIn()){
        fun();
    }

    return 0;
}
