#include<stdio.h>

long long int num;

long long table[2] = {9,2};

int fun(){
    long long int n = 9ll;
    int win = 1;
    
    while(n < num){
		n *= table[win];
		win = 1 - win;
	}
	return win;
}

int main(){
    int t;
    
    scanf("%lld",&num);
    while(!feof(stdin)){
		t = fun();
		if(t ){
			printf("Stan wins.\n");	
		}else {
			printf("Ollie wins.\n");	
		}
		scanf("%lld",&num);
	}
	
    return 0;
}
