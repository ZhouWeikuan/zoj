#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

enum {
	Size = 3002,	
};

int prime[Size] = {2,3,5,7};
int pos = 4;

void init(){
	int start = 9;
	int lim;
	int i;
	int flag;
	for( ; pos < Size; start +=2){        
        lim = sqrt(start) + 1;
        flag = 0;
        for(i=0; prime[i] < lim; i++){
            if(start % prime[i] ==0){
                flag = 1;
                break;
            }
        }
        if(flag ==0){
            prime[pos++] = start;
        }        
    }    
}

int main(){
	int num;
	init();
	
	scanf("%d", &num);
	while(num){
        printf("%d\n", prime[num-1]);
        scanf("%d", &num);    
    }
	
	return 0;
}
