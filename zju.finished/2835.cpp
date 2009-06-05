#include<iostream>
using namespace std;
enum {
    NUM = 1004,
    SIZ = 10,
};
int mark[NUM];
int mat[SIZ][SIZ];
int num,sum;
int row(){
    int t;
    for(int i=0;i<num;i++){
        t = 0;
        for(int j=0;j<num;j++){
            t += mat[i][j];
        }
        if(t != sum)
            return 0;
    }
    return 1;
}
int col(){
    int t;
    for(int j=0;j<num;j++){
        t = 0;
        for(int i=0;i<num;i++){
            t += mat[i][j];
        }
        if(t != sum)
            return 0;
    }
    return 1;
}
int diag(){
    for(int i=0;i<num;i++){
        sum += mat[i][i];
    }
    int t = 0;
    for(int i=0;i<num;i++){
        t += mat[i][num-1-i];
    }
    return sum==t;
}
int distinct(){
    memset(mark,0,sizeof(mark));
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(mark[mat[i][j]] == 0){
                mark[mat[i][j]] = 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}
int readIn(){
    scanf("%d", &num);
    if(num==0)
        return 0;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    sum = 0;
    return 1;
}
int fun(){
    return distinct() && diag() && col() && row();
}
int main(){
    const char *ans[2] = {"No","Yes"};
    while(readIn()> 0){
        printf("%s\n", ans[fun()]);
    }
    return 0;
}

