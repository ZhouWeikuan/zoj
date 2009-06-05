#include<iostream>
using namespace std;
// wrong answer
long long A, B, C, K;

long long egcd(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1, y = 0; return a;
    }
    long long d = egcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

long long fun(){
    long long M = 1, d;
    long long x, y;
    M <<= K;
    K = (B - A + M) % M;
    d = egcd(M, C, x, y);
    if(K % d != 0) return -1;
    y *= (K / d);
    return y;
}

int readIn(){
    scanf("%lld%lld%lld%lld", &A, &B, &C, &K);
    return int(A + B + C + K);
}
int main(){
    long long t;
    while(readIn() > 0){
        t = fun();
        if(t < 0){
            printf("FOREVER\n");
        } else {
            printf("%lld\n", t);
        }
    }
    return 0;
}

