#include<iostream>
using namespace std;
enum {
    SIZ = 1004,
    N = 16,
};
int dat[SIZ][N];

void init(){
    int i,j;
    memset(dat[0], 0, sizeof(dat[0]));
    dat[0][0] = 1;
    memset(dat[1], 0, sizeof(dat[1]));
    dat[1][0] = 1, dat[1][3] = dat[1][12] = 1;
    dat[1][9] = dat[1][15] = 1;
    for (i=2; i<SIZ; i++){
        dat[i][1] = dat[i-1][8] + dat[i-1][2] + dat[i-1][14];
        dat[i][2] = dat[i-1][1] + dat[i-1][13];
        dat[i][3] = dat[i-1][0] + dat[i-1][12];
        dat[i][0] = dat[i][3] + dat[i-1][9] + dat[i-1][3] + dat[i-1][15];
        dat[i][4] = dat[i][2];
        dat[i][5] = dat[i-1][10];
        dat[i][6] = dat[i-1][9];
        dat[i][7] = dat[i-1][8];
        dat[i][8] = dat[i][1];
        dat[i][9] = dat[i-1][0] + dat[i-1][6];
        dat[i][10] = dat[i-1][5];
        dat[i][11] = dat[i-1][4];
        dat[i][12] = dat[i][3];
        dat[i][13] = dat[i][11];
        dat[i][14] = dat[i][7];
        dat[i][15] = dat[i-1][0];
    }
}

void fun(){
}

int readIn(){
}

int main(){
    init();
    int tst, n, num=1;
    scanf("%d ", &tst);
    while(tst-- > 0){
        scanf("%d ", &n);
        printf("%d %d\n", num++, dat[n][0]);
    }

    return 0;
}

