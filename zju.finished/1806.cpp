#include<iostream>
#include<cmath>
using namespace std;

struct Point {
    double x, y;
};
int num;
Point pnt[10];
const double eps = 1e-7;
double PI = acos(-1.0);
double sum;

// calc the area of triangle (0, a, b)
double area(const Point &a, const Point &b){
    return (b.y*a.x - a.y*b.x)/2.0;
}

void fun(){
    int i;
    double diff, save;
    sum = 0;
    for (i=1; i<num; ++i){
        sum += area(pnt[i-1], pnt[i]);
    }
    sum += area(pnt[num-1], pnt[0]);
    diff = sum, save = sum;
    num *= 2;
    pnt[num] = pnt[0];
    for (i=num-2; i>0; i-=2){
        pnt[i] = pnt[i/2];
    }
    for (i=1; i<num; i+=2){
        pnt[i].x = (pnt[i-1].x + pnt[i+1].x)/2;
        pnt[i].y = (pnt[i-1].y + pnt[i+1].y)/2;
    }
    int j;
    for (i=0; i<num-1; ++i){
        double a = area(pnt[i], pnt[i+1]);
        for (j=i+2; j<num; ++j){
            a += area(pnt[j-1], pnt[j]);
            double as = a + area(pnt[j], pnt[i]);
            if (fabs(sum-2*as) < diff){
                diff = fabs(sum-2*as);
                save = as;
            }
        }
    }
    sum -= save;
    if (save > sum)
        swap(save, sum);
    static int tst=1;
    printf("Cake %d: %.3lf %.3lf\n", tst++, save, sum);
}

int readIn(){
    sum = 0;
    num = 4;
    for (int i=0; i<num; ++i){
        scanf("%lf%lf", &pnt[i].x, &pnt[i].y);
        sum += fabs(pnt[i].x);
        sum += fabs(pnt[i].y);
    }
    if (sum < eps) return 0;
    return 1;
}

int main(){

    while(readIn()>0){
        fun();
    }
    return 0;
}

