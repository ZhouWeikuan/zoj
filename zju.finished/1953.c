#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int first;
	int second;
} Node;

enum {
	Up = 1,
	Left = 2,
	Corner = 3,
};

char first[108];
char second[108];
int firstlen;
int secondlen;
int point[108][108];		/* 1-> up, 2->left, 3 ->left up */
int matrix[108][108];
Node match[108];
int pos;

void fun(){
    int i,j;
    for(i=0;i<firstlen;i++){
		if(first[i] == second[0] ){
			point[i][0] = Corner;
			matrix[i][0] = 1;
		} else {
			point[i][0] = Left;
			matrix[i][0] = i==0?0:matrix[i-1][0];
		}		
	}
	for(j=1;j<secondlen;j++){
		if(first[0] == second[j]){
			point[0][j] = Corner;
			matrix[0][j] = 1;
		} else {
			point[0][j] = Up;
			matrix[0][j] = (j>0)?matrix[0][j-1]:0;
		}
		
	}
    for(i=1;i<firstlen;i++){
		for(j=1;j<secondlen;j++){
			if(first[i] == second[j]){
				point[i][j] = Corner;
				matrix[i][j] = matrix[i-1][j-1] + 1;
			} else {
				if(matrix[i-1][j] > matrix[i][j-1]){
					point[i][j] = Left;
					matrix[i][j] = matrix[i-1][j];
				} else {
					point[i][j] = Up;
					matrix[i][j] = matrix[i][j-1];
				}
			}
		}	
	}
	i = firstlen -1;
	j = secondlen -1;
	pos = matrix[i][j];
	int k = pos-1;
	while(i >=0 && j >= 0){
		if(point[i][j] == Corner){
			match[k].first = i;
			match[k].second = j;
			k--;
			i--;
			j--;
		} else if(point[i][j] == Left) {
			i--;
		} else { /*  Up */
			j--;
		}		
	}
	i =0,j=0; k = 0;
	while(k < pos){
		while(i < match[k].first){
			printf("%c", first[i]);
			i++;
		}
		while(j < match[k].second){
			printf("%c", second[j]);
			j++;
		}
		printf("%c", first[i]);
		i ++, j++, k++;
	}
	while(i < firstlen){
		printf("%c", first[i]);
		i++;
	}
	while(j < secondlen){
		printf("%c", second[j]);
		j++;
	}
	printf("\n");
}

int main(){
    
    do {
		scanf("%s %s ", first, second);
		firstlen = strlen(first);
		secondlen = strlen(second);
		fun();		
	} while(!feof(stdin));
    
    return 0;
}
