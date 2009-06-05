#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
int R, C, v0, v1;
int mat[SIZ][SIZ];

int fun(){
}

void readIn(){
    int i, j;
    scanf("%d%d%d%d", &R, &C, &v0, &v1);
    for(i=0; i
}
int main(){
    int tst;
    scanf("%d", &tst);
    for(int i=1; i<=tst; i++){
        printf("Case %d:\n", i);
        readIn();
        printf("%d\n", fun());
        if(i != tst) printf("\n");
    }

    return 0;
}

