#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 100,
};
// the cycle may not start from 1,1
int  num;
int  buf[Size];
int mark[256];
int cycle;
int length;

void init(int a, int b){
	int pred;
	int next;
	int i = 3;
	int value;
	int key;
	memset(mark,0,sizeof(mark));	
	buf[1] = buf[2] = 1;
	key = (buf[1] <<3) + buf[2];
	do {
		mark[key] = i;
		value = a * buf[i-1] + b * buf[i-2];
		value %= 7;
		buf[i++] = value;
		key = (buf[i-2] <<3) + buf[i-1];
	}while(mark[key] == 0);
	cycle = i - mark[key];
	length = i -3;
	if(cycle < 1)
		cycle = 1;
}

int main(){
	int a, b , n;
	
	scanf("%d %d %d", &a, &b, &n);
	while(n != 0){
		init(a,b);
		if(n > length){
			int t = (n - length) /cycle;
			n -= t *cycle;
		}
		while(n > length){
			n -= cycle;
		}
		printf("%d\n", buf[n]);
		scanf("%d %d %d", &a, &b, &n);
	}
	
	return 0;
}
