#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 120,	
};

typedef struct {
	char alpha;
	int count;	
}Node ;

Node code[Size];
int pos = 0;
char buffer[Size];


void fun(){
    int i =0;
    pos = -1;
    
    while(buffer[i] ){
		pos ++;
		code[pos].alpha = buffer[i];
    	code[pos].count = 1;
    	i++;
		while(buffer[i] == code[pos].alpha){
			i++;
			code[pos].count++;
		}		
	}
	pos ++;
	for(i=0;i<pos;i++){
		if(code[i].count >1){
			printf("%d",code[i].count);
		}
		printf("%c",code[i].alpha);
	}
	printf("\n");
}

int main(){
    int tstcase;
    
    scanf("%d", &tstcase);
    while(tstcase --){
		scanf("%s", buffer);
		fun();		
	}
    
    return 0;
}
