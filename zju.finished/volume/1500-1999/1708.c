#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 12,	
	North = 0,
	South = 1,
	East = 2,
	West = 3,
};

int cmd[Size][Size];
int step[Size][Size];
int row, col;
int x, y;

int direct[4][2] ={
    {-1,0},
    {1,0},
    {0,1},
    {0,-1}
};

int fun(){
	int num = 1;
	int flag;
	memset(step,0,sizeof(step));
	while(x >=0 && x< row && y>=0 && y < col){
        if(step[x][y]) {
            flag = 10;
            break;
        }
        step[x][y] = num++;
        flag = cmd[x][y];
        x += direct[flag][0];
        y += direct[flag][1];
    }
    if(flag ==10){
        printf("%d step(s) before a loop of %d step(s)\n", step[x][y] -1, num-step[x][y]);
    } else {
        printf("%d step(s) to exit\n", num -1);
    }
}

int main(){
	int i,j;
	char c;
	
	scanf("%d %d %d ", &row, &col, &y);
	while(row ){
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                scanf("%c ", &c);
                if(c=='N'){
                    cmd[i][j] = North;
                } else if(c=='S'){
                    cmd[i][j] = South;
                } else if(c=='E'){
                    cmd[i][j] = East;
                }  else {
                    cmd[i][j] = West;
                }
            }
        }
        y --; x = 0;
        fun();
        scanf("%d %d %d ", &row, &col, &y);
    }
	return 0;
}
