#include<iostream>
using namespace std;
enum {
    SIZ = 1001,
};

double mat[SIZ][SIZ];

void init(){
    int i, j;
    for(i=0; i<SIZ; i++){
        mat[i][0] = mat[0][i] = 0;
    }
    for(i=1; i<SIZ; i++){
        for(j=1; j<=i; j++){
            mat[i][j] = 1 + (mat[i-1][j] + mat[i][j-1])*0.5;
            mat[j][i] = mat[i][j];
        }
    }
}

int main(){
    init();
    int tst, n;

    scanf("%d ", &tst);
    while(tst--){
        scanf("%d ", &n);
        printf("%.2lf\n", mat[n][n]);
    }

    return 0;
}

