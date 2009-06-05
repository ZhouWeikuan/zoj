#include<iostream>
using namespace std;
enum {
    //SIZ = 508,
    SIZ = 1,
};
// 利用二分算法,求出循环节和调整在循环中的位置 
// rule    11->10 or 10{x}10{x} =>11{x}00{x}  {x} stands for consequence 0
// at first it is  011111111111111111{...}
int mat[SIZ][SIZ];

int compute(int n, int m){
    if(n == 0 || m ==0) return (n==0&&m==0);
    int r;
    if(m % 2 ==0){
        --n,--m;
    }
    if(n<m)return 0;
    n-=m;
    m=(m+1)/2;
    if(m==1) return 1;
    r = 1;
    while(r < m){
        r *= 2;
    }
    n %= r;
    while(r>1){
        r /= 2;
        if(n >= r) return 0;
        if(m - r <= r/2){ // shift to first
            if(n >= r/2) n-=r/2;
            m -= r/2;
        } else {
            m -= r;
        }
    }
    return 1;
}

void init(){
    int i,j;
    mat[0][0] = 1;
    for(j=1; j<SIZ; j++){
        if(j%2==0){
            for(i=1; i<SIZ; i++){
                mat[i][j] = mat[i-1][j-1];
            }
        } else {
            for(i=1; i<SIZ; i++){
                mat[i][j] = (mat[i-1][j] + mat[i-1][j-1])%2;
            }
        }
    }
}
int main(){
    //init();
    int tst;
    int n, m;
    /*
    for(n=0; n<SIZ; n++){
        for(m=0; m<SIZ; m++){
            if(compute(n,m)!=mat[n][m]){
                printf("%d %d\n", n, m);
                return -1;
            }
        }
    }*/
    scanf("%d",&tst);
    while(tst--){
        scanf("%d%d",&n,&m);
        printf("%d\n", compute(n,m));
    }
    return 0;
}

