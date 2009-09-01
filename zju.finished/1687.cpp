#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 1<<13,
};
int N, S;
int val[20];
bool win[20][SIZ];

void fun(){
    int i, j;
    for (i=0; i<N; ++i){
        win[i][0] = true;
        win[i][1] = false;
    }
    for (j=2; j<=S; ++j){
        for (i=0; i<N; ++i){
            int b = (i+1)>=N?0:i+1;
            win[i][j] = false;
            for (int k=1; k<=val[i]&&k<=j; ++k){
                if (win[b][j-k] == false){
                    win[i][j] = true;
                    break;
                }
            }
        }
    }
    printf("%d\n", (int)win[0][S]);
}

int readIn(){
    scanf("%d", &N);
    if (N == 0) return 0;
    scanf("%d", &S);
    N *= 2;
    for (int i=0; i<N; ++i){
        scanf("%d", &val[i]);
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

