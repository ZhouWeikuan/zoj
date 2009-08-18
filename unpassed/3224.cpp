#include<iostream>
using namespace std;
uint64_t gcd(uint64_t a, uint64_t b){
    uint64_t t;
    if( a < b){
        t = a, a = b, b = t;
    }
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
uint64_t lcm(uint64_t a, uint64_t b){
    uint64_t t = gcd(a, b);
    b /= t;
    a *= b;
    return a;
}

uint64_t A, B, a;

void fun(){
    uint64_t l=1, r=a, ans = 0;
    uint64_t d = 1;
    while(r <= A){
        l = r;
        r *= a;
        ++d;
    }
    r = l * a;
    while (r <= B){
        ans += (r - l)/d;
        l  = r;
        r *= a;
    }
    if (l <= B){
        ans += 1 + (B - l ) / d;
    }
    printf("%lld\n", ans);
}

int readIn(){
    int n;
    if (scanf("%d%lld%lld", &n, &A,&B)<0)
        return 0;
    a = 1;
    uint64_t t;
    while(n--){
        scanf("%lld", &t);
        a = lcm(a, t);
    }

    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

