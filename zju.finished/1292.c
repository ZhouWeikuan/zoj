#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 200,	
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
		data[j++] =  input[i] - '0';
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
	while(i>=0){
		input[j++] = result[i] +'0';
		i--;	
	}
	input[j] = 0;	
	
	printf("%s\n",input);
}

int main(){
	int tstcase;
	int i = 0;
			
	scanf("%d", &tstcase);    
	while(i < tstcase){
		if(i!=0){
			printf("\n");
		}
		i++;
		pos = 0;
		scanf("%s", input);
		len=strlen(input);
		while(input[0] != '0'|| len > 1){			
			trans();
			add();
			scanf("%s", input);
			len=strlen(input);
		}
		output();				
	}
    
    return 0;
}
