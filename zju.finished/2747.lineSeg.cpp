#include<iostream>
using namespace std;
// 未完成...
/*
 *  对于重复的，根据优先级和范围的不同可以分成四类
 *  1. 优先级高且范围大的， 抹去原有数据
 *  2. 优先级高且范围小的， 改为现有的，且加上新的矩形
 *  3. 优先级低且范围大的，加上新的矩形
 *  4. 优先级低且范围小的， 不作为
 *  要注意的是，防止因为矩形过多导致矩形都被拆得很开，结点数太多
 *  因此，要及时清除不须考虑的结点
 * */
enum {
    SIZ = 8004,
    MIN = 0,
    MAX = SIZ,
    NUM = SIZ *2,
    X = 0,
    Y = 1,
    Low = 0,
    High = 1,
};
struct Rect {
    int d[2][2];
    int color;
};
struct Seg{
    int a,b;
    Rect *rect;
    Seg *l,*r;
};
Seg tree[NUM];
Seg *next, *head, *pred;
int color[SIZ];
int maxVal, num;
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
    head->c = -1;
}
void countColor(Seg *t){
    if(t->l==0 && t->r==0){ // a node
        if(pred == NULL || pred->c!=t->c||pred->b!=t->a){
            color[t->c]++;
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
    maxVal = -1;
    if(scanf("%d",&num) <= 0)
        return 0;
    init();
    int i;
    for(i=0;i<num;i++){
        scanf("%d%d%d",&save[i].a, &save[i].b, &save[i].c);
        if(save[i].c>maxVal)
            maxVal = save[i].c;
    }
    for(i=num-1;i>=0;i--){
        add(head, save[i].a, save[i].b, save[i].c);
    }
    return 1;
}

void fun(){
    memset(color, 0, sizeof(color[0])*(maxVal + 1));
    pred = 0;
    countColor(head);
    for(int i=0;i<=maxVal;i++){
        if(color[i] ==0)
            continue;
        printf("%d %d\n", i, color[i]);
    }
    printf("\n");
}
int main(){

    while(readIn()){
        fun();
    }

    return 0;
}
