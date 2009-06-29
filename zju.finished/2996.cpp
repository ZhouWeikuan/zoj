#include<iostream>
using namespace std;

int n, m;

int calc(int s){
    int r = 0;
    while(s > 0){
        s /= 2;
        r += s;
    }
    return r;
}

void fun(){
    int u = 0, d = 0;
    u = calc(n);
    d = calc(m);
    d += calc(n-m);
    printf("%d\n", (u<=d));
}

int main(){

    while(scanf("%d%d ", &n, &m) > 0){
        fun();
    }

    return 0;
}

