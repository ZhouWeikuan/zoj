#include<iostream>
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
        int t = i + (i+1)*i;
        t %= n;
        dat[t] = '0';
    }
    dat[n-1] = 0;
    printf("%s\n", dat);
}

int main(){

    scanf("%d ", &n);
    while(n > 0){
        fun();
        scanf("%d ", &n);
    }

    return 0;
}

