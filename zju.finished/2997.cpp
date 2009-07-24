#include<iostream>
using namespace std;
enum {
    SIZ = 5004,
};
// this use a diff system, I can't prove it is true...
// compared to 2997.other.cpp, it uses topology sort
// actually, they are the same..
int N, P, Q;
int sum[SIZ];
int dat[SIZ];

bool fun(){
    int i;
    memset(sum, 0, sizeof(sum));
    memset(dat, 0, sizeof(dat));
    bool flag = true;
    int v = 0;
    while(flag){
        flag = false;
        v = 0;
        for (i=0; i<=N; ++i){
            if (i+P<=N && sum[i] >= sum[i+P]){
                flag = true;
                sum[i+P] = sum[i] + 1;
            }
            if (i+Q<=N && sum[i] <= sum[i+Q]){
                flag = true;
                sum[i] = sum[i+Q] + 1;
            }
            v += sum[i]>0;
        }
        if (v > N)
            return false;
    }
    for (i=0; i<N; ++i){
        dat[i] = sum[i+1] - sum[i];
    }
    return true;
}

int readIn(){
    return scanf("%d%d%d", &N, &P, &Q) == 3;
}

void output(){
    int i;
    printf("%d", dat[0]);
    for (i=1; i<N; ++i)
        printf(" %d", dat[i]);
    printf("\n");
}

int main(){
    const char *ans[2] = {"NO", "YES"};
    while(readIn() > 0){
        int v = fun();
        printf("%s\n", ans[v]);
        if (v){
            output();
        }
    }

    return 0;
}

