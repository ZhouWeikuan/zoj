#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};
int N;
int dat[SIZ];

void fun(){
    int i;
    dat[0] = 0;
    for (i=1; i<=N; ++i){
        dat[i-1] = i*dat[i];
    }
}

void readIn(){
    scanf("%d ", &N);
    for(int i=N; i>=0; --i){
        scanf("%d ", &dat[i]);
    }
}

void output(){
    int i;
    printf("%d", dat[N-1]);
    for(i=N-2; i>=0; --i){
        printf(" %d", dat[i]);
    }
    printf("\n");
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
        output();
    }

    return 0;
}

