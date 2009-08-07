#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 1004,
};

struct Point {
    double x,y; // x-> longitude, y->latitude
    double dis(const Point &o)const {
        double v = cos(o.y)*cos(y)*cos(x-o.x) + sin(y)*sin(o.y);
        v = acos(v);
        return v;
    }
};

const double eps = 1e-4;
double PI = acos(-1.0);
int num;
Point tree[SIZ];

void fun(){
    int p = 0, i, j;
    double v = 1e8, nv;
    for (i=0; i<num; ++i){
        double mv = 0;
        for (j=0; j<num; ++j){
            if (i==j) continue;
            nv = tree[i].dis(tree[j]);
            if (mv < nv) mv = nv;
        }
        if (mv < v){
            v = mv;
            p = i;
        }
    }
    tree[p].x *= 180/PI;
    tree[p].y *= 180/PI;
    printf("%.2lf %.2lf\n", tree[p].y, tree[p].x);
}

int readIn(){
    if (scanf("%d",&num)<0) return 0;
    for (int i=0; i<num; ++i){
        scanf("%lf%lf", &tree[i].y, &tree[i].x);
        tree[i].y *= PI/180;
        tree[i].x *= PI/180;
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

