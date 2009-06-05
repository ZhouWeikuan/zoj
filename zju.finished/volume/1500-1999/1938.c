#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,k;

unsigned int fun(){
    long long sum = 1;
    int i;
    if(k > n- k)
    	k = n - k;
    for(i=1;i<=k;i++){
		sum *= (n-i+1);
		sum /= i;
	}
	return sum;
}

int main(){
    
    scanf("%d %d", &n,&k);
    while(n ){
		printf("%u\n", fun());
		scanf("%d %d", &n,&k);
	}
    
    return 0;
}
