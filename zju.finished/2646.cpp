#include<iostream>
using namespace std;

// 利用余数的数列性质
int direct(int n, int k){
    int ret = 0;
    while(n>=2){
        ret += k%n;
        n--;
    }
    return ret;
}
long long fun(int n, int k){
    long long ret = 0;
    long long diff, s, e;
    if(n<= 100){
        return direct(n, k);
    }
    if(n >= k){
        ret = k;
        ret *= (n-k);
        n = k - 1;
    }
    while(n > 100){
        // calc current diff
        diff = k / n + 1;
        s = k % n;
        e = k / diff + 1; 
        ret += (s + k%e) * (n - e + 1)/2;

        n = e-1;
    }
    ret += direct(n, k);
    return ret;
}
int main(){
    int n,k;    
    scanf("%d",&n);
    while(!feof(stdin)){
        scanf("%d", &k);
        printf("%lld\n", fun(n, k));
        scanf("%d",&n);
    }
    return 0;
}

