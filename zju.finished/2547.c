#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ways[32][3];
int  num;

void init(){
	int i;
	ways[0][0] = 1;
	ways[1][0] = 0;
	ways[1][1] = 1;
	ways[1][2] = 0;
	ways[2][0] = 3;
	ways[2][1] = 0;
	ways[2][2] = 1;
	for(i=3;i<31;i++){
		ways[i][0] = ways[i-2][0] + 2 *ways[i-1][1];
		ways[i][1] = ways[i-1][0] + ways[i-1][2];
		ways[i][2] = ways[i-1][1];
	}
}

int main(){
	int num;

	init();
	scanf("%d", &num);
	while(num >= 0){
		printf("%d\n", ways[num][0]);
		
		scanf("%d", &num);
	}
	return 0;
}
