#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dimen[16];
int num;
int matrix[16][16];
int trace[16][16];

void traceback(int i, int j){
	if(i==j)
		return;
	printf("(");
	if(i==trace[i][j])
		printf("A%d",i);
	traceback(i,trace[i][j]);
	printf(" x ");
	traceback(trace[i][j]+1,j);
	if(trace[i][j]+1 == j)
		printf("A%d",j);
	printf(")");	
}

void fun(){
    int i,j,k,r;
    int t;
    for(i=1;i<= num;i++)
    	matrix[i][i] = 0;
    for(r=2;r<=num;r++){
		for(i=1;i<=num-r+1;i++){
			j = i+ r -1;
			matrix[i][j] = matrix[i+1][j] + dimen[i-1] * dimen[i] * dimen[j];
			trace[i][j] = i;
			for(k=i+1;k<j;k++){
				t = matrix[i][k] + matrix[k+1][j] + dimen[i-1]*dimen[k] *dimen[j];
				if(t < matrix[i][j]){
					matrix[i][j] = t;
					trace[i][j] = k;
				}
			}
		}
	}
    
    traceback(1,num);
}

int main(){
    int i;
    int row, col;
    int tstcase = 1;
    
    scanf("%d", &num);
    while(num){
		for(i=0;i<num;i++){
			scanf("%d %d", &row,&col);
			dimen[i] = row;
		}
		dimen[i] = col;
		printf("Case %d: ",tstcase ++);
		fun();
		printf("\n");
		scanf("%d", &num);
	}
    
    return 0;
}
