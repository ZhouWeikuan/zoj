#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int generate(int n){
	int ret = n;
	while(n){
		ret += n%10;
		n /= 10;
	}
	return ret;	
}

int main(){
	int n;
	int lim;
	int t;
	int last;
	int flag;
    printf("1\n3\n5\n7\n9\n20\n31\n42\n53\n64\n75\n86\n97\n");
    
    lim = 3*9;
    for(n=100;n<1000;n++){
		flag = 0;
		last = n - lim;
		for(t=n-1;t>=last;t--){
			if(generate(t) == n){
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("%d\n", n);
	}
	lim = 4*9;
	for(n=1000;n<10000;n++){
		flag = 0;
		last = n - lim;
		for(t=n-1;t>=last;t--){
			if(generate(t) == n){
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("%d\n", n);
	}
	lim = 5*9;
	for(n=10000;n<100000;n++){
		flag = 0;
		last = n - lim;
		for(t=n-1;t>=last;t--){
			if(generate(t) == n){
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("%d\n", n);
	}
	lim=6*9;
	for(n=100000;n<=1000000;n++){
		last = n - lim;
		flag = 0;
		for(t=n-1;t>=last;t--){
			if(generate(t) == n){
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("%d\n", n);
	}
    
    return 0;
}
