#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 求 n的错位排列:  n!(1 -1/1! + 1/2! + ... + (-1)^n *1/n! ) */
/* D(n) = (n-1) * (D(n-1) + D(n-2)) */

void fun(int n, int m){
    int i;
    int sign = -1;
    n -= m;
    double v=1,ret=1;
    
    
    for(i=1; i<= n; i++){
        v /= i;
        ret += sign * v;
        sign = - sign;
	}
    for(i=1;i<=m;i++){
        ret /= i;
    }
	printf("%.8lf\n", ret);
}

int main(){
    int n,m;
    
    scanf("%d %d", &n, &m);
    while(!feof(stdin) ){
		fun(n,m);		
		scanf("%d %d", &n, &m);
	}
    
    return 0;
}
