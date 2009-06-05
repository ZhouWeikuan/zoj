#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 3,
	Stand = 168,
};

int data[Size];

int main(){
    int i;
    for(i=0;i<Size;i++)
    	scanf("%d", &data[i]);
    
    for(i=0;i<Size;i++){
		if(data[i] <= Stand ){
			printf("CRASH %d\n", data[i]);
			break;
		}
	}
	if(i== Size){
		printf("NO CRASH\n");
	}
    
    return 0;
}
