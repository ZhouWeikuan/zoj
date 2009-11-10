#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int fun(int n){
	int left,  right;
	left = n/2;
	right = n- left;
	
	left = (left-1) * left /2;
	right = (right -1) *right /2;
	
	left += right;
	printf("%d\n", left);
}

int main(){
    int num;
    int n;
    
    scanf("%d", &num);	
	while(num --){
        scanf("%d", &n);
        fun(n);
    }
	
	return 0;
}
