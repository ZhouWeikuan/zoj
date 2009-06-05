// zoj 2860
// assume the split position of [a,b-1] is l, 
//                           of [a+1,b] is r,
// then the split position of [a,b] is between [l,r];
#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
    MaxN= 0x7fffffff,
};
int N, num;
int pos[SIZ];
int cost[SIZ][SIZ];
int ptr[SIZ][SIZ];

int main(){
    int i,j,t,l,r;
    pos[0] = 0;
    while(scanf("%d%d",&N, &num) > 0){        
        pos[++num] = N;
        for(i=1; i<num; i++){
            scanf("%d", &pos[i]);
        }
        for(i=0;i<=num;i++){
            cost[i][i] = cost[i][i+1] = 0;
            ptr[i][i]  = ptr[i][i+1] = 0;
            cost[i][i+2] = pos[i+2] - pos[i];
            ptr[i][i+2] = i+1;
        }
        for(t=3;t<=num;t++){
            for(i=0,j=t;j<=num;i++,j++){
                cost[i][j] = MaxN;
                for(l=ptr[i][j-1], r=ptr[i+1][j]; l<=r; l++){                    
                    if(cost[i][j] > cost[i][l] + cost[l][j]){
                        cost[i][j] = cost[i][l] + cost[l][j];
                        ptr[i][j]  = l;
                    }
                }
                cost[i][j] += pos[j] - pos[i];
            }
        }
        printf("%d\n", cost[0][num]);
    }
    return 0;
}

