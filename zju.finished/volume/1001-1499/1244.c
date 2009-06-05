#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 26,
};

char buffer[Size];

int main(){
	int tstcase = 1;
	int num,i;
	char first, second;
	
	scanf("%d ", &num);
	while(num){
		memset(buffer,0,sizeof(buffer));
		buffer[0] = 1;
		printf("Program #%d\n", tstcase ++);
		while(num--){
			scanf("%c = %c ", &first,&second);
			buffer[first-'a'] = buffer[second -'a'];
		}
		first = 1;
		for(i=0;i<Size;i++){
			if(buffer[i]){
				if(first){
					first = 0;					
				}
				printf("%c ",i +'a');				
			}
		}
		if(first)
			printf("none");
		printf("\n\n");

		scanf("%d ", &num);
	}

	return 0;
}
