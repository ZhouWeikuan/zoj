#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};
int mat[SIZ][SIZ];
int N,M;

int readIn(){
    scanf("%d%d",&N,&M);
    if(N + M == 0)
        return 0;
    int i,j,k,t;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            mat[i][j] = 0;
        }
    }
    for(k=0;k<3;k++){
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                scanf("%d",&t);
                mat[i][j] += t;
            }
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            mat[i][j] /= 3;
        }
    }
    return 1;
}
void fun(){
    for(int i=0;i<N;i++){
        printf("%d", mat[i][0]);
        for(int j=1;j<M;j++){
            printf(",%d", mat[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int tstcase = 0;
    while(readIn() > 0){
        printf("Case %d:\n", ++tstcase);
        fun();
    }
    return 0;
}
