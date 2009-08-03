#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
};

const double eps = 1e-8;
double PI = acos(-1.0);

double getDis(double x0, double y0, double x1, double y1){
    x0 -= x1; y0 -= y1;
    x1 = sqrt(x0 *x0 + y0 *y0);
    return x1;
}

struct Circle {
    double x, y, r;
    double interArea(const Circle &o) const;
};
double Circle::interArea(const Circle &o) const {
    double d = getDis(x, y, o.x,o.y);
    double r0 = min(r, o.r);
    double r1 = max(r, o.r);
    double ans0 = PI*r0*r0;
    double ans1 = PI*r1*r1;
    double ans = ans0 + ans1;

    if (d >= r + o.r) return 0.0;
    if (d <= eps + r1-r0) return ans0;

    double val = (r0*r0+d*d-r1*r1)/2/r0/d;
    double ang = acos(val);
    if (val > 0){
        ans -= (ans0*ang/PI - r0*r0*sin(ang*2)/2);
    } else {
        ans -= (ans0*ang/PI + r0*r0*sin((PI-ang)*2)/2);
    }
    val = (r1*r1+d*d-r0*r0)/2/r1/d;
    ang = acos(val);
    if (val > 0){
        ans -= (ans1*ang/PI - r1*r1*sin(ang*2)/2);
    } else {
        ans -= (ans1*ang/PI + r1*r1*sin((PI-ang)*2)/2);
    }
    ans = ans0 + ans1 - ans;

    return ans;
}

Circle c[3];

void fun(){
    double a0 = c[0].interArea(c[1]);
    double a1 = c[0].interArea(c[2]);
    a1 -= a0;
    if (fabs(a1) < eps) a1 = 0;
    printf("%.3lf\n", a1);
}

int readIn(){
    if (scanf("%lf%lf%lf", &c[0].x, &c[0].y, &c[0].r) < 0)
        return 0;
    scanf("%lf%lf%lf", &c[1].x, &c[1].y, &c[1].r);
    scanf("%lf", &c[2].r);
    c[2].x = c[1].x;
    c[2].y = c[1].y; 

    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

