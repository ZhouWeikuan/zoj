#include<iostream>
#include<cmath>
// 内心公式是怎么来的呢？wondering..
using namespace std;
double Ax, Bx, Cx, Ay, By, Cy;
double x, y;
double a, b, c;

void fun(){
    a = sqrt((Bx-Cx)*(Bx-Cx)+(By-Cy)*(By-Cy));
    b = sqrt((Ax-Cx)*(Ax-Cx)+(Ay-Cy)*(Ay-Cy));
    c = sqrt((Bx-Ax)*(Bx-Ax)+(By-Ay)*(By-Ay));
    x = (a*Ax + b*Bx + c*Cx)/(a+b+c);
    x = int(10000*x)/10000.0;
    y = (a*Ay + b*By + c*Cy)/(a+b+c);
    y = int(10000*y)/10000.0;
}

int main(){
    int tst;
    scanf("%d",&tst);
    while(tst--){
        scanf("%lf,%lf", &Ax,&Ay);
        scanf("%lf,%lf", &Bx,&By);
        scanf("%lf,%lf", &Cx,&Cy);
        fun();
        printf("(%.0lf,%.0lf)(%.0lf,%.0lf)(%.0lf,%.0lf):(%.4lf,%.4lf)\n",
                Ax, Ay, Bx, By, Cx, Cy, x, y);
    }

    return 0;
}

