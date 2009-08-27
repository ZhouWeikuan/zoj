#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

void fun(){

    //Altitude of peak 6 =  354.0
    //Pipeline length    = 1259.1
}

void format(double s){
    static char buf[20];
    sprintf(buf, "%4.1lf", s);
    int len = strlen(buf);
    while(len < 6){
        printf(" ");
        ++len;
    }
    printf("%s\n", buf);
}
int run(){
    double a, d, h;
    double sum = 0;
    char ch;
    if (scanf("%lf%c",&a,&ch)<0) return 0;
    printf("\n");
    h = 0;
    int tn = 1;
    while(ch != '\n'){
        a *= M_PI/180.0;
        scanf("%lf", &d);
        sum += d*cos(a);
        h += d * sin(a);
        printf("Altitude of peak %d = ", tn++);
        format(h);
        scanf("%lf%c",&a,&ch);
    }
    a *= M_PI/180.0;
    sum += h / tan(fabs(a));
    printf("Pipeline length    = ");
    format(sum);

    return 1;
}

int main(){
   /* 
    double a = 1.2;
    double b = 20.3;
    printf("= %4.1lf\n", a);
    printf("= %4.1lf\n", b);
    return 0;
    */
    printf("Problem 6 by team x\n");
    while(run() > 0){
        ;
    }
    printf("End of problem 6 by team x\n");

    return 0;
}

