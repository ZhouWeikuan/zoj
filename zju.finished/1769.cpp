#include<iostream>
#include<cmath>
using namespace std;
double PI;
struct vec{
    double x, y;
    double dis;
    void set(double, double);
    bool operator<(const vec &rhs)const {
        return dis<rhs.dis;
    }
};
void vec::set(double x1, double y1){
    x = x1, y = y1;
    dis = sqrt(x*x + y*y);
}

vec a, b, c;
vec v[3];

int calc_side(){
    int t = 0;
    t += (v[1].dis - v[0].dis)< 0.01;
    t += (v[2].dis - v[1].dis)< 0.01;
    return t;
}
int calc_angl(){
    double t = v[0].x * v[1].x + v[0].y*v[1].y;
    t /= v[0].dis;
    t /= v[1].dis;
    t = PI - acos(t);
    t -= PI/2;
    if(t > 0.035){
        return 2;
    }
    t = fabs(t);
    if(t < 0.035){
        return 1;
    }
    return 0;
}
int fun(){
    if(v[0].dis + v[1].dis <= v[2].dis + 0.01){
        return -1;
    }
    return calc_side()*10 + calc_angl();
}
int readIn(){
    static char str[20];
    scanf("%s", str);
    if(strcmp(str,"-1") == 0) return 0;
    a.x = atof(str);
    scanf("%lf%lf%lf%lf%lf", &a.y, &b.x, &b.y, &c.x, &c.y);
    v[0].set(a.x-b.x, a.y-b.y);
    v[1].set(b.x-c.x, b.y-c.y);
    v[2].set(c.x-a.x, c.y-a.y);
    sort(v, v+3);
    return 1;
}
int main(){
    PI = asin(1.0)*2;
    const char *side[3] = {"Scalene", "Isosceles", "Equilateral"};
    const char *angl[3] = {"Acute", "Right", "Obtuse"};
    while(readIn() > 0){
        int t = fun();
        if(t < 0){
            printf("Not a Triangle\n");
        } else {
            printf("%s %s\n", side[t/10], angl[t%10] );
        }
    }
    printf("End of Output\n");
    return 0;
}

