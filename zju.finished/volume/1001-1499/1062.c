#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 24,
};

int tree[Size];
int sum[Size];
int  pos;
void init(){
	int i;
	tree[0] = 1;
	sum [0] = 0;
	for(pos=1;sum[pos-1] < 500000001;pos++){
		tree[pos] = 0;
		for(i=0;i<=pos-1;i++){
			tree[pos] += tree[i] * tree[pos-i-1];
		}
		sum[pos] = sum[pos-1] + tree[pos];
	}
}

int fun(int node, int num, int right){
	int i = 0,t, ret = 0;
	t = tree[i]  * tree[node-1-i] * right;
	while(t < num){
		num -= t;
		ret += t;
		i++;
		t = tree[i]  * tree[node-1-i] * right;
	}
	if(i){
		printf("(");
		t = fun(i,num,right * tree[node-i-1]);
		printf(")");
	} else {
		t = 0;
	}
	ret += t;
	printf("X");
	i = node -1-i;
	if(i){
		printf("(");
		ret += fun(i,num - t,right);
		printf(")");
	}
	return ret;
}

int main(){
	int num,t;
	
	init();

	scanf("%d", &num);
	while(num > 0){
		for(t=1;sum[t]<num;t++){
			;
		}
		num -= sum[t-1];
		fun(t,num,1);
		printf("\n");
		scanf("%d", &num);
	}

	return 0;
}
