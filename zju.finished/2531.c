#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 具体数学有介绍公式
// 这里编程时基本上照抄了网上某人的程序:)

// 获得数字x出现的位置
int getPos(int x){
    int y;
    for(y=x;x>>=1;y^=x)
        ;
    return y;
}
// 获得位置x所出现的数字
int getVal(int x){
    return x^(x>>1);
}
int N,M;

int readIn(){
    scanf("%d%d",&N,&M);
    return N + M;
}
int check(int n){
    int t = 0;
    while(n > 0){
        t += n &0x01;
        n>>=1;
    }
    return t;
}
void fun(){
    if(check(N) != 1 ){
        printf("NO\n");
        return ;
    }
    printf("%d", M);
    int p = getPos(M);
    for(int i=1;i<N;i++){
        p++;
        if(p == N){
            p = 0;
        }
        M = getVal(p);
        printf(" %d", M); 
    }
    printf("\n");
}

int main(){
    while(readIn()){
        fun();
    }
    return 0;
}

