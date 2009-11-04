#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int num;
int stack[20];
int pos;

int isPal(int base){
	static int digit[66];
	int n = num;
	int len = 0;
	int i;
	
	while(n){
		digit[len++] = n % base;
		n /= base;
	}
	i = 0, len --;
	while(i < len){
		if(digit[i] != digit[len]){
			return 0;
		}
		i ++, len--;
	}
	
	return 1;
}


void fun(){
	int i;
    pos = 0;
    for(i=2; i<= 16;i++){
		if(isPal(i)){
			stack[pos ++] = i;
		}
	}
	if(pos ==0){
		printf("Number %d is not a palindrom\n",num);
		return;
	}
	printf("Number %d is palindrom in basis", num);
	for(i=0;i<pos;i++){
		printf(" %d", stack[i]);
	}
	printf("\n");
}

int main(){
    
    scanf("%d", &num);
    while(num){
		fun();
		scanf("%d", &num);
	}
    
    return 0;
}
