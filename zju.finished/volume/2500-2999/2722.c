#include<stdio.h>

unsigned int mask[32];
unsigned int num;

void init(){
	int i;
	for(i=0;i<32;i++){
		mask[i] = (1 << i);
	}
}

int fun(){
    int t = 0;
    
    while(num > mask[t]){
		t++;
	}
    return t;
}

int main(){
    int t;
    
    init();
    
    scanf("%u",&num);
    while(num){
		t = fun();
		printf("%d\n",t);
		
		scanf("%u",&num);
	}
    
    return 0;
}
