#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 1008,
};

int coach[Size];
int num;

int fun(){
	int max = -1;
	int i,j;
	
	for(i=0;i<num;i++){
		if(coach[i] > max){
			max = coach[i];
			int t = max;
			for(j=i+1;j < num;j++){
				if(coach[j] < max ){
					if(coach[j] > t){
						return 0;
					} else {
						t = coach[j];
					}
				}
			}
		}
	}
	return 1;
}

int main(){
	int tstcase = 0;
	int i;
	
	scanf("%d", &num);
	while(num){
		scanf("%d", &coach[0]);
		while(coach[0]){
			for(i=1;i<num;i++){
				scanf("%d", &coach[i]);
			}
			
			if(fun()){
				printf("Yes\n");
			}else {
				printf("No\n");
			}
			
			scanf("%d", &coach[0]);
		}
		
		printf("\n");
		scanf("%d", &num);
	}	

	return 0;
}
