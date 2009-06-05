#include<iostream>
using namespace std;
enum {
    SIZ = 60,
};
int num;
char lit[SIZ];
int mat[SIZ][SIZ];

void fun(){
    int l,i,j,v;
    for(l=0; l<num; l++){
        for(i=0; i+l<num; i++){
            mat[i][i+l] = l+1;
            for(j=i+1;j<=i+l;j++){
                v = lit[j] == lit[i];
                if(mat[i][i+l] > mat[i][j-1] + mat[j][i+l]-v){
                    mat[i][i+l] = mat[i][j-1] + mat[j][i+l]-v;
                }
            }
        }
    }
    printf("%d\n", mat[0][num-1]);
}

int readIn(){
    scanf("%d",&num);
    if(num > 0){
        scanf("%s", lit);
    }
    return num;
}

int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

