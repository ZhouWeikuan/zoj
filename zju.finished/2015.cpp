#include<iostream>
#include<cmath>
using namespace std;

double eps = 1e-5;
double A, x, y;

void calc(double x1, double y1, double x2, double y2)
{
    double val = x1 * y2 - x2 * y1;
    A += val;
    x += val * (x1 + x2)/3;
    y += val * (y1 + y2)/3;
}

void fun(){
    int num;
    double x0, y0;
    double px, py, nx, ny;
    A = x = y = 0;
    scanf("%d ", &num);
    scanf("%lf%lf ", &x0, &y0);
    px = x0, py = y0;
    for(int i=1; i<num; i++){
        scanf("%lf%lf ", &nx, &ny);
        calc(px, py, nx, ny);
        px = nx, py = ny;
    }
    calc(nx, ny, x0, y0);
    x /= A, y /= A;
    x = round(1000.0*x)/1000.0, y = round(1000.0*y)/1000.0;
    if (fabs(x) < eps) x = 0;
    if (fabs(y) < eps) y = 0;
    printf("%.2lf %.2lf\n", x, y);
}

int main(){
    int tst;

    scanf("%d ", &tst);
    while(tst--){
        fun();
    }

    return 0;
}

