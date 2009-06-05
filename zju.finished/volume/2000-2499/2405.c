#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int get_sum(int num, int base){
	int ret = 0;
	while(num ){
		ret += num%base;
		num /= base;
	}	
	return ret;
}

int fun(int n){
    int sum;
    int t;
    sum = get_sum(n, 10);
    if(sum != get_sum(n,16)){
		return 0;
	}
	
	return (sum == get_sum(n, 12));	
}

int main(){
    int i;
    
    for(i=1000;i<10000;i++){
		if(fun(i)){
			printf("%d\n", i);
		}
	}
    
    return 0;
}
