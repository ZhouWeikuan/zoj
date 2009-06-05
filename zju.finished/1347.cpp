#include<iostream>
using namespace std;
// copy from others...
struct Node {
    double p, r, a;
};
Node best;
double n, m;
double p, r, s;

void fun(){
    double pri;
    double aud;
    double t = (p*n + m*s);
    pri = p * m;
    t = t/2/pri;
    int x = (int)t;
    best.r = 0;
    for(int i=x-10;i<=x+10;i++){
        pri = i*p - 0.01;
        aud = n - m *(i-1);
        t = (pri - s) * aud - r;
        if(t > best.r){
            best.r = t;
            best.p = pri;
            best.a = aud;
        }
    }
    printf("price = %.2lf\n", best.p);
    printf("audiences = %.0lf\n", best.a);
    printf("revenue = %.2lf\n", best.r);
}
int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase--){
        scanf("%lf%lf%lf%lf%lf",&n,&p,&m,&r,&s);
        fun();
        if(tstcase){
            printf("\n");
        }
    }
    return 0;
}

