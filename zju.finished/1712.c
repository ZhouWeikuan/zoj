#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 32,	
};

int bin[Size];
char buffer[Size *2];
int pos;

void init(){
    int i;
    for( i=0;i<Size;i++){
        bin[i] = (1<<i) -1;
    }
}

int fun(){
	int i, t;
	int ret = 0;
	for(i=0;i<pos;i++){
        t = buffer[i] - '0';
        ret += (bin[pos-i]) * t;
    }
    return ret;
}

int main(){
	init();
	
	scanf("%s ", buffer);
	while(buffer[0] != '0'){
        pos = strlen(buffer);
        printf("%d\n", fun());
        scanf("%s ", buffer);
    }
	return 0;
}
