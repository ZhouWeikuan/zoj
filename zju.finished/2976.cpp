#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
};
struct Point {
    int x, y, z, I;
};
int num;
Point pnt[SIZ];
int X[2], Y[2];

double calc(int x, int y, const Point &p){
    double R = sqrt(0.0+(x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + p.z*p.z);
    double e = p.I * p.z / R;
    e /= R;
    e /= R;
    return e;
}

void fun(){
    double r = 0.0, t;
    for(int x=X[0]; x<=X[1]; ++x){
        for(int y=Y[0]; y<=Y[1]; ++y){
            t = 0.0;
            for(int i=0; i<num; ++i){
                t += calc(x, y, pnt[i]);
            }
            r = max(r, t);
        }
    }
    printf("%.2lf\n", r);
}

void readIn(){
    scanf("%d ", &num);
    for (int i=0; i<num; i++){
        scanf("%d%d%d%d ", &pnt[i].x,
                &pnt[i].y, &pnt[i].z, &pnt[i].I);
        if (i==0){
            X[0] = X[1] = pnt[i].x;
            Y[0] = Y[1] = pnt[i].y;
        } else {
            X[0] = min(pnt[i].x, X[0]); X[1] = max(pnt[i].x, X[1]);
            Y[0] = min(pnt[i].y, Y[0]); Y[1] = max(pnt[i].y, Y[1]);
        }
    }
}

int main(){
    int tst;

    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

