#include<iostream>
using namespace std;
enum {
    SIZ = 10008,
};
int slen, dpos;
int tab[2][SIZ];
int *src, *dst;
long long sum, cost;

void readIn(){
    int i;
    sum = cost = 0;
    scanf("%d%d",&slen, &dpos);
    for(i=1; i<=slen; i++){
        scanf("%d", &tab[0][i]);
        sum  += tab[0][i];
    }
    for(i=1; i<=dpos; i++){
        scanf("%d", &tab[1][i]);
        cost += tab[1][i];
    }
    if(sum < cost){
        src = tab[0], dst = tab[1];
    } else {
        src = tab[1], dst = tab[0];
        i = dpos, dpos = slen, slen = i;
    }
    sum = cost = 0;
}
void fun(){
    int si=1, di=1;
    while(si <= slen){
        if(src[si] < dst[di]){
            sum  += src[si];
            cost += src[si]*(si+di);
            dst[di] -= src[si];
            si++;
        } else {
            sum  += dst[di];
            cost += dst[di]*(si+di);
            src[si] -= dst[di];
            di++;
        }
    }
    printf("%lld %lld\n", sum, cost);
}
int main(){
    int tst, tstn=0;
    scanf("%d", &tst);
    while(tst--){
        printf("Case %d:\n", ++tstn);
        readIn();
        fun();
        if(tst) printf("\n");
    }
    return 0;
}
