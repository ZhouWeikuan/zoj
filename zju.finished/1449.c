#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 20,
};

int matrix[Size][Size][Size];
int plane[Size][Size];
int array[Size];
int N;
int max;

void calc_array(){
	int i;
	int t = 0;
	for(i=0;i<N;i++){
		if(t > 0)
			t += array[i];
		else
			t = array[i];
		if(t > max)
			max = t;
	}
}

void calc_matrix(){
	int i,j,k;
	for(i=0;i<N;i++){
		memset(array,0, sizeof(int)*Size);
		for(j=i;j<N;j++){
			for(k=0;k<N;k++){
				array[k] += plane[j][k];				
			}
			calc_array();
		}
	}
}

void fun(){
    int i,j,k;
    for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				scanf("%d", &matrix[i][j][k]);
			}
		}
	}
	max = matrix[0][0][0];
	for(i=0;i<N;i++){
		memset(plane,0, sizeof(int)*Size*Size);
		for(j=i;j<N;j++){
			int m,n;
			for(m=0;m<N;m++){
				for(n=0;n<N;n++){
					plane[m][n] += matrix[j][m][n];					
				}				
			}
			calc_matrix();
		}
	}
}

int main(){    
    
    scanf("%d", &N);
    while(N ){
		fun();
		printf("%d\n",max);
		scanf("%d", &N);
	}
    
    return 0;
}
