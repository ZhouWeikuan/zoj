#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
};

//
// max(L) = D * h / H;
// max(L) = H*x/(D+x) + (D*h + x(h-H))/H, when x = H *sqrt(D/(H-h)) - D

double h, H, D;

void fun(){
    double L = max(D*h/H, h);
    double x = H*sqrt(D/(H-h))-D;
    if (x > 0){
        x = H*x/(D+x) + (D*h+x*(h-H))/H;
        L = max(L, x);
    }
    printf("%.3lf\n", L);
}

int main(){
    int tst;

    scanf("%d",&tst);
    while(tst-- > 0){
        scanf("%lf%lf%lf", &H, &h, &D);
        fun();
    }

    return 0;
}

