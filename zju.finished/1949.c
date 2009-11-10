#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 108,	
};

char matrix[Size][Size];
char row[Size];
char col[Size];
int num;

int fun(){
    int i,j;
    for(i=0;i<num;i++){
		row[i] = 0;
		col[i] = 0;
		for(j=0;j<num;j++){
			row[i] += matrix[i][j];
			col[i] += matrix[j][i];
		}
		row[i] %= 2;
		col[i] %= 2;
	}
	
	int flag = 1;
	int a,b;
	for(i=0;i<num;i++){
		if(row[i]){
			for(j=0;j<num;j++){
				if(col[j]){
					if(flag){
						a = i;
						b = j;
						row[i] = 0;
						col[j] = 0;
						matrix[i][j] = 1 - matrix[i][j];
						flag = 0;
					} else {
						return 1;
					}
				}
			}
			if(flag)
				return 1;
		}
		if(col[i]){
			for(j=0;j<num;j++){
				if(row[j]){
					if(flag){
						a = j;
						b = i;
						row[j] = 0;
						col[i] = 0;
						matrix[j][i] = 1 - matrix[j][i];
						flag = 0;
					} else {
						return 1;
					}
				}
			}
			if(flag)
				return 1;
		}
	}
	if(flag == 1)
		return 0;
	printf("Change bit (%d,%d)\n", a+1,b+1);
	return 2;
}

const char * ans[2] = {
	"OK",
	"Corrupt"
};

int main(){
	int i,j;
	
	scanf("%d", &num);
	while(num){
		for(i=0;i<num;i++){
			for(j=0;j<num;j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		i = fun();
		if(i < 2){
			printf("%s\n", ans[i]);
		}
		scanf("%d", &num);
	}
    
    return 0;
}
