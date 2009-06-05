#include<iostream>
using namespace std;
enum {
    SIZ = 20000,
};

template<typename Obj>
class TAlloc {
    Obj *link;
    int augSize;
public:
    TAlloc(int size=100):link(0), augSize(size){};
    ~TAlloc();
    Obj * getSpace();
    void freeSpace(Obj *o);
};

template<typename Obj>
Obj *TAlloc::getSpace(){
    if (link == 0)
    {
        link = (Obj*)malloc(sizeof(Obj)*augSize);
        for(int i=0; i<augSize; i++){
            link[i].next = &link[i+1];
        }
        link[augSize-1].next = 0;
    }
    Obj * a = link;
    link = link->next;
    return a;
}
template<typename Obj>
void TAlloc::freeSpace(Obj *o){
    o->next = link;
    link = o;
}

struct Node {
    int n;
    int lx, ly, hx, hy;
    union {
        Node *ul, *ur, *dl, *dr;
        Node *next;
    }
};

TAlloc<Node> ta;
Node *head;
char buf[100];
int mx, my;

void free(Node *o){
    if (o->ul) free(o->ul);
    if (o->ur) free(o->ur);
    if (o->dl) free(o->dl);
    if (o->dr) free(o->dr);
    o->ul = o->ur = o->dl = o->dr = 0;
    ta.freeSpace(o);
}

void init(){
    if(head)
        free(&head);
    head = ta.getSpace();
    head->n = 0;
    head->lx = head->ly = 1;
    head->hx = head->hy = 20000;
    head->ul = head->ur = head->dl = head->dr = 0;
}

void inline makeSure(Node *&p, int lx, int hx, int ly, int hy){
    if (p == 0) p = ta.getSpace();
    memset(p, 0, sizeof(Node));
    p->lx = lx, p->hx = hx, p->ly = ly, p->hy = hy;
}

void putInto(Node *h, Node *o) {
    h->n += o->n;
    if(h->lx == h->hx && h->ly == h->hy){
        ta.freeSpace(o);
        return;
    }
    mx = (h->lx + h->hx)/2;
    my = (h->ly + h->hy)/2;
    if (o->ly <= my) { //d 
        if(o->lx <=mx){ // l
            makeSure(h->dl, h->lx, mx, h->ly, my);
            putInto(h->dl, o);
        } else {// r
            makeSure(h->dr, mx+1, h->hx, h->ly, my);
            putInto(h->dr, o);
        }
    } else { //u
        if(o->lx <=mx){ // l
            makeSure(h->ul, h->lx, mx, my+1, h->hy);
            putInto(h->ul, o);
        } else { // r
            makeSure(h->ur, mx+1, h->hx, my+1, h->hy);
            putInto(h->ur, o);
        }
    }
}

int calc(Node *h, Node *o) {
    if (h->lx == o->lx && h->hx == o->hx 
            && h->ly == o->ly && h->hy == o->hy )
    {
        o->n += h->n;
        return o->n;
    }

}

void Enter()
{
    if (buf[0] != 'I') return;
    fgets(buf, 100, stdin);
    while(buf[0] != 'Q'){
        Node *o = ta.getSpace();
        scanf("%d%d%d ", &o->lx, &o->ly, &o->n);
        o->hx = o->lx; o->hy = o->ly;
        putInto(head, o);
        fgets(buf, 100, stdin);
    }
}

void Query(){
    if (buf[0] != 'Q') return;
    fgets(buf, 100, stdin);
    while(isdigit(buf[0])){
        Node *o = ta.getSpace();
        scanf("%d%d%d%d ", &o->lx, &o->hx, &o->ly, &o->hy);
        o->n = 0;
        int t = calc(head, o);
        printf("%d\n", t);
        ta.freeSpace(o);
        fgets(buf, 100, stdin);
    }
}

int main(){

    fgets(buf, 100, stdin);
    while(buf[0] != 'E'){
        init();
        if(buf[0] == 'I'){
            Enter();
        }
        if(buf[0] == 'Q'){
            Query();
        }
    }

    return 0;
}

