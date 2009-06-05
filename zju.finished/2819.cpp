#include<iostream>
#include<cmath>
using namespace std;
const double eps = 0.00000001;
struct Vec{
    double d[3];
    double dist()const{
        return sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);
    }
    double angle(const Vec& v)const{
        double t = d[0]*v.d[0] + d[1]*v.d[1] + d[2]*v.d[2];
        t /= dist();
        t /= v.dist();
        t = acos(t);
        return t;
    }
    void read(){
        scanf("%lf%lf%lf", &d[0], &d[1], &d[2]);
    }
};
struct Tele {
    Vec v;
    double ang;
    bool inside(const Vec&o)const{
        return v.angle(o) < ang + eps;
    }
    void read(){
        v.read();
        scanf("%lf", &ang);
    }
};
int sn, tn;
Vec star[502];
Tele tele[50];

void fun(){
    int cnt = 0, i, j;
    for(i=0; i<sn; i++){
        for(j=0; j<tn; j++){
            if(tele[j].inside(star[i])){
                ++cnt;
                break;
            }
        }
    }
    printf("%d\n", cnt);
}
int readIn(){
    scanf("%d", &sn);
    if(sn == 0) return 0;
    int i;
    for(i=0; i<sn; i++){
        star[i].read();
    }
    scanf("%d", &tn);
    for(i=0; i<tn; i++){
        tele[i].read();
    }
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

