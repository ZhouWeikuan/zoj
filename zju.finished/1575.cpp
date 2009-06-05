#include<iostream>
using namespace std;
// 被精度处理搞了很多遍...
int lvl;
double d3;

void draw(double sx, double sy, double ex, double ey, int l){
    if(l == lvl){
        printf("%.2lf %.2lf\n", sx, sy);
        return;
    }
    double x1, y1;
    double x2, y2;
    x1 = (2*sx + ex)/3; y1 = (2*sy + ey)/3;
    draw(sx, sy, x1, y1, l+1);
    x2 = (sx*d3 + ex*d3 - ey + sy)/(2*d3);
    y2 = (sy*d3 + ey*d3 + ex - sx)/(2*d3);
    draw(x1, y1, x2, y2, l+1);
    x1 = (sx + 2*ex)/3, y1 = (sy + 2 * ey)/3;
    draw(x2, y2, x1, y1, l+1);
    draw(x1, y1, ex, ey, l+1);
}

int main(){
    double sx, sy;
    double ex, ey;

    sx =0, sy = 3.0, ex = 5e-16;
    while(sx + ex <= sy){
        d3 = (sx + sy)/2;
        if(d3*d3 > 3.0){
            sy = d3;
        } else {
            sx = d3;
        }
    }

    while(scanf("%d", &lvl) > 0){
        scanf("%lf%lf%lf%lf", &sx, &sy, &ex, &ey);
        draw(sx, sy, ex, ey, 0);
        printf("%.2lf %.2lf\n", ex, ey);
        printf("\n");
    }

    return 0;
}

