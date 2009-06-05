#include<iostream>
using namespace std;
enum {
    SIZ = 1002,
    ALP = 30,
};
struct Node {
    unsigned val, ptr;
};
int len, num;
Node cost[SIZ][ALP];
int mat[ALP][ALP];
int dat[SIZ];
char buf[SIZ];

void fun(){
    int i,j,k,t;
    memset(cost[len-1], 0, sizeof(cost[0]));
    for(i=len-1; i>0; i--){
        memset(cost[i-1], -1, sizeof(cost[0]));
        for(j=0; j<num; j++){
            for(k=0; k<num; k++){
                t = abs(mat[k][j] - dat[i-1]);
                if(cost[i-1][k].val > cost[i][j].val + t){
                    cost[i-1][k].val = cost[i][j].val + t;
                    cost[i-1][k].ptr = j;
                }
            }
        }
    }
    t = 0;
    for(i=1; i<num; i++){
        if(cost[0][i].val < cost[0][t].val)
            t = i;
    }
    for(i=0; i<len; i++){
        buf[i] = t + 'a';
        t = cost[i][t].ptr;
    }
    buf[i] = 0;
    printf("%s\n", buf);
}

int readIn(){
    if(scanf("%d%d",&len, &num) < 0) return 0;
    int i,j;
    for(i=0; i<len-1; i++){
        scanf("%d", &dat[i]);
    }
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

