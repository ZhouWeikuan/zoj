#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int left[1024];
int right[1024];
int *pa;
int *pb;
int num;
int max,min;

void fun(){
    if(max == min){
		printf("0 %d\n", min);
		return;
	}
	
	pa = left;
	pb = right;
	int *t;
	int i= 1,k;
	for(;i;i++){
		pb[0] = pa[0]/2 + pa[num-1]/2;
		pb[0] += pb[0] % 2;
		max = min = pb[0];
		for(k=1;k<num;k++){
			pb[k] = pa[k]/2 + pa[k-1]/2;
			pb[k] += pb[k]%2;
			if(min > pb[k])
				min = pb[k];
			if(max < pb[k])
				max = pb[k];
		}
		if(max == min){
			break;
		}
		t = pa;
		pa = pb;
		pb = t;
	}
	printf("%d %d\n",i, min);
}

int main(){
    int i;
    
    scanf("%d ", &num);
    while(num){
		scanf("%d ", &left[0]);
		min = max = left[0];
		for(i=1;i<num;i++){
			scanf("%d ", &left[i]);
			if(min > left[i])
				min = left[i];
			if(max < left[i])
				max = left[i];
		}
		fun();
		
		scanf("%d ", &num);
	}
    
    return 0;
}
