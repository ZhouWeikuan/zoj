#include<iostream>
// Wrong Answer.
using namespace std;
enum {
    SIZ = 1008,
};
struct Point {
    double v[2];
};
int n, flag;
Point p[SIZ];
double multiply(Point &s, Point &e, Point &o){
    return (s.v[0] - o.v[0])*(e.v[1] - o.v[1]) 
        -  (s.v[1]-o.v[1])*(e.v[0]-o.v[0]);
}
bool interseg(Point &a, Point &b, Point &c, Point &d)
{
    return
        //排斥实验
        (    (max(a.v[0],b.v[0])>=min(c.v[0],d.v[0]))&&                        
             (max(c.v[0],d.v[0])>=min(a.v[0],b.v[0]))&&
             (max(a.v[1],b.v[1])>=min(c.v[1],d.v[1]))&&
             (max(c.v[1],d.v[1])>=min(a.v[1],b.v[1]))&&
        //跨立实验
             (multiply(c,b,a)*multiply(b,d,a)>=0)&&                 
             (multiply(a,d,c)*multiply(d,b,c)>=0));
}

int readIn(){
    if(scanf("%d",&n)<=0 || n <= 0)
        return 0;
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&p[i].v[0],&p[i].v[1]);
    }
    return 1;
}
inline double calc(Point &a, Point &b, Point &c){
    double ret;
    for(int i=0;i<2;i++){
        b.v[i] -= a.v[i];
        c.v[i] -= a.v[i];
    }
    ret = b.v[0] * c.v[1] - b.v[1]*c.v[0];
    ret /= 2;
    if(ret < 0)
        ret = - ret;
    return ret;
}
void fun(){
    static int tstcase = 0;
    double area = 0, t;
    if(n < 3){
        area = -1;
    } else {
        for(int i=0;i<n-1;i++){
            for(int j=i+2;j<n-2;j++){
                if(interseg(p[i], p[i+1], p[j], p[(j+1)])){
                    area = -1; break;
                }
            }
        }
        for(int i=1;i<n-2;i++){
            if(interseg(p[0],p[n-1], p[i], p[i+1])){
                area = -1; break;
            }
        }
        if(area >= 0){
            for(int i=1;i<n-1;i++){
                t = calc(p[0], p[i], p[i+1]);
                area += t;
            }
        }
    }
    printf("Figure %d: ", ++tstcase);
    if(area >= 0){
        printf("%.2lf\n", area);
    } else {
        printf("Impossible\n");
    }
}

int main(){

    while(readIn() > 0){
        fun();
    }
    return 0;
}
