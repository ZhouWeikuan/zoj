#include<iostream>
#include<cmath>
using namespace std;
// 横向递增1,纵向递增2
// 左上右下运动时， ax + ay = ax' + ay'
// 左下右上运动时， ay'- ay = ax' - ax 
// 先将与原点平行的，再计算是否要偏移
int ax, ay, bx, by;
double len, dis, ran;

void fun(){
    if(ax == bx){ // 同列
        if(ay != by){
            dis += abs(by - ay) * ran;
        }
        return;
    }
    int t, x, y;
    if(ax > bx){
        t = ax, ax = bx, bx = t;
        t = ay, ay = by, by = t;
    }
    if(ay >= by){ // b 左上运动，
        y = bx + by - ax;
        if(ay >= y){ // a右下运动
            dis += ran * (ay - y + bx - ax);
        } else { // a右上运动
            dis += ran * (bx - ax);
        }
    } else { // b 左下运动
        y = ax - bx + by;
        if(ay <= y){ // a右下运动
            dis += ran * (y - ay + bx - ax);
        } else { // a右上运动
            dis += ran * (bx - ax);
        }
    }
}
inline double dist(double x, double y, double a, double b){
    return sqrt((a-x)*(a-x) + (b-y)*(b-y));
}

inline int adjust(int v){ //        [-2 -1) [0 1) [2 3) 4
    if(v % 2 != 0){
        v += (v > 0);
        v -= (v < 0);
    }
    return v;
}
double locate(int &x, int &y, double ox, double oy){
    double cx, cy, ret;
    int nx, ny;

    ny = adjust(int(oy / len));
    nx = adjust(int(ox /(1.5)/len)); 
    cx = nx * 1.5 * len;
    cy = ny * ran / 2;
    ret = dist(cx, cy, ox, oy);
    x = nx, y = ny;
    if(ox > cx){
        nx = x + 1;
    } else { // ox < cx;
        nx = x - 1;
    }
    if(oy > cy){
        ny = y + 1;
    } else {
        ny = y - 1;
    }
    cy = ny * ran / 2;
    cx = nx * 1.5 * len;
    cx = dist(cx, cy, ox, oy);
    if(cx < ret){
        ret = cx;
        x = nx;
        y = ny;
    }

    return ret;
}
int readIn(){
    double a,b,c,d;
    scanf("%lf%lf%lf%lf%lf", &len, &a, &b, &c, &d);
    if(a==0&&b==0&&c==0&&d==0&&len==0) return 0;
    dis = 0;
    ran = len * sqrt(3.0);
    dis += locate(ax, ay, a, b);
    dis += locate(bx, by, c, d);
    if(ax == bx && ay == by){
        dis = dist(a, b, c, d);
    }
    return 1;
}
int main(){

    while(readIn() > 0){
        fun();
        printf("%.3lf\n", dis);
    }
    return 0;
}

