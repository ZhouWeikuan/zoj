#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int num;
    int n;
    int t;
	scanf("%d ", &num);
	
	while(num --){
		t = 0;
		scanf("%d ", &n);
		while(n >= 5){
			n /= 5;
			t += n;
		}		
		printf("%d\n", t);
	}
    
    return 0;
}
