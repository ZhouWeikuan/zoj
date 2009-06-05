#include<iostream>
using namespace std;
enum {
    SIZ  = 1008,
    MaxN = 0x7fffffff,
};
int L,C, num;
int topic[SIZ];
int dis[SIZ];
int cnt[SIZ];

void readIn(){
    scanf("%d%d",&L,&C);
    for(int i=0; i<num; i++){
        scanf("%d", &topic[i]);
    }
}

int calc(int t){
    if(t == 0) return 0;
    if(t <= 10) return -C;
    return (t-10)*(t-10);
}
void fun(){
    int t, j, c, v;
    dis[num] = cnt[num] = 0;
    for(int i=num-1;i>=0;i--){
        dis[i] = cnt[i] = MaxN;
        j = i+1; t = topic[i];
        while(t <= L && j <= num){
            c = 1 + cnt[j];
            v = calc(L-t) + dis[j];
            if(c < cnt[i]){
                cnt[i] = c; dis[i] = v;
            } else if(c == cnt[i] && dis[i] > v){
                dis[i] = v;
            }
            t += topic[j];
            j ++;
        }
    }
}

int main(){
    int tstblk, tstcase;
    scanf("%d",&tstblk);
    while(tstblk--){
        tstcase = 0;
        scanf("%d",&num);
        while(num){
            if(tstcase){
                printf("\n");
            }
            readIn();
            fun();
            tstcase++;

            printf("Case %d:\n\n", tstcase);
            printf("Minimum number of lectures: %d\n", cnt[0]);
            printf("Total dissatisfaction index: %d\n", dis[0]);

            scanf("%d",&num);
        }
        if(tstblk){
            printf("\n");
        }
    }
    return 0;
}

