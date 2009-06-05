#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int par,stroke;

void fun(){
	if(par == stroke){
		printf("Par.\n");
	}else if(par > stroke){
		if(par -1 == stroke){
			printf("Birdie.\n");
		}else if(par -2==stroke){
			if(stroke==1){
				printf("Hole-in-one.\n");
			}else{
				printf("Eagle.\n");
			}
		}else {
			printf("Double Eagle.\n");
		}
	}else {
		if(par +1 == stroke){
			printf("Bogey.\n");
		}else{
			printf("Double Bogey.\n");
		}		
	}

}

int main(){
	int tstcase = 1;
	
	scanf("%d %d", &par, &stroke);
	while(par > 0){
		printf("Hole #%d\n",tstcase ++);
		fun();
		printf("\n");
		scanf("%d %d", &par, &stroke);
	}

	return 0;
}
