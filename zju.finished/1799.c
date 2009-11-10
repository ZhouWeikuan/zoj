#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char keyword[12];
int ksort[12];
char buffer[120];
char column[12][12];
int row,col;

int mycomp(const int *a, const int *b){
	return keyword[*a] - keyword[*b];
}

void fun(){
	int i,j;
	for(i=0; i<col;i++)
		ksort[i] = i;
	row = strlen(buffer);
	row /= col;
	qsort(ksort,col,sizeof(int), mycomp);
	for(i=0;i<col;i++){
		strncpy(column[ksort[i]], buffer+i*row,row);
	}
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%c",column[j][i]);
		}
	}
	printf("\n");
}

int main(){

	scanf("%s", keyword);
	while(strcmp(keyword,"THEEND")!=0){
		scanf("%s",buffer);
		col = strlen(keyword);
		fun();
		
		scanf("%s", keyword);
	}

	return 0;
}
