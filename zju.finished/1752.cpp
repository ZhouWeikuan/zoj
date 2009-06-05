#include<iostream>
using namespace std;
// 居然最暴力的方法过了...
// 思路是从网上拷贝的，我一开始还打算用线段树呢，可惜不会二维的
enum {
    SIZ = 201,
};
char tab[SIZ][SIZ];
int color;
int readIn(){
    int num;
    scanf("%d%d",&num,&color);
    int v,a,b,c,d,t;
    memset(tab, 0, sizeof(tab));
    for(int i=0;i<num;i++){
        scanf("%d%d%d%d%d",&v,&a,&b,&c,&d);
        a += 100; b += 100; c += 100; d += 100;
        if(a > c){
            t =c ,c =a, a=t;
        }
        if(b > d){
            t = b, b = d, d = t;
        }
        for(int j=a;j<c;j++){
            memset(&tab[j][b], v, (d - b));
        }
    }
    return num;
}
int fun(){
    int a = 0;
    for(int i=0;i<SIZ;i++){
        for(int j=0;j<SIZ;j++){
            a += (tab[i][j]==color);
        }
    }
    static int tstcase = 1;
    printf("The area of color %d in dataset %d is: %d\n", color, tstcase++, a);
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}
