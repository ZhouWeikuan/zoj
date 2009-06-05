#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int coef[9];

void fun(){
    int first = 0;
	int i;

	for(i=8;i>=0;i--){
		if(coef[i] ==0)
			continue;
		if(first !=0){
			if(coef[i] > 0){
				printf(" + ");
			} else{
				printf(" - ");
				coef[i] = - coef[i];
			}
		} else {
			if(coef[i] < 0){
				printf("-");
				coef[i] = - coef[i];
			}		
		}
		if(i!= 0){
			if(coef[i] != 1)
				printf("%d", coef[i]);
		}else 
			printf("%d", coef[i]);
		if(i!=0){
			if(i==1)
				printf("x");
			else 
				printf("x^%d", i);
		}
		first++;
	}
	if(first ==0)
		printf("0");
	printf("\n");
}

int main(){
    int i;

	do {
		for(i=8;i>=0;i--){
			scanf("%d ", &coef[i]);
		}
		fun();	
	} 	while(!feof(stdin));
	
    return 0;
}
