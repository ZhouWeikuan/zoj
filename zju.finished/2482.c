#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 40,	
};

char buffer[Size];
int num;

int conv(int start){
    int t;
    int ret = 0;
    for(t = start; t < start + 8 ; t++){
        ret *= 2;
        ret += buffer[t] -'0';
    }
    return ret;
}

int fun(){
	int i;
	int t;
	for(i=0;i<32;i+=8){
        if(i)
            printf(".");
        t= conv(i);
        printf("%d",t);
    }
    printf("\n");
}

int main(){
	
	scanf("%d", &num);
	while(num -- ){
        scanf("%s", buffer);
        fun();
    }
	
	return 0;
}
