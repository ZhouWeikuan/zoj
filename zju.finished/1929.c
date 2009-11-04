#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int base;
int divisor;
char multiple[1200];
int pos;

int fun(){
    int i;
    int carry = 0;
    int t;
    for(i=0; multiple[i]; i++){
		t = multiple[i] -'0';
		carry *= base;
		carry += t;
		carry %= divisor;		
	}
	
	int pos = 1008;
	multiple[pos]	=	0;
	pos --;
	if(carry ==0){
		multiple[pos --] = '0';
	}
	while(carry){
		multiple[pos --] = carry%base + '0';
		carry /= base;
	}
	pos ++;
	printf("%s\n", multiple + pos);	
}

int conv(char *str){
	int ret = 0;
	
	while(*str){
		ret *= base;
		ret += *str -'0';
		str ++;
	}
	return ret;
}

int main(){
    char buffer[20];
    
    scanf("%d", &base);
    while(base ){
		scanf("%s %s ", multiple, buffer);
		divisor = conv(buffer);
		
		fun();
		
		scanf("%d", &base);	
	}
    
    return 0;
}
