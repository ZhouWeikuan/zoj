#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 108,
};

int matrix[Size][Size];
int cheese[Size][Size];
int  num, dis;

int fun(int x,int y){
	int i;
	int max = 0, v;
	if(matrix[x][y] != -1)
		return matrix[x][y];
	for(i=x-1;i>=0 && x-i <= dis;i--){
		if(cheese[i][y] <= cheese[x][y])
			continue;
		v= fun(i,y);
		if(max < v)
			max = v;
	}
	for(i=x+1;i<num && i-x <= dis;i++){
		if(cheese[i][y] <= cheese[x][y])
			continue;
		v= fun(i,y);
		if(max < v)
			max = v;
	}
	for(i=y-1;i>=0 && y-i <= dis;i--){
		if(cheese[x][i] <= cheese[x][y])
			continue;
		v= fun(x,i);
		if(max < v)
			max = v;
	}
	for(i=y+1;i<num && i-y <= dis;i++){
		if(cheese[x][i] <= cheese[x][y])
			continue;
		v= fun(x,i);
		if(max < v)
			max = v;
	}
	
	matrix[x][y] = cheese[x][y] + max;
	return matrix[x][y];
}

int main(){
	int i,j;
	scanf("%d %d",&num,&dis);
	while(num > 0){
		for(i=0;i<num;i++){
			for(j=0;j<num;j++){
				scanf("%d",&cheese[i][j]);
				matrix[i][j] = -1;
			}
		}
		
		fun(0,0);
		printf("%d\n",matrix[0][0]);

		scanf("%d %d",&num,&dis);
	}	

	return 0;
}
