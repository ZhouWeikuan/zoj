#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char alpha[28];
char buffer[56];
int num;

void init(){
	int i;
	for(i=0;i<26;i++){
		alpha[i] = 'B' + i;
	}
	alpha[25] = 'A';
}

int fun(){
    int i;
    int t;
    num ++;
    for(i=0; buffer[i]; i++){
		t = buffer[i] - 'A';
		buffer[i] = alpha[t];
	}
	printf("String #%d\n",num);
	printf("%s\n\n",buffer);
}

int main(){
    int tstcase;
    init();
    
    scanf("%d", &tstcase);
    while(tstcase --){
		scanf("%s", buffer);
		fun();
		
	}
    
    return 0;
}
