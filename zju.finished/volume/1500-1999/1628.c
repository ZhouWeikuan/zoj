#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 10,
};

char diamond[Size][Size];
int  num;

int check(int x, int y, char c){
	int t;
	if(x >0 && x < 7){
		t = diamond[x-1][y] == c;
		t += diamond[x+1][y] ==c;
		if(t ==2)
			return 1;
	}
	if(y >0 && y < 7){
		t = diamond[x][y-1] == c;
		t += diamond[x][y+1] ==c;
		if(t ==2)
			return 1;
	}
	if(x>1){
		t = diamond[x-2][y]==c; 
		t += diamond[x-1][y]==c;
		if(t ==2)
			return 1;
	}
	if(x < 6){
		t = diamond[x+2][y]==c; 
		t += diamond[x+1][y]==c;
		if(t ==2)
			return 1;
	}
	if(y > 1){
		t = diamond[x][y-2]==c; 
		t += diamond[x][y-1]==c;
		if(t ==2)
			return 1;
	}
	if(y < 6){
		t = diamond[x][y+2]==c; 
		t += diamond[x][y+1]==c;
		if(t ==2)
			return 1;
	}
	return 0;
}

int fun(){
	int ox,oy,nx,ny;
	int t;
	scanf("%d %d %d %d", &ox, &oy, &nx, &ny);
	ox --, oy--,nx--,ny--;
	t = ox-nx;
	if(t <0) t=-t;
	if(ny > oy)
		t += ny-oy;
	else
		t += oy - ny;
	if(t != 1)
		return 0;
	if(check(ox,oy, diamond[nx][ny]))
		return 1;
	return check(nx,ny, diamond[ox][oy]);
}

int main(){
	int i;
	scanf("%s", diamond[0]);
	while(!feof(stdin)){
		for(i=1;i<8;i++){
			scanf("%s", diamond[i]);
		}
		if( fun() )
			printf("Ok!\n");
		else {
			printf("Illegal move!\n");
		}
		scanf("%s", diamond[0]);
	}

	return 0;
}
