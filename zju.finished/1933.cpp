#include<iostream>
using namespace std;
enum {
    SIZ = 20,
};
char input[SIZ];
typedef unsigned long long uint64;
uint64 n,d;
uint64 tab[SIZ];

void init(){
    tab[0] = 1;
    for(int i=1; i<SIZ; i++){
        tab[i] = tab[i-1]*10;
    }
}
uint64 gcd(uint64 a, uint64 b){
    uint64 t;
    while(b != 0){
        t = a % b;
        a = b; 
        b = t;
    }
    return a;
}

void fun(){
    int i, s;
    d = -1;
    for(i=2; input[i]!='.'; i++){
        input[i-2] = input[i];
    }
    i -= 2;
    input[i] = 0;
    uint64 a = 0, b, t;
    uint64 v = atoi(input), p = 0;
    for(s=0; s<i; s++){
        a = v - p;
        b = tab[i] - tab[s];
        t = gcd(b, a);
        b /= t;
        a /= t;
        if( b < d){
            d = b; n = a;
        }
        p *= 10;
        p += (input[s] - '0');
    }
    printf("%llu/%llu\n", n, d);
}

int main(){
    init();

    scanf("%s", input);
    while(input[1] =='.'){
        fun();
        scanf("%s", input);
    }
    return 0;
}

