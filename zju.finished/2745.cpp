#include<iostream>
using namespace std;
enum {
    SIZ = 6,
};
typedef long long (*D2)[SIZ];
long long tab[2][SIZ][SIZ];
int N, K, lim;

void fun(){
    if(N <= K){
        printf("%d\n", 1<<N);
        return ;
    }
    D2 pre, cur, tmp;
    pre = tab[0], cur = tab[1];
    memset(pre, 0, sizeof(tab[0]));
    pre[0][0] = 1;
    int i, a, b, m, n;
    for(i=0; i<N; i++){
        memset(cur, 0, sizeof(tab[0]));
        for(a=0; a<= K; a++){ // count zero
            for(b=0; b<= K; b++){ // count one
                // append zero
                m = a + 1, n = b - 1; 
                if(n < 0) n = 0;
                if(m <= K)
                    cur[m][n] += pre[a][b];
                // append one
                m = a - 1, n = b + 1;
                if(m < 0) m = 0;
                if(n <= K)
                    cur[m][n] += pre[a][b];
            }
        }
        tmp = pre, pre = cur, cur = tmp;
    }
    long long ret = 0;
    for(a=0; a<= K; a++){
        for(b=0; b<=K; b++){
            ret += pre[a][b];
        }
    }
    printf("%lld\n", ret);
}

int main(){

    while(scanf("%d%d", &N, &K) > 0){
        fun();
    }

    return 0;
}

