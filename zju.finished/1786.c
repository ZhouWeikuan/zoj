#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 100,
};

int skew[Size];
int stack[Size];
int  num, pos;

void init(){
	int i;
	int t = 0;
	for(i=0; t <= 100663270; i++){
		t = 1<<(i+1);
		t --;
		skew[i] = t;
	}
	num = i;

}
int find_pos(int v){
	int hi = num, low = 0;
	int mid;
	while(hi> low){
		mid = (hi + low)/2;
		if(skew[mid] == v){
			return mid;
		}else if(skew[mid] < v){
			low = mid + 1;
		} else {
			hi = mid;
		}
	}
	if(hi ==low)
		mid = low;
	if(skew[mid] > v)
		mid --;
	return mid;
}
void fun(int value){
	pos = 0;
	int p = find_pos(value);
	while(value){
		if(value == 2 *skew[p]){
			stack[pos++] = p;
			stack[pos++] = p;
			return;
		}
		stack[pos++] = p;
		value -= skew[p];
		p = find_pos(value);
	}
}

int main(){
	int tstcase;
	int n;
	init();

	scanf("%d", &tstcase);
	while(tstcase --){
		scanf("%d", &n);
		if(n==0){
			printf("0 []\n");
		}else {
			fun(n);
			printf("%d [",n);
			printf("%d", stack[--pos]);
			while(pos --){
				printf(",%d", stack[pos]);
			}
			printf("]\n");
		}
	}

	return 0;
}
