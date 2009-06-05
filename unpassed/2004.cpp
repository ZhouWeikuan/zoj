#include<iostream>
// 用merge排序求逆序数，没过
// 用转换方法判断奇偶性 也不行...
using namespace std;
enum {
    SIZ = 100 * 100 * 100,
};
int N;
int dat[SIZ];
void readIn(){
    scanf("%d ",&N);
    N = N * N * N - 1;
    int i, j=0, t;
    for(i=0; i<=N; i++){
        scanf("%d ", &t);
        if(t == 0) continue;
        dat[j++] = t;
    }
}
int fun(){
    int ans = 0;
    int i, t;
    for(i=0; i<N; i++){
        while(dat[i] != i+1){
            t = dat[dat[i]-1];
            dat[dat[i]-1] = dat[i];
            dat[i] = t;
            ans = 1 - ans;
        }
    }
    return ans;
}
int main(){
    int tstcase;
    scanf("%d ",&tstcase);
    while(tstcase --){
        readIn();
        if( fun()==0 ){
            printf("Puzzle can be solved.\n");
        } else {
            printf("Puzzle is unsolvable.\n");
        }
    }
	return 0;
}

