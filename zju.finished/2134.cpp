#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
int num, val;
int mat[SIZ][SIZ];
int side[SIZ];

void dfs(int i, int v){
    if(i == num){
        if(v > val) val = v;
        return;
    }
    int a=0, b=0;
    for(int k=0; k<i; k++){
        if(side[k] == 1){
            a += mat[k][i];
        } else {
            b += mat[k][i];
        }
    }
    side[i] = 0;
    dfs(i+1, v + a);
    side[i] = 1;
    dfs(i+1, v + b);
}
void fun(){
    side[0] = 0;
    val = 0;
    dfs(1, 0);
    printf("%d\n", val);
}
void readIn(){
    scanf("%d", &num);
    int i, j;
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
        if(tst) printf("\n");
    }
    return 0;
}

