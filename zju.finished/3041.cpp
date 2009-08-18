#include<iostream>
#include<algorithm>
using namespace std;
enum {
    SIZ = 200004,
};
int N, M;
struct Point {
    int x, y;
    bool operator < (const Point&o)const{
        if (x!=o.x)
            return x<o.x;
        return y>o.y;
    }
    struct cmp{
        bool operator() (const Point&l, const Point&r)const{
            if (l.x!=r.x) return l.x < r.x;
            return l.y<r.y;
        }
    };
};
Point city[SIZ];
Point fac[SIZ];

void fun(){
    int c = 0, f = 0, i=0;
    while (c < N){
        while (f<M-1&&fac[f+1].x<=city[c].x)
            ++f;
        if (fac[f].x > city[c].x){
            if (i!=c){
                city[i] = city[c];
            }
            ++i,++c;
        } else if (fac[f].y < city[c].y){
            if (i!=c){
                city[i] = city[c];
            }
            ++i,++c;
        } else {
            ++c;
        }
    }
    N = i;
    sort(city, city+N, Point::cmp());
    printf("%d\n", N);
    for (i=0; i<N; ++i){
        printf("%d %d\n", city[i].x, city[i].y);
    }
}

int readIn(){
    if (scanf("%d%d",&N,&M) < 0) return 0;
    int i, j=0;
    for (i=0; i<N; ++i){
        scanf("%d%d",&city[i].x, &city[i].y);
    }
    for (i=0; i<M; ++i){
        scanf("%d%d",&fac[i].x, &fac[i].y);
    }
    sort(city, city+N);
    sort(fac, fac+M);
    j = 0;
    for (i=1; i<M; ++i){
        if (fac[i].x == fac[j].x || fac[i].y <= fac[j].y)
            continue;
        fac[++j].x = fac[i].x;
        fac[j].y = fac[i].y;
    }
    M = j+1;
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

