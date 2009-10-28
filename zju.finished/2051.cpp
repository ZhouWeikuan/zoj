#include<iostream>
#include<cstdio>
using namespace std;
enum {
    SIZ = 100004,
};

int N, K;
char dat[SIZ];

void fun(){
    int s = 0, e;
    int sum = 0, ans = K*9+1, L=-1;
    for (e=0; e<N; ++e){
        if (dat[e] == '*'){
            s = e + 1;
            sum = 0;
            continue;
        }
        sum += dat[e] - '0';
        if (e-s+1>=K){
            if (sum < ans){
                ans = sum;
                L = s;
            }
            sum -= dat[s] - '0';
            ++s;
        }
    }
    ++L;
    printf("%d\n", L);
}

void readIn(){
    scanf("%d%d ", &N, &K);
    for (int i = 0; i<N; i+=80){
        scanf("%s", &dat[i]);
    }
}

int main(){
    int bn;
    scanf("%d", &bn);
    // bn = 1;
    while(bn-- > 0){
        readIn();
        fun();
        if (bn)
            printf("\n");
    }

    return 0;
}

