#include<iostream>
using namespace std;
enum {
    SIZ = 2000008,
    MOD = 1000000,
    DIG = 21,
};
int fac[DIG];
int part[SIZ];
int num;

void init(){
    int i, t;
    for(int i=0; i<DIG; i++){
        fac[i] = 1<<i;
    }
    part[0] = 1;
    for(i=0; i<DIG; i++){
        for(t=fac[i]; t<SIZ; t++){
            part[t] += part[t-fac[i]];
            if(part[t] >= MOD){
                part[t] -= MOD;
            }
        }
    }
}
int main(){
    int tstcase;
    init();
    scanf("%d", &tstcase);
    while(tstcase--){
        scanf("%d", &num);
        printf("%d\n", part[num]);
    }
    return 0;
}

