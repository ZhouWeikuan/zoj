#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
enum {
    SIZ = 54,
};

const double eps = 1.0e-5;

struct Point {
    int no;
    double x, y;
};

Point pnt[SIZ];
int num;
vector<int> res;
double ang;

double dis2(const Point &a, const Point &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

double angle(const Point &pa, const Point &po, const Point &pb){
    double a2 = dis2(pa, po);
    double b2 = dis2(po, pb);
    double c2 = dis2(pa, pb);
    c2 = (a2 + b2 - c2)/2;
    a2 = sqrt(a2*b2);
    c2 /= a2;
    c2 = acos(c2);
    return c2;
}

int choose(const Point &a, const Point &b){
    double ta;
    int p = 0;
    ang = angle(a, b, pnt[0]);
    for (int i=1; i<num; ++i){
        ta = angle(a, b, pnt[i]);
        if (fabs(ta-ang) < eps){
            double dp = sqrt(dis2(b, pnt[p]));
            double di = sqrt(dis2(b, pnt[i]));
            if (di < dp){
                p = i; ang = ta;
            }
        } else if (ta > ang){
            ang = ta; p = i;
        }
    }
    return p;
}

void fun(){
    Point a, b;
    res.clear();
    b = pnt[0];
    a.x = 0; a.y = b.y;
    res.push_back(b.no);
    --num;
    swap(pnt[0], pnt[num]);
    while(num > 0){
        int t = choose(a, b);
        res.push_back(pnt[t].no);
        a = b; b = pnt[t];
        --num;
        swap(pnt[t], pnt[num]);
    }
    printf("%d", res.size());
    for (int i=0; i<res.size(); ++i){
        printf(" %d", res[i]);
    }
    printf("\n");
}

void readIn(){
    scanf("%d", &num);
    Point *p=0;
    for (int i=0; i<num; ++i){
        scanf("%d%lf%lf",&pnt[i].no, &pnt[i].x, &pnt[i].y);
        if (p==0){
            p = &pnt[i];
        } else if (pnt[i].y < p->y || (pnt[i].y==p->y && pnt[i].x < p->x)){
            p = &pnt[i];
        }
    }
    if (p!=&pnt[0]){
        swap(*p, pnt[0]);
    }
}

int main(){
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        fun();
    }

    return 0;
}

