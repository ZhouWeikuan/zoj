#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int base;
char buffer[200];
int num, sum;

void fun(){
    int i;
    int t;
    num = sum = 0;
    for(i=0; buffer[i] ;i++){
		t = buffer[i] - '0';
		num *= base;
		num += t;
		sum += t;
	}
	if(sum && num % sum == 0){
		printf("yes\n");
	} else {
		printf("no\n");
	}
}

int main(){
    int tstblk;
    scanf("%d", &tstblk);
    
    while(tstblk --){		
		scanf("%d", &base);
		while(base ){
			scanf("%s", buffer);
			fun();
			scanf("%d", &base);
		}
		if(tstblk )
			printf("\n");
	}
    
    return 0;
}
