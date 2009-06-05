#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 20,
};
char dat[SIZ];

void fun(){
    if(strcmp(&dat[1],"000000000000000")==0){
        printf(" 0.000000e+000\n");
        return;
    }
    bool neg = dat[0]=='1';
    double val, p, iter;
    int i;

    p = 0;
    for(i=1; i<8; i++){
        p *= 2;
        if(dat[i]=='1'){
            p += 1;
        }
    }
    p -= 63;
    p = pow(2.0, p);
    val = iter = 1.0;
    for(i=8; i<16; i++){
        iter /= 2;
        if(dat[i]=='1'){
            val += iter;
        }
    }
    val *=p;
    p = 0;
    if(val >= 10.00){
        while(val >= 10.00){
            val /= 10; p++;
        }
    } else if(val < 1.00){
        while(val < 1.00){
            val *= 10; p--;
        }
    }
    i = (int)p;
    printf("%s", neg?"-":" ");
    printf("%.6lfe%+04d\n", val, i);
}

int main(){
    printf("Program 6 by team X\n");
    while(scanf("%s", dat) > 0){
        fun();
    }
    printf("End of program 6 by team X\n");
    return 0;
}

