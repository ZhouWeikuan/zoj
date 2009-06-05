#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 10008,
};

char buffer[Size *2];
int  num;

void fun(){
	int i;
	int min = 0;
	num = strlen(buffer);
	memmove(buffer+num,buffer,num);
	buffer[num*2]= 0;
	for(i=1;i<num;i++){
		if(strncmp(buffer+min, buffer+i, num) > 0){
			min = i;
		}
	}
	
	min++;
	printf("%d\n", min);
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
