#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int buffer[8];
int getnum(){
	int num = 0;
	int i;
	for(i=6;i>0;i--){
		num *= 2;
		num += buffer[i];
	}
	if(buffer[7])
		num = -num;
	return num;
}

int main(){
	int num, sum;
	int i;
	int pos;
	int value;
	
	scanf("%d", &num);
	while(num != -1){
		pos = 7;
		sum = 0;
		while(num --){
			scanf("%d", &value);
			for(i=15;i>=0;i--){
				buffer[pos --] = (value>>i) & 0x01;
				if(pos ==0){
					sum += getnum();
					pos = 7;
				}
			}
		}
		printf("%d\n", sum);
		scanf("%d", &num);
	}

	return 0;
}
