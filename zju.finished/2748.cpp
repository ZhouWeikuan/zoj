#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
};

double eps = 1e-12;
double PI = acos(-1.0);
double a, W, x, y, D, A;

double getSquare(double x0, double y0, double x1, double y1){
    return ((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}

int fun(){
    double e1 = getSquare(x, y, -a, 0);
    double e2 = getSquare(x, y, a, 0);
    double e = 2*a;
    e = e1 + e2 - e*e;
    e /= 2 * sqrt(e1*e2);
    e = acos(e);
    e -= A*PI/180;
    if (e <= eps){
        return 0;
    }
    e = 2 * D * tan(e/2);
    
    int num = e / W;
    if (e-W*num > eps)
        ++num;
    return num;
}

int main(){

    while(cin>>a>>W>>x>>y>>D>>A){
        cout<<fun()<<endl;
    }

    return 0;
}

