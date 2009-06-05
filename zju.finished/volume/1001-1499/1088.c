#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int test(int left,int step){
	int start = 0,sum = 0;
	step --;
	while(left > 1){
		left --;
		start += step;
		while(start >= left){
			start -= left;
		}
		if(start ==0)
			break;
	}
	return left == 1;
}

int fun(int num){
	int i= 2;

	for(;;i++){
		if(test(num,i)){
			return i;
		}
	}
	return 0;
}

int main(){
	int n;

	scanf("%d", &n);
	while(n > 0){
		printf("%d\n", fun(n));
		scanf("%d", &n);
	}

	return 0;
}
