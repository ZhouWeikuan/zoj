#include<iostream>
using namespace std;
// 动态规划，从别人那里抄来的思想，程序倒是自己写的:)
enum {
    SIZ = 5004,
    MAX = 99999999,
};
int hire,fire,salary;
int tab[2][SIZ], *pred, *now;
int mon, lim;
int worker[14];

void set(int *t, int n){
    for(int i=0;i<=n;i++){
        t[i] = MAX;
    }
}
int fun(){
    int *tmp;
    int i,j,k,t;
    pred = tab[0], now = tab[1];
    set(pred, lim);
    pred[0] = 0;
    for(i=0;i<mon;i++){
        set(now, lim);
        for(j=i>0?worker[i-1]:0;j<=lim;j++){
            for(k=worker[i];k<=lim;k++){
                t = pred[j] + k * salary;
                if(j<=k){
                    t += (k-j)*hire;
                }else if(j>k){
                    t += (j-k)*fire;
                }
                if(t < now[k]){
                    now[k] = t;
                }
            }
        }
        tmp = pred, pred = now, now = tmp;
    }
    t = MAX;
    for(i=0;i<=lim;i++){
        if(pred[i] < t)
            t = pred[i];
    }
    return t;
}

int main(){
    
    scanf("%d",&mon);
    while(mon){
        scanf("%d%d%d",&hire,&salary,&fire);
        lim = -1;
        for(int i=0;i<mon;i++){
            scanf("%d",&worker[i]);
            if(worker[i] > lim)
                lim = worker[i];
        }
        printf("%d\n",fun());
        scanf("%d",&mon);
    }

    return 0;
}
