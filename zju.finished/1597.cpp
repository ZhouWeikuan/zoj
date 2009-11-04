#include<iostream>
#include<cstdio>
#include<cmath>

/* copy from pku discuss due to hard to find a tool to draw geometry*/
using namespace std;
struct Circle{
    double x;
    double y;
    double r;
};
double dis;
const double PI = 3.14159265358;
Circle a,b; // assure a.r >= b.r;

void fun(){
    double t;
    double A,B;
    dis = a.x - b.x; t = a.y-b.y;
    dis = dis*dis + t *t;
    dis = sqrt(dis);
    if(dis >= a.r + b.r){ // no area shared
        t = 0;
        printf("%.3lf\n",t);
        return ;
    }else if( a.r >= dis + b.r){ // small circle is embraced.
        t = PI * b.r * b.r;
        printf("%.3lf\n",t);
        return ;
    }
    A = acos( (b.r*b.r + dis*dis - a.r*a.r)/2/b.r/dis);
    B = acos( (a.r*a.r+dis*dis-b.r*b.r)/2/a.r/dis);
    t = a.r + b.r + dis ;
    t /= 2;
    t = sqrt( t*(t-a.r)*(t-b.r)*(t-dis));
    t = a.r*a.r*B + b.r*b.r*A -2 * t;

    printf("%.3lf\n",t);
}

int main(){
    
    while(cin>>a.x>>a.y>>a.r>>b.x>>b.y>>b.r){
        if(a.r < b.r){
            dis = a.x ; a.x = b.x; b.x = dis;
            dis = a.y ; a.y = b.y; b.y = dis;
            dis = a.r ; a.r = b.r; b.r = dis;
        }
        fun();
    }

	return 0;
}
