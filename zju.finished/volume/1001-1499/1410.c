#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 32000,
};

unsigned int  sum[Size];
unsigned int  perm[Size];
int pos;

char buffer[20];

void init(){
	int i,j;
	for(i=1;i<10;i++){
		perm[i] = perm[i-1] + 1;
		sum[i] = sum[i-1] + perm[i];
	}
	for(i=10;i<100;i++){
		perm[i] = perm[i-1] + 2;
		sum[i] = sum[i-1] + perm[i];
	}
	for(i=100;i<1000;i++){
		perm[i] = perm[i-1] + 3;
		sum[i] = sum[i-1] + perm[i];
	}
	for(i=1000;i<10000;i++){
		perm[i] = perm[i-1] + 4;
		sum[i] = sum[i-1] + perm[i];
	}
	for(i=10000;i<100000;i++){
		perm[i] = perm[i-1] + 5;
		sum[i] = sum[i-1] + perm[i];
		if(sum[i] > 2147483647) {
			pos = i;
			return;
		}
	}

}

void fun(unsigned int n){
	int hi = pos,low=0;
	int mid;
	while(hi > low){
		mid = (hi + low) /2;
		if(sum[mid] > n){
			hi = mid;
		}else if(sum[mid ] < n){
			low = mid + 1;
		}else {
			break;
		}
	}
	if(hi==low)
		mid = low;
	if(sum[mid] >= n)
		mid --;
	n -= sum[mid];
	mid ++;
	hi = mid, low = 0;
	while(hi > low){
		mid = (hi + low) /2;
		if( perm[mid] > n){
			hi = mid;
		}else if(perm[mid] < n){	
			low = mid + 1;
		}else {
			break;
		}
	}
	if(hi ==low)
		mid = low;
	if(perm[mid] >= n){
		mid --;
	}
	n -= perm[mid];
	mid++;
	sprintf(buffer,"%d",mid);
	printf("%c\n", buffer[n-1]);
}

int main(){
	unsigned int num;
	int tstcase ;
	init();

	scanf("%d", &tstcase);
	while(tstcase --){
		scanf("%u", &num);
		fun(num);
	}

	return 0;
}
