#include<iostream>
using namespace std;
int hx,hy,lx,ly;

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    while(x || y){
        lx = hx = x; ly=hy=y;
        do {
            if(lx > x){
                lx = x;
            } else if(hx < x){
                hx = x;
            }
            if(ly > y){
                ly = y;
            } else if(hy < y){
                hy = y;
            }
            scanf("%d%d",&x,&y);
        } while(x||y);
        printf("%d %d %d %d\n",lx, ly, hx, hy);
        scanf("%d%d",&x,&y);
    }

    return 0;
}
