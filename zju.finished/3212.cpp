#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 16,
};
int n, m, k;
char mat[SIZ][SIZ];
char move[4][2] = {
    {-1, 0}, {1, 0},
    {0, -1}, {0, 1}
};

void updateAdj(int x, int y){
    mat[x][y] = 0;
    for (int i=0; i<4; i++){
        mat[x+move[i][0]][y+move[i][1]] = 0;
    }
}

void update(){
    int i, j;
    for (i=1; i<n-1; i++){
        for (j=1; j<m-1; j++){
            if (k==0) return;
            updateAdj(i, j);
            --k;
        }
    }
}

void fun(){
    memset(mat, 1, sizeof(mat));
    update();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%s%d", j?" ":"", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int tst;

    scanf("%d ", &tst);

    while(tst-- > 0){
        scanf("%d%d%d ", &n, &m, &k);
        fun();
    }

    return 0;
}

