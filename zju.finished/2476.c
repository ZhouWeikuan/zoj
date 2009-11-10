#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 40,	
};

char result[Size];
int pos;
char input[Size];
char data[Size];
int len;

void trans(){
	int i = len - 1;
	int j= 0;
	while(i>=0){
		if(input[i] <='9' && input[i] >= '0')
			data[j++] =  input[i] - '0';
		else
			len --;
		i--;
	}	
}

void add(){
	int i = 0;
	int carry = 0;
	while(i<len && i < pos){
		carry = carry + data[i] + result[i] ;
		result[i] = carry % 10;
		carry /= 10;
		i++;
	}
	while(i<pos){
		carry = carry + result[i] ;
		result[i] = carry % 10;
		carry /= 10;
		i++;
	}
	while(i<len){
		carry = carry + data[i] ;
		result[i] = carry % 10;
		carry /= 10;
		i++;
	}
	if(carry)
		result[i++] = carry;
	pos = i;
}
void output(){
	int i= pos - 1;
	int j = 0;
	int t;
	while(i>=0){
		input[j++] = result[i] +'0';
		t = i -2;
		if(t >0 && t%3==0){
			input[j++] = ',';
		} else if(t ==0){
			input[j++] = '.';
		}
		i--;	
	}
	input[j] = 0;	
	
	printf("$%s\n",input);
}

int main(){
	int tstcase;
	int i = 0;
			
	scanf("%d", &tstcase);    
	while(tstcase){	
		pos = 0;	
		while(tstcase --){
			scanf("%s", input);
			len=strlen(input);
			trans();
			add();			
		}
		output();
		scanf("%d", &tstcase);
	}
    
    return 0;
}
