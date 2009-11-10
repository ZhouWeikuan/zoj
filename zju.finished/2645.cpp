#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*time limited exceeded */

unsigned ip;
unsigned min,max;
unsigned int mask[32];

void init(){
	int value = ~0;
	int i;
	for(i=0;i<32;i++){
		mask[i] = (value>>i)<<i;
	}
}

void print(unsigned value){
	printf("%u.%u.%u.%u\n", (value >>24)&0xff, (value>>16)&0xff, (value>>8)&0xff,value&0xff);	
}

void fun(){    
	int i = 0;
	while(min != max){
		min >>=1; max>>=1;
		i++;
	}
	
	min <<= i;
	print(min);
	print(mask[i]);	
}

int main(){
	unsigned int num = 0;
	int temp;
	union MyName{
		unsigned t;
		unsigned char buffer[4];
	};	
	union MyName u;
	init();	
	
	scanf("%u ", &num);
	while(!feof(stdin)){
		num --;
		scanf("%u.", &temp);
		u.buffer[3] = temp;
		scanf("%u.", &temp);
		u.buffer[2] = temp;
		scanf("%u.", &temp);
		u.buffer[1] = temp;
		scanf("%u", &temp);
		u.buffer[0] = temp;
		
		min = max = u.t;
		while(num --){
			scanf("%u.", &temp);
			u.buffer[3] = temp;
			scanf("%u.", &temp);
			u.buffer[2] = temp;
			scanf("%u.", &temp);
			u.buffer[1] = temp;
			scanf("%u", &temp);
			u.buffer[0] = temp;
			
			if(u.t < min){
				min = u.t;
			} else if(u.t > max){
				max = u.t;
			}
		}
		
		fun();
		scanf("%u ", &num);
	}
    
    return 0;
}
