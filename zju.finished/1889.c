#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int num;

void fun(){
    int sum = 1;
    int pred = 1;
    int digit = 1;
    
    while(sum % num != 0){		
		pred *= 10;
		pred %=  num;
		sum += pred;
		sum %= num;
		digit ++;
	}
    
    printf("%d\n", digit);
}

int main(){    
    scanf("%d",&num);
    while(!feof(stdin)){
		fun();
		scanf("%d",&num);
	}
    
    return 0;
}
