#include<iostream>

using namespace std;
enum {
    SIZ = 108,
};
int num, val;
int cof[SIZ];
char buf[SIZ];

void fun(){
    int cost = 2, ret = val;    // x =, the initial value 
    --num;
    for(int i=num; i>=0; i--){
        // a * x ?
        if(i != num){
            cost += 2;
            ret *= val;
        }
        // + cof[i] ?
        if(cof[i]){
            ret  += cof[i];
            cost += 1 + sprintf(buf, "%d", cof[i]);
        }
    }
    printf("%d %d\n", ret, cost);
}

int readIn(){
    scanf("%d", &num);
    if( num ) {
        for(int i=num; i>=0; i--){
            scanf("%d", &cof[i]);
        }
    }
    scanf("%d", &val);
    return (num || val);
}

int main(){
    int tst = 0;
    while(readIn() > 0){
        printf("Polynomial %d: ", ++tst);
        fun();
    }    
    return 0;
}

