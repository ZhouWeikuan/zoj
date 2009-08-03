#include<iostream>
using namespace std;
enum {
    SIZ = 30,
};
int dat[SIZ];

void init(){
    dat[0] = 0;
    dat[1] = 1;
    for (int i=2; i<SIZ; ++i){
        dat[i] = 1 + dat[i-1] + 2 * dat[i-2];
    }
}

int main(){
    init();
    int tst, n;
    scanf("%d", &tst);
    while(tst--){
        scanf("%d", &n);
        printf("%d\n", dat[n]);
    }

    return 0;
}

