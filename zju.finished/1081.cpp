#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};

int N, M;
struct Point {
    int x,y;
}pnt[SIZ];
Point dot;

bool online(const Point&a, const Point&b) {
    if (a.y==b.y){
        if (a.y==dot.y)
            return (dot.x>=min(a.x,b.x) && dot.x<=max(a.x,b.x));
        return false;
    }
    if (a.x==dot.x&&a.y==dot.y)
        return true;
    if (b.x==dot.x&&b.y==dot.y)
        return true;
    if (a.y==dot.y||b.y==dot.y)
        return false;
    return (dot.y-b.y)*(a.x-dot.x) - (a.y-dot.y)*(dot.x-b.x) == 0
            && dot.y>=min(a.y,b.y) && dot.y<=max(a.y,b.y);
}

int intersect(const Point&a, const Point&b) {
    if (a.y==b.y){
        return 0;
    }
    if (a.y==dot.y){
        if (a.x > dot.x)
            return 0;
        if (b.y>a.y){
            return 0;
        }
        return 1;
    }
    if (b.y==dot.y){
        if (b.x > dot.x)
            return 0;
        if (a.y > b.y)
            return 0;
        return 1;
    }
    double x = (a.y*b.x -b.y*a.x) + dot.y*(a.x-b.x);
    x /= (a.y-b.y);
    return (x<=dot.x && dot.y>=min(a.y,b.y) && dot.y<=max(a.y,b.y));
}

bool checkInside(){
    int i;
    int r = 0;
    if (N==1){
        return (pnt[0].x==dot.x)&&(pnt[0].y==dot.y);
    }else if(N==2){
        return online(pnt[0],pnt[1]);
    }
    for (i=0; i<N; ++i){
        if (online(pnt[i], pnt[(i+1)%N])){
            return true;
        } else if (intersect(pnt[i], pnt[(i+1)%N])){
            r = 1 - r;
        }
    }
    return r; 
}

void fun(){
    while(M--){
        scanf("%d%d ", &dot.x, &dot.y);
        if (checkInside()){
            printf("Within\n");
        } else {
            printf("Outside\n");
        }
    }
}

int readIn(){
    scanf("%d%d ", &N, &M);
    if (N == 0) return N;
    for (int i=0; i<N; ++i){
        scanf("%d%d ", &pnt[i].x, &pnt[i].y);
    }

    return N;
}

int main(){
    int tst=0;
    while(readIn() > 0){
        if (tst++)
            printf("\n");
        printf("Problem %d:\n", tst);
        fun();
    }

    return 0;
}

