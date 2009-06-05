#include<iostream>
#include<cmath>
using namespace std;

const double eps = 1e-7;
struct Line{
    int x0,x1,y0,y1;
    void readIn(){
        scanf("%d%d%d%d", &x0,&y0,&x1,&y1);
    }
};
Line a,b;

void fun(){
    int adx, ady, bdx, bdy;
    adx = a.x1-a.x0; ady = a.y1-a.y0;
    bdx = b.x1-b.x0; bdy = b.y1-b.y0;
    if(ady*bdx==bdy*adx){ // parallel or same?
        if((a.y0-b.y0)*bdx==bdy*(a.x0-b.x0)){ //same
            printf("LINE\n");
        } else {
            printf("NONE\n");
        }
        return;
    }
    double res;
    res = -a.y0*bdx*adx-b.x0*adx*bdy+a.x0*ady*bdx + b.y0*adx*bdx;
    res /= (ady*bdx-bdy*adx);
    if(fabs(res) < eps) res = 0;
    printf("POINT %.2lf ", res);
    res = b.x0*bdy*ady - b.y0*bdx*ady - a.x0*bdy*ady + a.y0*adx*bdy;
    res /= (-ady*bdx+bdy*adx);
    if(fabs(res) < eps) res = 0;
    printf("%.2lf\n", res);
}

int main(){
    int tst;
    printf("INTERSECTING LINES OUTPUT\n");
    scanf("%d",&tst);
    while(tst--){
        a.readIn(); b.readIn();
        fun();
    }
    printf("END OF OUTPUT\n");
    return 0;
}

