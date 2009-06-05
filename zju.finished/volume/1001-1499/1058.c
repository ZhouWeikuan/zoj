#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 5,
};

double mat[Size][Size];
int  num;
int visit[12];

void fun(){
	int n;
	double money;
	int current, next,i;
	int value;
	
	scanf("%d", &n);
	while(n > 0){
		for(i=0;i<n;i++){
			scanf("%d", &visit[i]);
			visit[i] --;
		}
		visit[i] = 0;
		n++;
		scanf("%lf", &money);
		money *=100;
		current = 0;
		for(i=0;i<n;i++){
			next = visit[i];
			money *= mat[current][next];
			current = next;
			value = money;
			if(money - value >= 0.5){
				value ++;
			}
			money = value;
		}
		money /= 100;
		printf("%.2lf\n", money);


		scanf("%d", &n);
	}
}

int main(){
	int tstcase;
	int i,j;
	
	scanf("%d", &tstcase);
	while(tstcase--){
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				scanf("%lf", &mat[i][j]);
		fun();
		if(tstcase)
			printf("\n");
	}

	return 0;
}
