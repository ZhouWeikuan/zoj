#include<iostream>
using namespace std;
enum {
    SIZ = 28,
};
int num;
int dat[SIZ];

void readIn(){
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        scanf("%d", &dat[i]);
    }
    sort(dat, dat+num);
    printf("%d\n", 2*(dat[num-1] - dat[0]));
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst --){
        readIn();
    }
    return 0;
}

