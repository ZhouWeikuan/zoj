#include<iostream> 
using namespace std; 
// for zju 2900  TLE
enum {
    SIZ = 108,
    LEN = 2008,
};
int N, K, P, M;
int dat[LEN];
int cnt[SIZ][LEN];

void fun(){
    memset(cnt, 0, sizeof(cnt));
    int ret = 0, low, hi;
    for(int i=0; i<N; i++){
        low = max(dat[i]-P, 0);
        hi  = min(dat[i]+P, 100);                       
        for(int j=K-1; j>0; j--){
            for(int t=low; t<=hi; t++){
                cnt[dat[i]][j+1] += cnt[t][j];
                cnt[dat[i]][j+1] %= M;
            }
        }
        for(int t=low; t<=hi; t++){
            if(t == dat[i]) continue;
            cnt[dat[i]][K] += cnt[t][K];
            cnt[dat[i]][K] %= M;
        }
        cnt[dat[i]][1] = (cnt[dat[i]][1] + 1 )%M;
                
        ret = (ret + cnt[dat[i]][K]) % M;
    }
    printf("%d\n", ret);
}

int readIn(){
    if(scanf("%d%d%d%d", &N, &K, &P, &M) < 0) return 0;
    if(K<=1) K = 1;
    for(int i=0; i<N; i++){
        scanf("%d", &dat[i]);
    }
    return 1;
}
int main(){
    
    while(readIn() > 0){
        fun();
    }
    return 0;
}

