#include<iostream>
using namespace std;
enum {
    SIZ = 100004,
};
int N, S;
int sum[SIZ];

void fun(){
    int m = SIZ;
    int l=0, r=1;
    while(r <= N){
        while(r <= N && sum[r] - sum[l] < S){
            ++r;
        }
        if (r > N)
            break;
        while(sum[r] - sum[l] >= S){
            if (r - l < m) m = r - l;
            ++l;
        }
    }
    if (m > N) m = 0;
    printf("%d\n", m);
}

void readIn(){
    scanf("%d%d ", &N, &S);
    sum[0] = 0;
    for (int i=1; i<=N; i++){
        scanf("%d ", &sum[i]);
        sum[i] += sum[i-1];
    }
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

