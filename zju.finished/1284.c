#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int fun(int n){
	int i, d;
	int sum = (n != 1);
	
	
	d = sqrt(n);
	
	for(i = 2; i < d ;i ++){
        if(n%i==0){
            sum += i + n/i;
        }
    }
    if(i ==d && n%i==0){
		d = n / i;
		if(d != i )
			sum += d;
        sum += i;
    }
    printf("%5d  ", n);
    if(sum < n){
		printf("DEFICIENT\n");
	} else if(sum ==n) {
		printf("PERFECT\n");
	} else {
		printf("ABUNDANT\n");
	}
}

int main(){
    int num;
    
    printf("PERFECTION OUTPUT\n");
    scanf("%d", &num);
    while(num){
		fun(num);
		scanf("%d", &num);	
	}
	printf("END OF OUTPUT\n");
    
    return 0;
}
