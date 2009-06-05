#include<iostream>
using namespace std;
// 从网上拷贝思想，知道使用高度差来节约空间
enum {
    SIZ = 108,
    MAX = 1008,
};

int num, total;
int cry[SIZ];
int tab[2][MAX]; // 高度差为x时tab[cur][x]表明最低塔的高度,-1表示没有

void readIn(){
    total = 0;
    for(int i=0;i<num;i++){
        scanf("%d",&cry[i]);
        total += cry[i];
    }
}
int fun(){
    total += 1;
    total /= 2;
    int *cur, *nex, *p;
    int t,x,y;
    cur = tab[0], nex = tab[1];
    memset(cur, -1, (total + 1)*sizeof(int));
    cur[0] = 0;
    for(int i=0;i<num;i++){
        memset(nex, -1, (total+1)*sizeof(int));
        for(int j=0;j<=total;j++){
            if(cur[j] < 0)
                continue;
            if(nex[j] < cur[j]){
                nex[j] = cur[j];
            }
            x = cur[j]; 
            y = x + j;
            // add to lower
            x += cry[i];
            if(x > y){
                t = x - y;
                if(t <= total && nex[t] < y) 
                    nex[t] = y;
            } else {
                t = y - x;
                if(t <= total && nex[t] < x){
                    nex[t] = x;
                }
            }
            // add to higher
            x -= cry[i];
            y += cry[i];
            t = y - x;
            if(t <= total && nex[t] < x){
                nex[t] = x;
            }
        }
        p = nex, nex = cur, cur = p;
    }

    return cur[0];
}
int main(){
    scanf("%d",&num);
    while(num > 0){
        readIn();
        int t = fun();
        if(t > 0){
            printf("%d\n", t);
        } else {
            printf("Sorry\n");
        }
        scanf("%d",&num);
    }
    return 0;
}
