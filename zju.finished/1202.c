#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 16,	
};

int box[Size];
int total;
int num;
int identity[Size];

int C(int n, int k){
	if(k > n-k)
		k = n-k;
	int sum = 1;
	int i;
	
	for(i=1;i<=k;i++){
		sum *= (n-i+1);
		sum /= i;
	}
	return sum;
}

int P(int k){
	int ret = 1;
	int i;
	for(i=2;i<=k;i++){
		ret *= i;
	}
	return ret;
}

int fun(){
	int ret =1;
	int i;
	int left = total;
	for(i=0;i<num;i++){
		ret *= C(left,box[i]);
		left -= box[i];
	}
	for(i=0;i<Size;i++){
		if(identity[i] ==0)
			continue;
		ret /= P(identity[i]);
	}
	
	printf("%d\n", ret);
}

int main(){
	int i;
	
	scanf("%d ", &num);
	while(!feof(stdin)){
		total = 0;
		memset(identity,0,sizeof(identity));
		for(i=0;i<num;i++){
			scanf("%d ", &box[i]);
			identity[box[i]]++;
			total += box[i];
		}
		fun();
		scanf("%d ", &num);	
	}
	return 0;
}
