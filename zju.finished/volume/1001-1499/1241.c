#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a,b,c;

void fun(){
	static tstcase = 0;
	int t;
    double ret;
    char alpha;
    
    tstcase ++;
    printf("Triangle #%d\n", tstcase);
    
    if(c == -1){
		alpha ='c';
		ret = a*a + b *b;
		ret = sqrt(ret);
		printf("%c = %.3lf\n\n", alpha, ret);
		return;	
	}
	if(a == -1){
		t = b;
		alpha = 'a';
	} else {
		t = a;
		alpha = 'b';
	}
	
	if( t >= c ){
		printf("Impossible.\n\n");
		return;
	}
	
	ret = c*c - t *t;
	ret = sqrt(ret);
	printf("%c = %.3lf\n\n", alpha, ret);
}

int main(){
    
    scanf("%d %d %d", &a, &b, &c);
    while(a ){
		fun();
				
		scanf("%d %d %d", &a, &b, &c);
	}    
    
    return 0;
}
