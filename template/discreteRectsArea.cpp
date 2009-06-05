#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
enum {
    NUM = 108,
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
int width,height,num;
int color[NUM];
int lastx;

int readIn(){
    scanf("%d%d",&width,&height);
    if(width==0)
        return 0;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d%d%d%d%d", &r[i].lx,
                            &r[i].ly,
                            &r[i].hx,
                            &r[i].hy,
                            &r[i].c );
        r[i].ts = i;
        in[i] = &r[i];
    }
    inum = num, onum = 0;
    make_heap(in, in+inum, inCmp);

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
    int lasty=0;
    for(i=0;i<n;i++){
        if(pnt[i].v == pnt[i].r->ly){ // enter
            if(!s.empty()){
                it=s.end(); --it;
                color[r[*it].c]  += (pnt[i].v - lasty)*w;
            }
            s.insert(pnt[i].r->ts);
        } else { // exit
            if(!s.empty()){
                it=s.end(); --it;
                color[r[*it].c]  += (pnt[i].v - lasty)*w;
            }
            s.erase(pnt[i].r->ts);
        }
        lasty = pnt[i].v;
    }
}
void fun(){
    memset(color, 0, sizeof(color));
    lastx = 0;
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
    static int tstcase = 0;
    int cnt = 0;
    if(tstcase ++)
        printf("\n");
    printf("Case %d:\n", tstcase);
    for(int i=0;i<NUM;i++){
        if(color[i]<=0)
            continue;
        printf("%d %d\n", i, color[i]);
        cnt ++;
    }
    if(cnt==1){
        printf("There is 1 color left on the wall.\n");
    } else {
        printf("There are %d colors left on the wall.\n",cnt);
    }

}

int main(){
    
    while(readIn()){
        fun();
    }

    return 0;
}
