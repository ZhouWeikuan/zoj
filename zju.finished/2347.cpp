#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
enum {
    SIZ = 1004,
};
struct Point {
    int x, y;
    bool operator < (const Point &pnt) const {
        if (x != pnt.x) return x < pnt.x;
        return y < pnt.y;
    }
};
int num;
set<Point> tab;

void fun(){
    int ans = 0;
    Point k, o;
    while(!tab.empty()){
        Point a = *tab.begin();
        tab.erase(tab.begin());
        for (set<Point>::iterator it=tab.begin(); it!=tab.end(); ++it){
            k.x = -((*it).y - a.y);
            k.y = ((*it).x - a.x);
            o.x = (*it).x + k.x; 
            o.y = (*it).y + k.y;
            if (tab.find(o) == tab.end()){
                continue;
            }
            k.x += a.x;
            k.y += a.y;
            if (tab.find(k) == tab.end()){
                continue;
            }
            ++ans;
        }
    }
    printf("%d\n", ans);
}

int readIn(){
    if (scanf("%d", &num) < 0 || num <= 0)
        return 0;
    tab.clear();
    Point pnt;
    for (int i=0; i<num; ++i){
        scanf("%d%d", &pnt.x, &pnt.y);
        tab.insert(pnt);
    }
    return num;
}

int main(){
    int gn;
    scanf("%d", &gn);
    while(gn--){
        while(readIn() > 0){
            fun();
        }
        if (gn) printf("\n");
    }

    return 0;
}

