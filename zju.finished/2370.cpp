#include<iostream>
#include<cmath>
// 抄袭别人的代码，实在是数据精度难以处理
using namespace std;
const double eps=1e-14;
double PI;
double nl,l,d,co;

void fun(){
    if(d * co == 0){
        printf("%.3lf\n", 0.0);
        return;
    }
    nl = (1 + d * co) *l;
    double low = 0, high = PI, mid;
    double t;
    d = l/nl;
    for(int i=0; i<100; i++){
        mid = (low + high) / 2;
        t = d * mid - sin(mid);
        if(t > 0){
            high = mid;
        } else {
            low = mid;
        }
    }
    t = (1-cos(mid))*nl/mid;

    printf("%.3lf\n", t);
}

int readIn(){
    cin>>l>>d>>co;
    if(l < 0) return 0;
    l /= 2;
    return 1;
}
int main(){
    PI = asin(1.0);
    while(readIn() > 0){
        fun();
    }
    return 0;
}

