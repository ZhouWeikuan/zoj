#include<iostream>
// TLE
using namespace std;

int n;
int c[12];
double ans, tmp;
int a, b;

void fun(){
    ans = 0;
    for (int t=a; t<=b; ++t){
        tmp = 0;
        for (int i=n; i>=0; --i){
            tmp *= t;
            tmp += c[i];
        }
        ans += tmp;
    }
    printf("%.6e\n", ans);
}

int readIn(){
    if (scanf("%d", &n) < 0)
        return 0;
    for (int i=n; i>=0; --i)
        scanf("%d", &c[i]);
    scanf("%d%d", &a, &b);
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

