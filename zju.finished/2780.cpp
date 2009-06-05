#include<iostream>
using namespace std;
/*对我来说还是有点难度的，昨晚想到过这种方法*/
enum {
    SIZ = 1008,
};
unsigned cnt[SIZ];
int sum[SIZ];
int num, dol;
int ven[30];

void fun(){
    memset(cnt, 0, sizeof(cnt[0])*(dol+8));
    int i, j, v, hi, low;
    unsigned res = 0;
    if(ven[0] > dol){
        printf("0\n");
        return;
    }
    cnt[0] = 1;
    for(i=num-1; i>=0; i--){
        hi = dol - sum[i];          // 尾
        low = dol - sum[i+1] + 1;   // 首
        if(hi < 0) hi = -1;
        if(low < 0) low = 0;
        for(j=hi; j>=low; j--){
            res += cnt[j];
            // cnt[j] = 0;
        }
        for(j=dol-ven[i]; j>=0; j--){
            cnt[j+ven[i]] += cnt[j];
        }
    }
    if(sum[num] <= dol) res++;

    printf("%u\n", res);
}

void readIn(){
    scanf("%d%d", &num, &dol);
    for(int i=0; i<num; i++){
        scanf("%d", &ven[i]);
    }
    sort(ven, ven+num);
    sum[0] = 0;
    for(int i=1; i<=num; i++){
        sum[i] = sum[i-1] + ven[i-1];
    }
}
int main(){
    int tst, v=0;

    scanf("%d", &tst);
    while(tst--){
        printf("%d ", ++v);
        readIn();
        fun();
    }

    return 0;
}

/*
简单的DP题目。此题唯一的难点就是"A valid combination must have a total price 
no more than the allocated amount and the unused amount (allocated amount – 
total price) must be less than the price of any establishment that was not 
selected."这句话。题目要求剩下的总量要不小于任何未选择的establishment，
即不小于未被选择的最小价格的 establishment。我们对所有的establishment按价格
由小到大排序，以下均在排序后的前提下讨论。假设未被选择的最小价格的 
establishment是第i个，那么首先可以确定前i-1个establishment一定是被选择的，
亦可以确定第i+1个到第n个 establishment的所有可行组合的价格和S满足 
D - v[i] < S + sum[ i-1 ] <= D , S 属于 N (其中sum[i]为前i个establishment的
价格和，v[i]为第i个establishment的价格)。这样，只要枚举所有的i然后再找出满足
条件的组合的个数（背包）即是本题的答案。
*/

