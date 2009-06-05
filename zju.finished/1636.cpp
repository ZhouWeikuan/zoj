#include<cstdio>

using namespace std;
enum {
	Size = 504,
};
int M,N;
int mat[Size][Size];
int sum[Size][Size];
int tstnum, tstcase;

void calc_sum(){
	int i,j;
	sum[0][0] = mat[0][0];
	for(i=1;i<M;i++){
		sum[i][0] = sum[i-1][0] + mat[i][0];
	}
	for(j=1;j<N;j++){
		sum[0][j] = sum[0][j-1] + mat[0][j];
	}
	for(i=1;i<M;i++){
		for(j=1;j<N;j++){
			sum[i][j] = mat[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
}

int fun(){
    int num;
    int i,j,x,y;
    int t;  	
  	
  	printf("Case %d:\n", tstcase);
  	
  	scanf("%d ", &num);
  	while(num--){		
		scanf("%d%d%d%d ", &i, &j, &x, &y);
		i--; j--; x--; y--;
		if(i == 0){
			if(j==0){
				t = sum[x][y];
			} else {
				t = sum[x][y] - sum[x][j-1];
			}
		} else if(j == 0){
			t = sum[x][y] - sum[i-1][y];
		} else {
			t = sum[x][y] - sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1];
		}
		
		printf("%d\n",t);
	}
    
}

int main(){
  	tstcase = 0;    
    scanf("%d ", &tstnum);
    
    while(tstcase ++ < tstnum){
		scanf("%d%d ", &M, &N);		
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				scanf("%d ", &mat[i][j]);				
				mat[i][j] *= mat[i][j];
			}
		}
		calc_sum();
		fun();
	}
    
    return 0;
}
