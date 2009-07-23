#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
using namespace std;
enum {
    NUM = 108,
};
double eps = 1e-7;
struct Rect {
    double v[4]; // 0->lx, 1->hx, 2->ly, 3->hy
};
Rect r[NUM];
struct Pair{
    Rect *r;
    int p;
    bool operator < (const Pair &rhs) const{
        if (fabs(r->v[p] - rhs.r->v[rhs.p]) < eps){
            if (p == rhs.p){
                return r < rhs.r;
            } else {
                return p < rhs.p;
            }
        }
        return r->v[p] < rhs.r->v[rhs.p];
    }
};
set<Pair> xs, ys;
int num;
double lastx;

int readIn(){
    scanf("%d ",&num);
    if (num <= 0) return 0;
    xs.clear(); ys.clear();
    double x, y, d;
    Pair o;
    for(int i=0;i<num;i++){
        scanf("%lf%lf%lf ", &x, &y, &d);
        r[i].v[0] = x-d;
        r[i].v[1] = x+d;
        r[i].v[2] = y-d;
        r[i].v[3] = y+d;
        o.r = &r[i];
        o.p = 0;
        xs.insert(o);
        o.p = 1;
        xs.insert(o);
    }

    return 1;
}

double area(){
    int d = 0;
    double lasty = 2000;
    double v = 0;
    for (set<Pair>::iterator it = ys.begin();
            it != ys.end(); ++it){

        v += d?(it->r->v[it->p] - lasty):0;
        if (it->p == 2){ // enter
            ++d;
        } else { //exit
            --d;
        }
        lasty = it->r->v[it->p];
    }

    return v;
}

void calc(){
    lastx = 2000;
    Pair o, nex;
    double sum = 0, v;
    set<Pair>::iterator iter;
    for(set<Pair>::iterator it = xs.begin();
            it!=xs.end(); ++it){
        o = *it;
        if (lastx > o.r->v[o.p])
            lastx = o.r->v[o.p];

        v = area();
        v *= o.r->v[o.p] - lastx;
        if(o.p == 0){ // enter
            nex.r = o.r;
            nex.p = 2;
            ys.insert(nex);
            nex.p = 3;
            ys.insert(nex);
        } else { // exit
            nex.r = o.r;
            nex.p = 2;
            ys.erase(nex);
            nex.p = 3;
            ys.erase(nex);
        }
        sum += v;
        lastx = o.r->v[o.p];
    }
    printf("%.2lf\n", sum);
}

int main(){
    int tst = 0;    
    while(readIn()){
        printf("%d ", ++tst);
        calc();
    }

    return 0;
}

