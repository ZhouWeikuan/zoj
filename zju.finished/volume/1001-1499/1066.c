#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 50,
};

int row,col;
char buffer[Size][Size];
int  num;

void draw(int x, int y, int v){
	x = x*4 + 1;
	y = y*4 + 3;
	buffer[x][y] = 'O';
	if(v == 1){
		buffer[x][y-1]='-';
		buffer[x][y+1]='-';
		buffer[x][y-2]='H';
		buffer[x][y+2]='H';
		return;
	}
	if(v == -1){
		buffer[x-1][y]='|';
		buffer[x+1][y]='|';
		buffer[x-2][y]='H';
		buffer[x+2][y]='H';
		return;
	}
	
	if(buffer[x][y-2] !='H' ){
		buffer[x][y-1] ='-';
		buffer[x][y-2] ='H';
	}else {
		buffer[x][y+1] ='-';
		buffer[x][y+2] ='H';
	}

	if(x-2>=0 && buffer[x-2][y] != 'H'){
		buffer[x-2][y] = 'H';
		buffer[x-1][y] = '|';
	} else {
		buffer[x+2][y] = 'H';
		buffer[x+1][y] = '|';
	}
}

int main(){
	int tstcase = 0;
	int i,j;
	
	scanf("%d",&num);
	while(num ){
		if(tstcase ++){
			printf("\n");
		}
		row = (num-1)*4+3; col = num*4+3;
		memset(buffer,' ',sizeof(buffer));
		for(i=0;i<col;i++){
			buffer[0][i] = '*';
			buffer[row-1][i] = '*';
		}
		for(i=0;i<row;i++){
			buffer[i][0] = '*';
			buffer[i][col-1] = '*';
		}
		int value;
		for(i=0;i<num;i++){
			for(j=0;j<num;j++){
				scanf("%d", &value);
				draw(i,j,value);
			}
		}
		printf("Case %d:\n\n",tstcase);
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				printf("%c",buffer[i][j]);
			}
			printf("\n");
		}

		scanf("%d",&num);
	}

	return 0;
}
