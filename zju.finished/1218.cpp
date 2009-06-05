#include<iostream>
using namespace std;
int N, M;
double r;

int gcd(int a, int b){
    int t;
    while( b ){
        t = a % b;
        a =b;
        b = t;
    }
    return a;
}

void reduce(){
    int t;
    if(N>=M){
        t = gcd(N,M);
    } else {
        t = gcd(M,N);
    }
    N /= t;
    M /= t;
}

double test(int a, int b){
    double nr = abs(N * b - a * M);
    nr /= b;
    nr /= M;
    return nr;
}

int fun(){
    r = 10000;
    int a, b;
    double nr1, nr2;
    for(b = 1;b<=M;b++){
        a = b * N;
        a /= M;
        nr1 = test(a, b);
        nr2 = test(a+1,b);
        if(nr1 < r ){
            if(nr2 <= nr1){
                printf("%d/%d\n", a+1, b);
                r = nr2;
            }else {
                printf("%d/%d\n", a, b);
                r = nr1;
            }
        } else if(nr2 < r) {
            printf("%d/%d\n", a+1, b);
            r = nr2;
        }
    }
}

int main(){
    int tstcase = 0;
    while(scanf("%d%d",&N, &M)>0){
        if(tstcase ++)
            printf("\n");
        reduce();
        fun();
    }

	return 0;
}
