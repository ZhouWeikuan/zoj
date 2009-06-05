#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int num;
    int bitmask;
    	
    scanf("%d", &num);
	while(num){
        bitmask = 1;
        while( (num & bitmask) ==0){
            bitmask <<= 1;
        }
        printf("%d\n", bitmask);
        scanf("%d", &num);    
    }
	
	return 0;
}
