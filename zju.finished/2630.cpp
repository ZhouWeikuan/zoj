#include<iostream>
#include<cstdio>
#include<stdint.h>
using namespace std;
/*
 * Copy from Internet that the formula is:
 *  II (a+b+c-1)/(a+b+c-2) for each a, b, c
 */

int a, b, c;
uint64_t  up =1, down = 1; 

uint64_t gcd(uint64_t a, uint64_t b){
    uint64_t t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void Add(int u, int d){
    up *= u, down *= d;
    uint64_t g = gcd(up, down);
    if (g > 1){
        up /= g;
        down /= g;
    }
}

void fun(){
    up = 1, down = 1;
    for (int i=1; i<=a; i++){
        for (int j=1; j<=b; j++){
            for(int k=1; k<=c; k++){
                Add(i+j+k-1, i+j+k-2);
            }
        }
    }

    printf("%llu\n", up);
}

int readIn(){
    return scanf("%d%d%d ", &a, &b, &c) > 0;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

