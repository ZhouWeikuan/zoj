#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 1000008,
    MOD = 1000000,
};
int part[SIZ];
int num;

void init(){
    int a, b;
    part[0] = 1;
    part[1] = 2;
    a = 1; b = 2;
    while(b <= 1000000){
        part[b] = part[b-1] + part[a];
        if(part[b] >= MOD) part[b] -= MOD;
        ++b;
        part[b] = part[b-1] + part[a];
        if(part[b] >= MOD) part[b] -= MOD;
        ++b;
        ++a;
    }
}
int main(){
    int tstcase;
    init();
    scanf("%d", &tstcase);
    while(tstcase--){
        scanf("%d", &num);
        printf("%d\n", part[num/2]);
    }
    return 0;
}

