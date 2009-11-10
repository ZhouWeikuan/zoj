#include<stdio.h>

enum {
	MaxBound = 50,
	Up = 0,
	Down = 1,
	Left = 2,
	Right = 3,	
};

int matrix[MaxBound][ MaxBound];
int headx, heady;
int tailx, taily;
int num;
char buffer[120];

int steps[4][2]= {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}	
};

int move(int *x, int *y, int s){
	*x += steps[s][0];
	*y += steps[s][1];
}

int get_step(char c){
	switch(c){
		case 'N':
			return Up;
		case 'S':
			return Down;
		case 'W':
			return Left;
		case 'E':
			return Right;
	}
}

void init(){
	memset(matrix,0, sizeof(int) * MaxBound * MaxBound);
	int i;
	int state = 1 + (Right<<1);
	for(i=10;i<29;i++){
		matrix[24][i] = state;
	}
	headx = 24;
	heady = 29;
	tailx = 24;
	taily = 10;
}
int out_of_bound(){
	if(headx < 0 || headx >=MaxBound || heady <0 || heady >= MaxBound)
		return 1;
	return 0;
}
void print_state(){
	int i,j;
	printf("\n");	
	for(i=0;i<MaxBound;i++){
		for(j=0;j<MaxBound;j++){
			if(matrix[i][j])
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
}
void fun(){
    int flag = 0;	/* -1 out of bound, -2 touch itself */
    int i;
    int s;    
    
    for(i=0;i<num;i++){
		s = get_step(buffer[i]);
		matrix[headx][heady] = 1 + (s <<1);
		move(&headx,&heady,s);
		if(out_of_bound()){
			flag = -1;
			break;
		}		
		
		s = matrix[tailx][taily]>>1;
		matrix[tailx][taily] = 0;
		move(&tailx,&taily,s);
		if(matrix[headx][heady] != 0){
			flag = -2;
			break;
		}
		matrix[headx][heady] = 1;
		/*print_state();*/
	}
	i++;
	if(flag == -1){
		printf("The worm ran off the board on move %d.\n",i);
	} else if(flag == -2){
		printf("The worm ran into itself on move %d.\n",i);
	} else {
		printf("The worm successfully made all %d moves.\n",num);
	}
}

int main(){
    
    scanf("%d", &num);
    while(num){
		init();
		scanf("%s", buffer);
		fun();
		scanf("%d", &num);	
	}
    
    return 0;
}
