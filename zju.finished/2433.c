#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 50008,
};

int  dis[Size];
int  num;

void fun(){
	if(num < 4){
		printf("0\n");
		return;
	}
	int min = dis[2] - dis[1], t, p=2;
	int i ;
	for(i=3;i<num-1;i++){
		t = dis[i] - dis[i-1];
		if(t < min){
			min = t;
			p = i;
		}
	}
	t = dis[p] + dis[num-1] - dis[p-1];
	printf("%d\n",t);
	printf("%d %d %d %d\n",p+1,1,num,p);
}

int main(){
	int tstcase,i;
	
	scanf("%d ", &tstcase);
	while(tstcase --){
		scanf("%d ", &num);
		for(i=1;i<num;i++){
			scanf("%d ", &dis[i]);
		}
		fun();

		if(tstcase != 0){
			printf("\n");
		}
	}	

	return 0;
}
