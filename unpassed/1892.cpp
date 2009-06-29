#include<iostream>
#include<cmath>
using namespace std;
double x[3], y[3];
double d;

double dis(double x0, double y0, double x1, double y1){
    x0 = (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0);
    x0 = sqrt(x0);
    return x0;
}

void fun(){
    double a, b, c;
    a = dis(x[0],y[0], x[1], y[1]);
    b = dis(x[0],y[0], x[2], y[2]);
    c = dis(x[2],y[2], x[1], y[1]);
    d = (x[2]-x[0])*(y[1]-y[0]) + (y[2]-y[0])*(x[1]-x[0]);
    d = a*b*c/d;
    d *= d;
    printf("%.3lf\n", d);
}

int readIn(){
    int n;
    scanf("%d ", &n);
    if (n == 0) return 0;
    for (n=0; n<3; n++){
        scanf("%lf%lf ", &x[n], &y[n]);
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

