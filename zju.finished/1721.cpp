#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
enum {
    SIZ  = 10,
    MaxV = 1000000000,
};
struct Point {
    double x,y;
};
struct Range {
    double col;
    double y[4];
    double d[4];
};
vector<Range> door;
Range one;
Point a, b, c;
double dis;

double getDis(Point &l, Point&r){
    return sqrt((l.x-r.x)*(l.x-r.x) + (l.y-r.y)*(l.y-r.y));
}
double getCord(Point &l, Point &h, double x){
    double y = (h.y-l.y)*(x-l.x)/(h.x-l.x);
    y += l.y;
    return y;
}
bool test(Point &l, Point &r, int s, int e){
    if(e <= s) return true;
    double v;
    for(; s<e; s++){
        v = getCord(l, r, door[s].col);
        if(v<door[s].y[0]||(v>door[s].y[1]&&v<door[s].y[2])||(v>door[s].y[3])){
            return false;
        }
    }
    return true;
}
double fun(){
    int i, j;
    dis = MaxV;
    a.x = 0, a.y = 5.0;
    b.x = 10.0, b.y = 5.0;
    if(test(a, b, 0, door.size())){
        return 10.0;
    }
    for(i=0; i<door.size(); i++){
        for(j=0; j<4; j++){
            c.x = door[i].col; c.y=door[i].y[j];
            if(test(a, c, 0, i)){
                door[i].d[j] = getDis(a, c);
            }
        }
    }
    for(i=0; i<door.size(); i++){
        for(j=0; j<4; j++){
            a.x = door[i].col, a.y=door[i].y[j];
            if(test(a, b, i+1, door.size())){
                double v = getDis(a, b) + door[i].d[j];
                if(dis > v){
                    dis = v;
                }
            }
            for(int m=i+1; m<door.size(); m++){
                for(int n=0; n<4; n++){
                    c.x = door[m].col; c.y=door[m].y[n];
                    if(test(a, c, i+1, m)){
                        double v = getDis(a, c) + door[i].d[j];
                        if(door[m].d[n] > v){
                            door[m].d[n] = v;
                        }
                    }
                }
            }
        }
    }
    return dis;
}
int readIn(){
    int i, a;
    door.clear();
    scanf("%d", &i);
    if(i == -1) return 0;
    for(i-- ;i>=0; i--){
        scanf("%lf", &one.col);
        for(int x=0; x<4; x++){
            scanf("%lf", &one.y[x]);
            one.d[x] = MaxV;
        }
        door.push_back(one);
    }
    return 1;
}
int main(){
    double t;
    while(readIn() > 0){
        t = fun();
        printf("%.2lf\n", t);
    }
    return 0;
}

