#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
};
char buf[SIZ];
double sum;

void fun(){
    sum *= 6;
    sum /= 1000;
    int m = round(sum);
    int h = m / 60;
    m %= 60;
    printf("%d:%02d\n", h,m);
}

int readIn(){
    if (!cin.getline(buf, SIZ))
        return 0;
    double x0, x1, y0, y1;
    sum = 0;
    cin.getline(buf, SIZ);
    while (strcmp(buf, "java")!=0){
        sscanf(buf, "%lf%lf%lf%lf", &x0, &y0, &x1, &y1);
        double d = sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
        sum += d;
        cin.getline(buf, SIZ);
    }

    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

