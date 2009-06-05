#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 108,
};
struct Point{
    int x, y;
};
int num, len;
Point com[SIZ];
Point l, h;
double dis;

double getDis(int x, int y){
    double s = 0, t;
    for(int i=0; i<num; i++){
        t = (com[i].x - x)*(com[i].x - x) + (com[i].y-y)*(com[i].y-y);
        s += sqrt(t);
    }
    return s;
}

void split(){
    int x = (h.x-l.x+2)/3, y=(h.y-l.y+2)/3;
    int i,j, si=1, sj=1;
    double t;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            t = getDis(l.x + (2*i+1)*x/2, l.y+(2*j+1)*y/2);
            if(dis > t){
                dis = t;si = i;sj = j;
            }
        }
    }
    l.x += x * si;  l.y += y * sj;
    h.x = l.x + x;  h.y = l.y + y;
}
int fun(){
    double t;
    int i, j;
    l.x = 0, l.y = 0, h.x=10000, h.y=10000;
    dis = getDis((l.x+h.x)/2, (l.y+h.y)/2);
    while((h.y-l.y)>5 && (h.x-l.x)>5){
        split();
    }
    for(i=l.x; i<=h.x; i++){
        for(j=l.y; j<=h.y; j++){
            t = getDis(i, j);
            if(dis > t) dis = t;
        }
    }
    i = (int)dis;
    if(dis - i >= 0.5){
        i++;
    }
    return i;
}

int readIn(){
    if(scanf("%d", &num)<0)
        return 0;
    for(int i=0; i<num; i++){
        scanf("%d%d", &com[i].x, &com[i].y);
    }
    return num;
}
int main(){
    while(readIn() > 0){
        printf("%d\n", fun());
    }
    return 0;
}

