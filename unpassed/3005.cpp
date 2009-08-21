#include<iostream>
using namespace std;
enum {
    SIZ = 504,
};
// should be disjoined, calc x first, and y
// if one is inserted, he overlap the one with the largest value
struct Rect {
    int x0, x1;
    int y0, y1;
    void read(){
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
    }
    bool disjoin(const Rect &r)const{
        return (x0>r.x1)||(x1<r.x0)||(y0>r.y1)||(y1<r.y0);
    }
};

int num;
Rect bac[SIZ];
int dat[SIZ], pos;

void solve(int d){
    pos = 0;
    for (int i=d+1; i<=num; ++i){
        if (!bac[i].disjoin(bac[d])){
            dat[pos++] = i;
        }
    }
    printf("%d", pos);
    for (int i=0; i<pos; ++i){
        printf(" %d", dat[i]);
    }
    printf("\n");
}

void fun(){
    int pic, dst;
    scanf("%d", &pic);
    while(pic--){
        scanf("%d", &dst);
        solve(dst);
    }
    printf("\n");
}

int readIn(){
    if (scanf("%d", &num)<0)
        return 0;
    for (int i=1; i<=num; ++i){
        bac[i].read();
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

