#include<iostream>
#include<cmath>

using namespace std;
int a,b,s,m,n;
double v[2] = {0};
double h[2] = {0};
const double PI = 3.1415927;

void fun(){
    double ox, oy;
    double x,y;
    ox = a; oy = b;
    x = ox /= 2; y = oy /= 2;
    v[1] = (double)a;
    h[1] = (double)b;
    int i = 1;
    while( m --){
        x = 2 * v[i] - x;
        i = 1 - i;
    }
    i = 1;
    while(n--){
        y = 2 * h[i] - y;
        i = 1 - i;
    }
    x -= ox;
    x /= s;
    y -= oy;
    y /= s;
    double vo = x * x + y * y;
    vo = sqrt(vo);
    if(y < 0)
        y = -y;
    y = y / vo;
    y = asin(y);
    y /= PI;
    y *= 180;
    printf("%.2lf %.2lf\n", y, vo);
}

int main(){
    
    cin>>a>>b>>s>>m>>n;
    while(a + b + s + m + n){
        fun();
        cin>>a>>b>>s>>m>>n;
    }

	return 0;
}
