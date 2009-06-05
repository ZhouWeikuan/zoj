#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 需要大整数支持 */

int mark[1008];

void init(){
    int i;
    int b0,b1,b2,b3,t;
    
    mark[0] = mark[1] = 0;
    mark[2] = 1;
    b0 = 1, b1 = 0, b2 = 0, b3 = 1;
    for(i=3;i<=1000;i++){
		mark[i] = 2 * mark[i-1];
		
		mark[i] += (b0 + b1 ==0) + (b3 + b0 ==0);		
		mark[i] -= (b1+b2==0);
		t = b0, b0 = b2, b2 = t;
	}   
    
}

int main(){
    int n;
    init();
    
    scanf("%d", &n);
    while(!feof(stdin)){
		
		printf("%d\n", mark[n]);
		
		scanf("%d", &n);
	}
    
    return 0;
}
