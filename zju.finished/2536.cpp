#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 24,
};
// 从1开始加倍，如果找到倍数，则再次加倍..
//      小于这个倍数，则将它加到这个倍数上去
//      大于，则动用贮备
//
//  原理不清楚，只是觉得这样正确
int w[SIZ], n, k;
void readIn(){
    scanf("%d%d",&n, &k);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    sort(w, w + n);
}
int fun(){
    int cur = 1, i = 0;
    while(i < n){
        if(w[i] == cur){
            cur *= 2;
            i++;
        } else if(w[i] < cur){
            cur += w[i];
            i++;
        } else {
            if(k <= 0){
                break;
            }
            k--;
            cur *= 2;
        }
    }
    while(k--){
        cur *= 2;
    }

    return cur;
}

int main(){
    int tstnum, tstcase=1;
    scanf("%d",&tstnum);
    while(tstnum -- ){
        readIn();
        printf("Case %d:\n", tstcase++);
        printf("%d\n", fun());
        if(tstnum)
            printf("\n");
    }
    return 0;
}

