#include<iostream>
#include<cmath>
// Wrong Answer
using namespace std;

double a,W,x,y,D,A;
double PI;

int fun(){
    A *= PI/180;
    double x1, x2;
    x1 = x - a;
    x2 = x + a;
    double t = (x1*x2+y*y)/sqrt(x1*x1+y*y)/sqrt(x2*x2+y*y);
    t = acos(t);
    t -= A;
    if(t <= 0) return 0;
    double n = 2 * D * tan(t/2);
    n /= W;
    int ret = (int)n;
    if(n - ret > 0.001){
        ret++;
    }
    return ret;
}

int main(){
    PI = asin(1.0)*2;

    while( scanf("%lf%lf%lf%lf%lf%lf",&a,&W,&x,&y,&D,&A) > 0){
        int t = fun();
        printf("%d\n", t);
    }

    return 0;
}

