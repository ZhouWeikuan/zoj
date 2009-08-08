#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};

int n, x, y;

int main(){

    while(scanf("%d%d%d", &n,&x,&y) > 0){
        printf("%d\n", n-1);
    }

    return 0;
}

