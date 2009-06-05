#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long steps;

unsigned int fun(){
    long long t;
    long long n = (long long)sqrt(steps);
    while(n *n + n > steps){
		n --;
	}
	long long left = steps - n*n - n;
	t = n * 2;
	if(left){
		if(left <= (n+1)){
			t += 1;
		} else if(left <=(n+1)*2) {
			t += 2;
		}
		
	}
	return t;
}

int main(){
    unsigned int a, b;
    
    scanf("%u %u", &a, &b);
    while(!feof(stdin)){
		steps = b - a;
		a = fun();
		printf("%u\n",a);
		scanf("%u %u", &a, &b);
	}
    
    return 0;
}
