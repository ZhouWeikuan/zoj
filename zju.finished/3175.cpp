#include<iostream>
#include<cmath>
using namespace std;
/*
 * See the attached ps file 3175.ps
 *      originally, F(n) = n/1 + n/2 + n/3 + ... + n/n - n
 *      set H(n) = n/1 + n/2 + n/3 + ... + n/n
 *      this equals to all integer points no greater than y = n / x
 *          This is A + B + C + D
 *      set s = sqrt(n)
 *      then set P(s) = n/1 + n/2 + n/3 + ... + n/s
 *      P(s) equals to part A + part B + part C
 *          and we know D equals to C
 *      2*P(s) equals 2*(A+B)+C+D
 *      2*P(s) - A - B equals to A + B + C + D
 *      A + B = s * s
 *
 *  above all, F(n) = A + B + C + D - n
 *                  = 2*P(s) - s*s - n
 *  this is copied from 
 *  http://hi.baidu.com/auhsr2346/blog/item/e35b5c8cdff76e1ab31bba86.html
 *      but his explanation is wrong.
 */

void F(int n){
    long long ans = 0, t;
    int lim = sqrt(n);
    for (int i=1; i<=lim; ++i){
        ans += n/i;
    }
    t = lim;
    t *= lim;
    ans *= 2;
    ans -= t;
    ans -= n;
    printf("%lld\n", ans);
}

int main(){
    int tn, n;
    scanf("%d", &tn);
    while(tn--){
        scanf("%d", &n);
        F(n);
    }

    return 0;
}

