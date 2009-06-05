#include<stdio.h>

enum {
	Size = 60,
};

int stack[Size];
int num;
int sum;

int fun(){
    int i;
    sum = 0;
    for(i=0;i<num;i++){
    	scanf("%d",&stack[i]);
    	sum += stack[i];
	}
	int average = sum /num;
	sum = 0;
	for(i=0;i<num;i++){
		if(stack[i] < average){
			sum += average - stack[i];
		}
	}
	printf("The minimum number of moves is %d.\n",sum);
}

int main(){
    int tstcase = 1;
    scanf("%d",&num);
    while(num){		
		
		printf("Set #%d\n",tstcase++);
		fun();
		printf("\n");
		scanf("%d",&num);
	}
    
    return 0;
}
