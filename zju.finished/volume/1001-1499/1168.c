#include<stdio.h>

enum {
	Size = 21 * 21 *21,	
};

int value[Size];

int fun(int a, int b, int c ){
	if(a <=0 || b<=0 || c<=0)
		return 1;
	if(a>20|| b>20 || c>20)
		return fun(20,20,20);
	int key = a*21*21 + b *21 + c;
	if(value[key])
		return value[key];
	int sum;
	if(a < b && b < c){
		sum = fun(a,b,c-1) + fun(a,b-1,c-1)	- fun(a,b-1,c);
	} else {
		sum = fun(a-1,b,c) + fun(a-1,b-1,c) + fun(a-1,b,c-1) - fun(a-1,b-1,c-1);	
	}
	
	value[key] = sum;	
	return sum;
}

int main(){
	int t;
	int a,b,c;	
	
	scanf("%d%d%d", &a, &b, &c);	
	while(a != -1 || b != -1 || c != -1){
		t = fun(a,b,c);
		printf("w(%d, %d, %d) = %d\n",a,b,c,t);
		scanf("%d%d%d", &a, &b, &c);	
	}
	return 0;
}
