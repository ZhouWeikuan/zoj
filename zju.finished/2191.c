#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 10008,
};

int a,b,c;

int fun(int x){
	return a*x*x + b *x + c;
}

int main(){
	int x,y;

	scanf("%d %d %d", &c, &x, &y);
	while(! feof(stdin) ){
		a = (y +c - 2*x)/2;
		b = x - a - c;
		
		printf("%d %d %d\n", fun(3),fun(4),fun(5));
		
		scanf("%d %d %d", &c, &x, &y);
	}	

	return 0;
}
