#include<iostream>
using namespace std;
enum {
    SIZ = 108,
};
// 写的方法不当的话，会老是RE，太恶心了...
double cost[SIZ][SIZ];
int goods[SIZ];
int mark[SIZ];
double rate[SIZ];
int num, e;

int readIn(){
    if(scanf("%d%d",&num, &e) < 0)
        return 0;
    for(int i=0;i<num-1;i++){
        scanf("%d",&goods[i]);
    }
    goods[num-1] = 0;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cost[i][j] = -1;
        }
    }
    int a,b; double c;
    for(int i=0;i<e;i++){
        scanf("%d%d%lf",&a,&b,&c);
        a--,b--;
        if(cost[a][b]< 0 || c < cost[a][b]){
            cost[a][b] = cost[b][a] = c;
        }
    }
    return 1;
}
void fun(){
    memset(rate,0,sizeof(rate));
    memset(mark,0,sizeof(mark));
    rate[num-1] = 1;
    int cur;
    double up;
    while(1){
        cur = -1;
        for(int i=0;i<num;i++){
            if(mark[i] == 1)
                continue;
            if(cur == -1 || rate[i] > rate[cur]){
                cur = i;
            }
        }
        if(cur == -1)
            break;
        mark[cur] = 1;
        for(int i=0;i<num;i++){
            if(mark[i] == 1 || cost[cur][i] < 0)
                continue;
            up = rate[cur] * (1.0 - cost[cur][i]);
            if(up > rate[i]){
                rate[i] = up;
            }

        }
    }
    up = 0;
    for(int i=0;i<num;i++){
        up += rate[i] * goods[i];
    }
    printf("%.2lf\n", up);
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

