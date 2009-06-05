#include<iostream>
using namespace std;
unsigned prime[4800]= {2,3}, pos=2;
unsigned M, N;

int fun(){
    if(N == 0) return 0;
    if(N <= M) return 1;
    unsigned n = N;
    int t, p, i;
    for(i=0; prime[i]<=n; i++){
        t = 0;
        while(n % prime[i] == 0) {
            n /= prime[i];
            ++t;
        }
        if(t==0) continue;
        p = M;
        while(p>0 && t>0){
            p /= prime[i];
            t -= p;
        }
        if(t > 0)  return 0;
    }
    // maybe n is prime and greater than prime[pos-1]
    t = 1;
    p = M;
    while(p>0 && t > 0){
        p /= n;
        t -= p;
    }
    if(t > 0) return 0;
    return 1;
}
void init(){
    unsigned lim = 1<<31, t;
    int i;
    for(t=5; t*t < lim; t+=2){
        prime[pos++] = t;
        for(i=0; prime[i]*prime[i]<= t; i++){
            if(t % prime[i] == 0){
                --pos;
                break;
            }
        }
    }
    prime[pos] = lim;
}
int main(){
    init();
    while( scanf("%u%u",&M,&N) > 0){
        printf("%u ", N);
        if( fun() ){
            printf("divides");
        }else{
            printf("does not divide");
        }
        printf(" %u!\n", M);
    }
    return 0;
}

