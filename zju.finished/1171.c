#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int tstcase;
	int num;
	char pred;
	char now;
	int op;
	
	scanf("%d ", &tstcase );
	while(tstcase --){
		scanf("%d ", &num);
		num--;
		scanf("%c ", &pred);
		op = 0;
		while(num--){
			scanf("%c ", &now);
			if(now != pred){
				pred = now;
				op ++;
			}				
		}
		printf("%d\n",op );
		if(tstcase)
			printf("\n");
	}

	return 0;
}
