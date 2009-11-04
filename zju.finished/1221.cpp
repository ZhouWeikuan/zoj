#include<iostream>
#include<cstdio>

enum {
	Size = 24,
};
using namespace std;
int matrix[Size][Size];

void init(){
	int i,j;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			matrix[i][j] = 1000;
		}
		matrix[i][i] = 0;
	}
}
void calc(){
	int i,a,b;
	for(i=0;i<20;i++){
		for(a=0;a<20;a++){
			for(b=0;b<20;b++){
				if(matrix[a][b] > matrix[a][i] + matrix[i][b])
					matrix[a][b] = matrix[a][i] + matrix[i][b];
			}
		}
	}
}
void fun(){
	static int tstcase = 0;
	int num,a,b;
	calc();
	scanf("%d ",&num);
	printf("Test Set #%d\n",++tstcase);
	while(num--){
		scanf("%d %d ",&a,&b);
		printf("%d to %d: %d\n",a,b,matrix[a-1][b-1]);
	}
	printf("\n");
}

int main(){
	int i,j,t;

	while(!feof(stdin)){
		init();
		for(i=0;i<19;i++){
			scanf("%d ",&t);
			while(t --){
				scanf("%d ",&j);
				j--;
				matrix[i][j] = matrix[j][i] = 1;
			}
		}
		fun();
	}
	return 0;
}
