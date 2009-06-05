#include<iostream>
using namespace std;
enum {
    SIZ = 104,
    LOW = -99999999,
};
int city, day;
int cost[SIZ][SIZ], income[SIZ][SIZ];
int tab[2][SIZ];

void fun(){
    int *pre=tab[0], *cur=tab[1], *tmp;
    int i,j,k,t;
    for(i=0; i<city; i++){
        pre[i] = LOW;
    }
    pre[0] = 0;
    for(i=0; i<day; i++){
        for(j=0;j<city;j++){
            cur[j] = LOW;
            for(k=0; k<city; k++){ // from k to j;
                if(pre[k] == LOW) continue;
                t = income[i][j] - cost[k][j] + pre[k];
                if(cur[j] < t){
                    cur[j] = t;
                }
            }
        }
        tmp=pre, pre=cur, cur=tmp;
    }
    t = LOW;
    for(i=0; i<city; i++){
        if(pre[i] > t){
            t = pre[i];
        }
    }
    printf("%d\n", t);
}

int readIn(){
    scanf("%d%d", &city, &day);
    if(city + day == 0) return 0;
    int i,j;
    for(i=0; i<city; i++){
        for(j=0;j<city;j++){
            scanf("%d", &cost[i][j]);
        }
    }
    for(i=0; i<day; i++){
        for(j=0; j<city; j++){
            scanf("%d", &income[i][j]);
        }
    }
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

