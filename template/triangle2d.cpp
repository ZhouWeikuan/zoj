#include<iostream>
#include<cmath>
using namespace std;

struct Point {
    double x, y;
};
Point tri[3];
const double eps = 1e-7;
double PI = acos(-1.0);

double dis(Point &p, Point &q){
    double r = (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
    r = sqrt(r);
    return r;
}

bool cocircle(Point &p1, Point &p2,Point &p3,Point &q,double &r)
{
    double x12=p2.x-p1.x;
    double y12=p2.y-p1.y;
    double x13=p3.x-p1.x;
    double y13=p3.y-p1.y;
    double z2=x12*(p1.x+p2.x)+y12*(p1.y+p2.y);
    double z3=x13*(p1.x+p3.x)+y13*(p1.y+p3.y);
    double d=2.0*(x12*(p3.y-p2.y)-y12*(p3.x-p2.x));
    if(abs(d) < eps) 
          return false;
    q.x=(y13*z2-y12*z3)/d;
    q.y=(x12*z3-x13*z2)/d;
    r=dis(p1,q);
    return true;
}


