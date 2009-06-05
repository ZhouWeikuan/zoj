#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 10008,
};

int buffer[Size];
int  num;

void fun(){
	int i,j,pos;
	int min,inverse = 0;
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(buffer[i] > buffer[j])
				inverse ++;
		}
	}
	min = inverse;
	pos = num;
	
	for(i=0;i<num-1;i++){
		pos = num + i;
		buffer[pos] = buffer[i];
		for(j=pos-1;j>i;j--){
			if(buffer[pos] > buffer[j]){
				inverse --;
			} else if(buffer[pos] < buffer[j]){
				inverse ++;
			}
		}
		if(inverse < min)
			min = inverse;
	}
	printf("%d\n", min);
}

int main(){
	int i;
	scanf("%d", &num);
	while(!feof(stdin)){
		for(i=0;i<num;i++){
			scanf("%d", &buffer[i]);
		}
		fun();
		scanf("%d", &num);
	}

	return 0;
}
