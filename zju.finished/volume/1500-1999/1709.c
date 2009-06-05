#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 108,
};

char matrix[Size][Size];
int  Row,Col;

int DFS(int x,int y){
	if(x <0 || y < 0 || x>= Row|| y>= Col)
		return 0;
	if(matrix[x][y] != '@')
		return 0;
	matrix[x][y] = 0;
	int ret = 1;
	ret += DFS(x-1,y-1);
	ret += DFS(x-1,y);
	ret += DFS(x-1,y+1);
	ret += DFS(x,y-1);
	ret += DFS(x,y+1);
	ret += DFS(x+1,y-1);
	ret += DFS(x+1,y);
	ret += DFS(x+1,y+1);
	return ret;
}

int main(){
	int i,j;
	int t;
	
	scanf("%d %d ", &Row, &Col);
	while(Row > 0){
		for(i=0;i<Row;i++){
			for(j=0;j<Col;j++){
				scanf("%c ", &matrix[i][j]);
			}
		}
		t = 0;
		
		for(i=0;i<Row;i++){
			for(j=0;j<Col;j++){
				if(matrix[i][j] =='@'){
					if(DFS(i,j))
						t++;
				}
			}
		}
		printf("%d\n",t);
		
		scanf("%d %d ", &Row, &Col);
	}	

	return 0;
}
