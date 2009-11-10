#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int wage[10008];

void init(){
    int i = 1;
    int range = 0;
    int j;
    
    for(i=0; i< 10007; ){
		range ++;
		for(j = 0;j < range && i<10007;j++){
			i++;
			wage[i] = range + wage[i-1];
		}
		
	}
}

int main(){    
    int num;
    int n;
    
    init();
    
    scanf("%d", &num);
    while(num --){
		scanf("%d", &n);
		while(n > 0){
			printf("%d %d\n", n, wage[n]);
			
			scanf("%d", &n);
		}
		if(num)
			printf("\n");
	}
    
    return 0;
}
