#include<iostream>
#include<string.h>
using namespace std;
enum {
    SIZ = 1008,
};

int N, M;
int dat[SIZ];
int mat[SIZ];

void fun(){
    int i, j, k;
    memset(dat, 0, sizeof(dat));
    for (i=0; i<N; i++)
    {
        for (j=0; j<M; j++)
        {
            scanf("%d ", &mat[j]);
        }
        for (j=M-1; j>=0; j--)
        {
            if (mat[j] <= 0)
                continue;

            k = j - mat[j];
            dat[j] = 1;
            for(j--; j>=k&&j>=0; j--)
            {
                if (mat[j]==0)
                    continue;
                dat[j] = 0;
                k = min(j-mat[j], k);
                k = max(k, 0);
            }
            ++j;
        }
    }
    k = 0;
    for(j=0; j<M; j++){
        k += dat[j];
    }
    printf("%d\n", k);
}

int readIn(){
    return (scanf("%d%d ", &N, &M) > 0);
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

