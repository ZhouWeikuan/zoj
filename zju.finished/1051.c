#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 20,
};

int  D[16];
int  cell[2][Size][Size];
int  days;

char ans[4]= {
	'.','!','X','#'
};

int getValue(int s[Size][Size], int x, int y){
	int sum = s[x][y];
	if(x>=1){
		sum += s[x-1][y];
	}
	if(y>=1){
		sum += s[x][y-1];
	}
	if(x <Size-1){
		sum += s[x+1][y];
	}
	if(y<Size-1){
		sum += s[x][y+1];
	}
	sum = D[sum] + s[x][y];
	if(sum >3)
		sum = 3;
	if(sum <0)
		sum = 0;
	return sum;
}

void fun(){
	int (*source)[Size], (*dest)[Size];
	int (*t)[Size];
	int i,j;
	
	source = cell[0];
	dest   = cell[1];
	while(days--){
		for(i=0;i<Size;i++){
			for(j=0;j<Size;j++){
				dest[i][j] = getValue(source,i,j);
			}
		}
		t = dest, dest = source, source = t;
	}

	for(i=0;i<Size;i++){
		for(j=0;j<Size;j++){
			printf("%c",ans[source[i][j]]);
		}
		printf("\n");
	}
}

int main(){
	int tstcase;
	int i,j;
	scanf("%d", &tstcase);
	while( tstcase --){
		scanf("%d", &days);
		for(i=0;i<16;i++)
			scanf("%d", &D[i]);
		for(i=0;i<Size;i++){
			for(j=0;j<Size;j++){
				scanf("%d", &cell[0][i][j]);
			}
		}
		fun();
		
		if(tstcase )
			printf("\n");
	}	

	return 0;
}
