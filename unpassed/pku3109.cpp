#include<iostream>
#include<algorithm>
using namespace std;
// untested!
enum {
    SIZ = 100004,
    MAX = 1000000008,
    //MAX = 3,
    MIN = -MAX,
    NUM = SIZ * 4,
    EVENUM = SIZ * 3,
    Enter = 0,
    Oper  = 1,
    Exit  = 2,
};
struct Seg {
    int a,b, lc,rc;
    Seg *l,*r;
};
Seg tree[NUM];
Seg *next, *head;
struct Point {
    int x,y;
    struct cmp_x{
        bool operator()(const Point&a, const Point&b)const{
            if(a.x != b.x)
                return a.x<b.x;
            return a.y<b.y;
        }
    };
    struct cmp_y{
        bool operator()(const Point&a, const Point&b)const{
            if(a.y!=b.y)
                return a.y<b.y;
            return a.x<b.x;
        }
    };
};
struct Event {
    int flag; // 0, enter, 1 exit, 2,operate
    int y;
    int d[2];
    struct cmp{
        bool operator()(const Event&a, const Event&b)const{
            if(a.y!=b.y)
                return a.y<b.y;
            return a.flag<b.flag;
        }
    };
};
Point dot[SIZ];
Event eve[EVENUM];
int en; // event num

void putNode(Seg *t){
    t->l = next;
    next = t;
}
Seg *getNode(){
    Seg * t = next; 
    next = next->l;
    memset(t, 0, sizeof(*t));
    return t;
}
inline Seg * allocNode(int s, int e){
    Seg *t = getNode();
    t->a = s, t->b = e;
    return t;
}
void initHead(){
    head = allocNode(MIN, MAX);
}
void FreeAll(Seg *t){
    if(t->l) FreeAll(t->l);
    if(t->r) FreeAll(t->r);
    putNode(t);
}
void init(){
    head = next = 0;
    for(int i=NUM-1;i>=0;i--){
        tree[i].l = next;
        next = &tree[i];
    }
}
int countFrom(Seg *t, int v){
    if(t==0){
        return 0;
    } else if(t->b-t->a==1){
        return 1;
    }
    if(v<(t->b+t->a)/2){
        return t->rc+countFrom(t->l,v);
    } else {
        return countFrom(t->r,v);
    }
}
int countTo(Seg *t, int v){
    if(t==0){
        return 0;
    } else if(t->b-t->a==1){
        return 1;
    }
    if(v>=(t->b+t->a)/2){
        return t->lc + countTo(t->r,v);
    } else {
        return countTo(t->l,v);
    }
}
// count the number of dots in range [s,e]
int countRange(Seg *t, int s, int e){
    if(t==0){
        return 0;
    } else if(t->b -t->a == 1){
        return 1;
    }
    if(s >= (t->a+t->b)/2){
        return countRange(t->r, s, e);
    } else if(e <(t->a+t->b)/2){
        return countRange(t->l, s,e);
    }
    return countFrom(t->l, s) + countTo(t->r, e);
}
void add(Seg *t, int v){
    if(t->b - t->a == 1){
        t->lc++;
        return;
    }
    int m = (t->a+t->b)/2;
    if(v>=m){
        t->rc++;
        if(t->r ==0)
            t->r = allocNode(m, t->b);
        add(t->r, v);
    } else { // v<m
        t->lc++;
        if(t->l==0)
            t->l = allocNode(t->a, m);
        add(t->l, v);
    }
}
// delete v from tree t, make sure the v exists in the tree.
int del(Seg *t, int v){
    if(t->b-t->a==1){
        t->lc--;
        return 1;
    }
    int ret = 0;
    if(v>=(t->b+t->a)/2){
        if(t->r != 0) {
            ret = del(t->r,v);
            t->rc -= ret;
            if(t->rc ==0){
                putNode(t->r);
                t->r = 0;
            }
        }
    } else {
        if(t->l != 0) {
            ret = del(t->l,v);
            t->lc -= ret;
            if(t->lc ==0){
                putNode(t->l);
                t->l = 0;
            }
        }
    }
    return ret;
}
int readIn(){
    int n,i,a,b;
    if(scanf("%d",&n)<=0)
        return 0;
    for(i=0;i<n;i++){
        scanf("%d%d",&dot[i].x,&dot[i].y);
    }
    sort(dot, dot+n, Point::cmp_x());
    en = 0;
    a = 0;
    while(a<n){
        b = a+1;
        while(b<n&&dot[b].x==dot[a].x){
            b++;
        }
        b--;
        eve[en].y    = dot[a].y;
        eve[en].d[0] = dot[a].x;
        eve[en++].flag = Enter;

        eve[en].y    = dot[b].y;
        eve[en].d[0] = dot[b].x;
        eve[en++].flag = Exit;

        a = b+1;
    }
    sort(dot, dot+n, Point::cmp_y());
    a=0;
    while(a<n){
        b = a+1;
        while(b<n&&dot[b].y==dot[a].y){
            b++;
        }
        b--;
        eve[en].y = dot[a].y;
        eve[en].flag = Oper;
        eve[en].d[0] = dot[a].x;
        eve[en++].d[1] = dot[b].x;
        a=b+1;
    }
    sort(eve, eve+en, Event::cmp());

    return 1;
}

void fun(){
    int res = 0;
    initHead();
    for(int i=0;i<en;i++){
        if(eve[i].flag == Enter){
            add(head, eve[i].d[0]);
        } else if(eve[i].flag == Exit){
            del(head, eve[i].d[0]);
        } else {
            res += countRange(head, eve[i].d[0], eve[i].d[1]);
        }
    }
    printf("%d\n",res);
    FreeAll(head);
    head = 0;
}

int main(){
    init();
    while(readIn()){
        fun();
    }

    return 0;
}
