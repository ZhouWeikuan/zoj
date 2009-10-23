#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
// Range Minimum Query
using namespace std;
enum {
    SIZ = 128,
    LOG = 8,
};

int num;
int dat[SIZ];
int M[SIZ][LOG];

void preprocess(){
    int i, j;
    for (i=0; i<num; ++i)
        M[i][0] = i;
    for (j=1; (1<<j) <= num; ++j){
        for (i=0; i+(1<<j) <= num; ++i){
            if (dat[M[i][j-1]] < dat[M[i+(1<<(j-1))][j-1]]){
                M[i][j] = M[i][j-1];
            } else {
                M[i][j] = M[i+(1<<(j-1))][j-1];
            }
        }
    }
}

int query(int s, int e){
    int k = (int)log2(e-s+1);
    if (dat[M[s][k]] < dat[M[e+1-(1<<k)][k]]){
        return M[s][k];
    } else {
        return M[e+1-(1<<k)][k];
    }
}


int main(){
    num = 10;
    for (int i=0; i<num; ++i)
        dat[i] = i;
    random_shuffle(dat, dat+num);
    preprocess();
    for (int i=0; i<num; ++i){
        printf("%d ", dat[i]);
    }
    printf("\n");
    while(1){
        int s, e;
        scanf("%d%d", &s, &e);
        s = query(s, e);
        printf("%d\n", dat[s]);
    }

    return 0;
}

