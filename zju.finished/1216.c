#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 100000,	
};

double table[Size];

void init(){
	int i;
	for(i=1;i<Size;i++){
		table[i]	+=	table[i-1] + (double)0.5 /i;
	}
}

int main(){
	int num;
	
	init();	
	printf("# Cards  Overhang\n");
	
	scanf("%d", &num);
	while(! feof(stdin)){
		printf("%5d  %8.3lf\n", num, table[num]);
		scanf("%d", &num);
	}
	
	return 0;
}
