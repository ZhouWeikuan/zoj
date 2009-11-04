#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 264,
};

char buffer[Size];
int len;
int stack[Size];
int pos;

void fun(){
    len = strlen(buffer);
    buffer[--len] = 0;
    pos = 0;
    int i=0;
    int t;
    int j;
    for(i=0;i<len;i++){
		if(buffer[i] =='('){
			stack[pos++] = i;
			continue;
		}else if(buffer[i] != ')'){
			continue;
		}
		t= stack[--pos];
		for(j=t-1;j>=0;j--){
			if(buffer[j] != ' ')
				break;
		}
		if(j<0 || buffer[j] != '-'){
			buffer[t] = buffer[i] = ' ';			
			continue;
		}
		for(j=t+1;j<i;j++){
			if(buffer[j] =='+' || buffer[j] =='-')
				break;
		}
		if(j==i){
			buffer[t] = buffer[i] = ' ';			
		}
	}
	j = 0;
    for(i=0;i<len;i++){
		if(buffer[i] != ' '){
			buffer[j++] = buffer[i];
		}
	}
	buffer[j] = 0;
	printf("%s\n",buffer);
}

int main(){
    int num;
    
    scanf("%d ", &num);
    while(num --){
		fgets(buffer,Size,stdin);
		fun();		
	}
    
    return 0;
}
