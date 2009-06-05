#include<iostream>
#include<vector>
#include<queue>
#include<set>
// 离散化TLE 
using namespace std;
enum {
    NUM = 1008,
};
struct Rect {
    int lx,hx;
    int ly,hy;
    int ts, c;
    struct in_cmp{
        bool operator()(Rect* &l,Rect* &r) const{
            return l->lx>r->lx;
        }
    };
    struct out_cmp{
        bool operator()(Rect* &l,Rect* &r) const{
            return l->hx>r->hx;
        }
    };
};
Rect::in_cmp inCmp;
Rect::out_cmp outCmp;
Rect r[NUM];
struct Pair{
    Rect *r;
    int v;
    bool operator < (const Pair &rhs) const{
        return v<rhs.v;
    }
};
Rect *in[NUM], *out[NUM];
Pair pnt[NUM * 2];
int inum,onum;
int num, color;
int lastx, area;

int readIn(){
    scanf("%d%d",&num,&color);
    if(num == 0)
        return 0;
    for(int i=0;i<num;i++){
        scanf("%d%d%d%d%d", &r[i].c,
                            &r[i].lx,
                            &r[i].ly,
                            &r[i].hx,
                            &r[i].hy);
        if(r[i].lx > r[i].hx){
            int t = r[i].lx; r[i].lx = r[i].hx; r[i].hx = t;
        }
        if(r[i].ly > r[i].hy){
            int t = r[i].ly; r[i].ly = r[i].hy; r[i].hy = t;
        }
        r[i].ts = i;
        in[i] = &r[i];
    }
    inum = num, onum = 0;
    make_heap(in, in+inum, inCmp);
    area = 0;
    return 1;
}
void calc(int w){
    set<int> s;
    set<int>::iterator it;
    int i, n = 0;
    for(i=0;i<onum;i++){
        pnt[n].r = out[i];
        pnt[n].v = out[i]->ly;
        n++;
        pnt[n].r = out[i];
        pnt[n].v = out[i]->hy;
        n++;
    }
    sort(pnt, pnt+n);
    int lasty=-1000;
    for(i=0;i<n;i++){
        if(pnt[i].v == pnt[i].r->ly){ // enter
            if(!s.empty()){
                it=s.end(); --it;
                if(r[*it].c == color)
                    area  += (pnt[i].v - lasty)*w;
            }
            s.insert(pnt[i].r->ts);
        } else { // exit
            if(!s.empty()){
                it=s.end(); --it;
                if(r[*it].c == color)
                    area  += (pnt[i].v - lasty)*w;
            }
            s.erase(pnt[i].r->ts);
        }
        lasty = pnt[i].v;
    }
}
void fun(){
    lastx = -1000;
    Rect *p;
    while(inum || onum){
        if(inum == 0 || (onum && out[0]->hx <= in[0]->lx)){ // pop one from out
            calc(out[0]->hx - lastx);
            lastx = out[0]->hx;
            //printf("Exiting %d -> %d\n", out[0]->hx, out[0]->ts);
            pop_heap(out, out + onum, outCmp);
            onum --;
        } else { // pop one from in and push it into out
            p = in[0];
            calc(p->lx - lastx);
            lastx = p->lx;
            pop_heap(in, in + inum, inCmp);
            inum--;
            out[onum] = p;
            //printf("Entering %d -> %d\n", p->lx, p->ts);
            onum++;
            push_heap(out, out + onum, outCmp);
        }
    }
    static int tstcase = 1;
    printf("The area of color %d in dataset %d is: %d\n",
            color, tstcase++, area);
}

int main(){
    
    while(readIn()){
        fun();
    }

    return 0;
}

