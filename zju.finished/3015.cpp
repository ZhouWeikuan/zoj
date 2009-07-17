#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
};

const double eps = 1e-7;
double k,h,a,b;
double PI = acos(-1.0);

void fun(){
    double o = k*PI/180.0;
    double l = h/tan(o) - b;
    double y = sin(2*o)*l;
    double x = l+b-cos(2*o)*l;
    l = sqrt((y-a)*(y-a) + x*x);
    cout<<fixed<<setprecision(2)<<l<<endl;
}

int main(){

    while(cin>>k>>h>>a>>b){
        fun();
    }

    return 0;
}

