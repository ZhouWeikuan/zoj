#include<iostream>
using namespace std;
enum {
    SIZ = 502,
};
// 直接计算...
int num;
int m[SIZ][SIZ];
void readIn(){
    int i,j;
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            scanf(" %d",&m[i][j]);
        }
    }
}
void fun(){
    int i,j, t;
    for(i=0; i<num; i++){
        for( j=0; j<num; j++ ){
            if(j==num-1){
                printf("%d", m[i][j]);
                continue;
            } else if(i==0 || j==0 || i==num-1 ){
                printf("%d ", m[i][j]);
                continue;
            }
            t = m[i][j] * 2;
            t += m[i-1][j] + m[i+1][j] + m[i][j-1] + m[i][j+1];
            t *= 2;
            t += m[i-1][j-1] + m[i-1][j+1] + m[i+1][j-1] + m[i+1][j+1];
            t /= 16;
            printf("%d ", t);
        }
        printf("\n");
    }
}
int main(){
    int tstcase = 0;

    scanf(" %d",&num);
    while(num > 0){
        printf("Case %d:\n", ++tstcase);
        readIn();
        fun();
        scanf(" %d",&num);
    }

    return 0;
}

