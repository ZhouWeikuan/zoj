#include<iostream>
using namespace std;
enum {
    SIZ = 1004,
};
/*
 * 找规律，可以证明这样不会重复
 */ 
int n,s;

void output(int t){
    s = (2*n+1)/3;
    printf("%d %d %d\n", t, n, s);
    s = n - s;
    s++;
    int k = 1;
    printf("[%d,%d]",s,k);
    for(int i=s+1; i<=n; i++){
        k+=2;
        printf(" [%d,%d]", i, k);
        if(i==k){
            k=0;
        }
    }
    printf("\n");
}

int main(){
    int tstcase, ind = 0;
    scanf("%d",&tstcase);
    while(tstcase --){
        scanf("%d", &n);
        output(++ind);
    }

    return 0;
}

