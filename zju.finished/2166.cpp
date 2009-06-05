#include<iostream>
using namespace std;
// 最好的就是最简单的,从最小的开始算 1/a + 1/b + 1/c...
// 如果只有一项,直接判断
// 有很多项,则可以分解为1/a + p/q的形式,并且 a*q<=当前限制
int P, Q, A, N;

int gcd(int a, int b){
    int t;
    if(a < b){
        t = a, a = b, b = t;
    }
    while(b!=0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// 从现在起第一项1/s中 s>=v且s*nq<=a
int count(int v, int p, int q, int a, int n){
    int ret = 0;
    if(p == 1 && q >= v){
        ret++;
    }
    if(n<=1) return ret;
    int t, r, s;
    int np, nq;
    for(s = v; s*s<=a; s++){
        np = p*s-q;
        nq = q*s;
        t = gcd(nq, np);
        nq /= t;
        if(np < 0 || s*nq>a){
            continue;
        }
        np /= t;
        ret += count(s, np, nq, a/s, n-1);
    }
    return ret;
}
void fun(){
    int t = gcd(P, Q);
    P /= t;
    Q /= t;
    int ret = count(1, P, Q, A, N);
    printf("%d\n", ret);
}
int readIn(){
    scanf("%d%d%d%d",&P,&Q,&A,&N);
    return P + Q + A + N;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

