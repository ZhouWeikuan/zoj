#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int matrix[24][24];
int row,col;
int perimeter;

void fun(int x, int y){	
	if(matrix[x][y] != 1){
		return;
	}
	matrix[x][y] = 2;
	perimeter += matrix[x-1][y] ==0;
	perimeter += matrix[x+1][y] ==0;
	perimeter += matrix[x][y-1] ==0;
	perimeter += matrix[x][y+1] ==0;
	fun(x-1,y-1);
	fun(x-1,y);
	fun(x-1,y+1);
	fun(x,y-1);	
	fun(x,y+1);
	fun(x+1,y-1);
	fun(x+1,y);
	fun(x+1,y+1);	
}

int main(){
	int x,y;
	int i,j;	
	char c;
	
	scanf("%d %d %d %d ", &row,&col,&x, &y);
	while(row != 0 || col != 0 || x != 0 || y != 0){
		memset(matrix,0,sizeof(matrix));
		
		for(i=1;i<=row;i++){
			for(j=1;j<=col;j++){
				scanf("%c ", &c);
				matrix[i][j] = (c=='X');
			}			
		}
		
		perimeter = 0;
		fun(x,y);			
		
		printf("%d\n", perimeter);
		scanf("%d %d %d %d ", &row,&col,&x, &y);
	}
    
    return 0;
}
