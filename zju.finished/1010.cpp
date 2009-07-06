#include<iostream>
#include<cmath>
// Wrong Answer.
using namespace std;
enum {
    SIZ = 1008,
};
const double eps = 1e-5;
struct Point {
    double x,y;
};
int n, vn;
Point p[SIZ];
double multiply(Point &s, Point &o, Point &e){
    return (o.x-s.x)*(e.y-o.y) - (o.y-s.y)*(e.x-o.x);
}
bool interseg(Point &a, Point &b, Point &c, Point &d)
{
    if ((min(a.x,b.x)>max(c.x,d.x)) ||
             (min(c.x,d.x)>max(a.x,b.x)) ||
             (min(a.y,b.y)>max(c.y,d.y)) ||
             (min(c.y,d.y)>max(a.y,b.y)))
        return false;
    if ((multiply(a,b,c)*multiply(a,b,d)>0) ||                
             (multiply(c,d,a)*multiply(c,d,b)>0))
        return false;
    return true;
}

bool samepoint(const Point &a, const Point&b){
    return fabs(b.x-a.x) < eps && fabs(b.y-a.y) < eps;
}

int readIn(){
    if(scanf("%d",&n)<=0 || n <= 0)
        return 0;
    int j = 0;
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&p[j].x,&p[j].y);
        if (j==0 || !samepoint(p[j-1], p[j]))
            ++j;
    }
    vn = j;
    return 1;
}
inline double calc(Point &s, Point &e){
    double ret;
    ret = s.x * e.y - s.y*e.x;
    ret /= 2;
    return ret;
}
int fun(){
    if(n < 3 || vn != n){
        return -1;
    }

    double area = 0, t;
    for(int i=0;i<n-1;i++){
        for(int j=i+2;j<n-1;j++){
            if(interseg(p[i], p[i+1], p[j], p[(j+1)])){
                return -1;
            }
        }
    }
    for(int i=1;i<n-2;i++){
        if(interseg(p[n-1],p[0], p[i], p[i+1])){
            return -1;
        }
    }
    for(int i=0;i<n-1;i++){
        t = calc(p[i], p[i+1]);
        area += t;
    }
    t = calc(p[n-1], p[0]);
    area += t;

    if (area < eps)
        area = fabs(area);
    printf("%.2lf\n", area);

    return 0;
}

int main(){
    int tst = 0;

    while(readIn() > 0){
        if (tst)
            printf("\n");
        printf("Figure %d: ", ++tst);
        if (fun() < 0)
            printf("Impossible\n");
    }
    return 0;
}
