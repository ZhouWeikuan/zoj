#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 108,
	U = 0,
	R = 1,
	D = 2,
	L = 3,
};
int row,col;

char block[Size][Size];
char matrix[2][Size][Size];
int move[4][2] ={
	{-1,0},{0,1},{1,0},{0,-1}
};

void trans(char *p){
	if(*p == 'U'){
		*p = 0;
	} else if(*p =='R'){
		*p = 1;
	} else if(*p =='D'){
		*p = 2;
	} else if(*p =='L'){
		*p = 3;
	}
}

int fun(int cur){
	int ret = 0;
	int i,j,x,y, s,e;
	char direct;
	int rev = 1 - cur;
	int step;
	
	scanf("%d %d", &s, &e);
	if(s==0 && e ==0){
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				matrix[cur][i][j] = block[i][j];
		return 0;
	}
	scanf(" %c", &direct);
	trans(&direct);

	fun(rev);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(block[i][j] == 1 ){
				matrix[cur][i][j] = 1;
				continue;
			}
			x = i, y = j;
			step = 0;
			while(step < s){
				x += move[direct][0];
				y += move[direct][1];
				if(x <0 || y < 0 || x>= row || y>= col || block[x][y] ==1)
					break;
				step ++;
			}
			matrix[cur][i][j] = 1;
			if(step < s){
				continue;
			}
			while(step <= e){
				if(matrix[rev][x][y] == 0){
					matrix[cur][i][j] = 0;
					ret ++;
					break;
				}
				step ++;
				x += move[direct][0];
				y += move[direct][1];
				if(x <0 || y < 0 || x>= row || y>= col || block[x][y] ==1)
					break;
			}
		}
	}
	return ret;
}

int main(){
	int tstcase;
	int i,j;
	
	scanf("%d",&tstcase);
	while(tstcase --){
		scanf("%d %d", &row, &col);
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				scanf("%d", &block[i][j]);
			}
		}
		
		i = fun(0);
		printf("%d\n",i);
	}	

	return 0;
}
