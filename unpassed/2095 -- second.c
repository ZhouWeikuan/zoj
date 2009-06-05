#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int fun(int n){
	int i, d;
	int sum = 1;
	
	d = sqrt(n);
	
	for(i = 2; i < d ;i ++){
        if(n%i==0){
            sum += i + n/i;
        }
    }
    if(i < n && n%i==0){
        sum += i;
    }
    printf("%d\n", sum);
}

int main(){
    int tstcase;
    int num;
    for(num=2;num<500000;num++)
        fun(num);
    scanf("%d", &tstcase);	
    
	while(tstcase --){
        scanf("%d", &num);
        fun(num);
    }
	
	return 0;
}
