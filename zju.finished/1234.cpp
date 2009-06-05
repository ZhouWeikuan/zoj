#include<iostream>
using namespace std;
// 看了别人的递推式才知道，处理连续相邻的两个数时注意判断前面多出的数
enum {
    SIZ  = 5004,
    MaxV = 0x1fffffff,
};
int bad[2][SIZ];
int chop[SIZ];
int K, N;

void fun(){
    int i,j,t;
    int pre=0, cur=1;
    memset(bad, 0, sizeof(bad));
    for(i=1; i<=K; i++){
        for(j=2*i; j<=N; j++){
            bad[cur][j] = MaxV;
            if(j>2*i){
                bad[cur][j] = bad[cur][j-1];
            }
            if(N - (K-i)*3 > j){
                t = (chop[j]-chop[j-1]);
                t *= t;
                t += bad[pre][j-2];
                if(bad[cur][j] > t){
                    bad[cur][j] = t;
                }
            } else {
                t = (chop[j-1] - chop[j-2]);
                t *= t;
                t += bad[pre][j-3];
                if(bad[cur][j] > t){
                    bad[cur][j] = t;
                }
            }
        }
        pre = 1 - pre;
        cur = 1 - cur;
    }

    printf("%d\n", bad[pre][N]);
}

void readIn(){
    scanf("%d%d",&K,&N);
    K += 8;
    for(int i=1; i<=N; i++){
        scanf("%d", &chop[i]);
    }
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

