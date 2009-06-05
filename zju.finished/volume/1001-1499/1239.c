#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 54,	
};

int table[Size];

void init(){
    int i;
    int t;
    for(i=1;i<51;i++){
		t = i+1;
		t *= t;
		table[i] = t/2 -1;
	}
}

int main(){
	int tstcase;
    int n;
    init();
    
    scanf("%d", &tstcase);
    while(tstcase --){
		scanf("%d", &n);
		printf("%d\n", table[n] );		
	}
    
    return 0;
}
