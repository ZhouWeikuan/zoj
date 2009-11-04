#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int fun(int a, int b){
    int t;
    while(b > 0){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(){
    int a, b;
    int t;    
    
    scanf("%d %d", &a, &b);
    while(!feof(stdin)){
		if( a< b)
			t = fun(b,a);
		else 
			t = fun(a,b);
		printf("%10d%10d    ",a,b);
		if(t ==1){
			printf("Good Choice\n");
		} else {
			printf("Bad Choice\n");
		}
		
		printf("\n");
		
		scanf("%d %d", &a, &b);	
	}
    
    return 0;
}
