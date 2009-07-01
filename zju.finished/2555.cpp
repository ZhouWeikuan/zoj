#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 100008,
};
int n;
char dat[SIZ];

void fun(){
    if (n == 2){
        printf("Impossible\n");
        return;
    }
    memset(dat, '1', sizeof(dat));
    for (int i=0; i<n/2; i++){
        long long t = i;
        t = t + (t+1)*t;
        t %= n;
        dat[t] = '0';
    }
    dat[n-1] = 0;
    printf("%s\n", dat);
}

int main(){

    scanf("%d ", &n);
    while(n > 0){
        fprintf(stderr, "%d\n", n);
        fun();
        scanf("%d ", &n);
    }

    return 0;
}

