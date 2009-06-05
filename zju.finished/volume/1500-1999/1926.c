#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int head, tail;

int main(){
    int num;
    char buffer[16];    

    scanf("%d\n",&num);
    while(num){
		head = 10;
		tail = 1 ;
		fgets(buffer,16,stdin);
		while(strcmp("right on\n",buffer) != 0){			
			if(strcmp("too high\n",buffer) == 0){
				if(num <= head)
					head = num-1;
			} else { /* too low */
				if(num >= tail)
					tail = num + 1;
			}
			scanf("%d\n",&num);
			fgets(buffer,16,stdin);
		}
		if(num <= head && num >= tail){
			printf("Stan may be honest\n");
		} else {
			printf("Stan is dishonest\n");			
		}
		scanf("%d\n",&num);
	}
    
    return 0;
}
