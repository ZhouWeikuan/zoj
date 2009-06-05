#include<iostream>
using namespace std;

int main(){
    int s, d, v;
    while(scanf("%d%d",&s,&d) > 0){
        v = -1;
        if(4*s-d<0 && 10*s-2*d>0)
            v = max(v, 10*s-2*d);
        if(3*s-2*d<0 && 8*s-4*d>0)
            v = max(v, 8*s-4*d);
        if(2*s-3*d<0 && 6*s-6*d>0)
            v = max(v, 6*s-6*d);
        if(s-4*d<0 && 3*s-9*d>0)
            v = max(v, 3*s-9*d);
        if(v >= 0){
            printf("%d\n", v);
        } else {
            printf("Deficit\n");
        }
    }
    return 0;
}

