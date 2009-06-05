#include<iostream>
using namespace std;
// triple = total - non-triple
// non-triple = (sum xi*yi)/2 for each ai, ai has x prime, y non-prime
// total = n*(n-1)*(n-2)/6
enum {
    SIZ = 508,
};
int num;
int d[SIZ];

int gcd(int a, int b){
    int t;
    if(a < b){
        t = a, a=b, b = t;
    }
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int fun(){
    int total = num *(num-1)*(num-2)/6;
    int non = 0;
    int p,np;
    int i,j;
    for(i=0; i<num; i++){
        p = np = 0;
        for(j=0; j<num; j++){
            if(i==j) continue;
            if(gcd(d[i], d[j]) > 1){
                np ++;
            } else {
                p++;
            }
        }
        non += p * np;
    }
    non /= 2; // 因为两个相同，一个不同，因此是相同的那两个重复了
    total -= non;
    return total;
}

int readIn(){
    if(scanf("%d",&num)<0)
        return 0;
    for(int i=0; i<num; i++){
        scanf("%d", &d[i]);
    }
    return 1;
}

int main(){
    while(readIn() > 0){
        printf("%d\n", fun());
    }
    return 0;
}

