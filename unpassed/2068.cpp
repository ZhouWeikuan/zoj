#include<iostream>
using namespace std;
// 题目意思还没看懂呢...
enum {
    SIZ = 508,
};
int tab[2][SIZ];
int an, bn;
int A[SIZ], B[SIZ];

void fun(){
    int *pre=tab[0], *cur=tab[1], *tmp;
    int v, i, j, p;
    memset(pre, -1, sizeof(tab[0]));
    pre[bn] = 0;
    for(i=an-1; i>=0; --i){
        memset(cur, -1, sizeof(tab[1]));
        for(j=1+i+bn-an, p=pre[j]; j>i; --j){
            p = min(p, pre[j]);
            v = (A[i]-B[j-1])*(A[i]-B[j-1]);
            if(cur[i]==-1||cur[i] > v + p){
                cur[i] = v + p;
            }
        }
        tmp = pre, pre = cur, cur = tmp;
    }
    v = -1;
    for(i=0; i<=bn; i++){
        if(pre[i]==-1) continue;
        if(v==-1||pre[i] < v){
            v = pre[i];
        }
    }
    printf("%d\n", v);
}
void readIn(){
    int i;
    scanf("%d", &an);
    for(i=0; i<an; i++){
        scanf("%d", &A[i]);
    }
    sort(A, A+an);
    scanf("%d", &bn);
    for(i=0; i<bn; i++){
        scanf("%d", &B[i]);
    }
    sort(B, B+bn);
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

