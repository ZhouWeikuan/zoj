#include<iostream>
#include<cmath>
using namespace std;
/*
 *  多边形边长为1，根据边角正弦相对，计算出各点到多边形中心的距离
 *  将各顶点行走方向分解，计算出向心与行走长度比率，最后得到行走路径总长度。
 *  要注意地是，为了减少计算精度误差，最后用cos2x代替了1- 2sin^2x
 */
double pi;
int main(){
    pi = 1.0;
    pi = 2 * asin(pi);
    int n ;
    double d;
    int t;
    scanf("%d",&t);

    while(t --){
        scanf("%d", &n);
        d = 1.0 - cos(2*pi/n);
        d = 1 / d;
        printf("%.3lf\n", d);
    }

    return 0;
}

