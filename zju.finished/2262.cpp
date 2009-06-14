#include<iostream>
using namespace std;
enum {
    N = 8,
    SIZ = 32,
};

unsigned dat[N];

void fun(){
    unsigned carry = 0;
    unsigned key = 0;
    for (int i=0; i<SIZ; ++i){
        unsigned s0 = 0, s1 = 0;
        unsigned b = 1<<i;
        for (int j=0; j<N; ++j){
            s0 += (dat[j] ^ 0) & b;
            s1 += (dat[j] ^ b) & b;
        }
        if (((s0+carry)&b) == ((dat[N]^0)&b)){
            carry += s0;
        } else {
            key |= b;
            carry += s1;
        }
    }
    printf("%x\n", key);
}

void readIn(){
    for (int i=0; i<N; i++){
        scanf("%x ", &dat[i]);
    }
    scanf("%x ", &dat[N]);
}

int main(){
    int tst;

    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

