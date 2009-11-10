#include<math.h>
#include<stdio.h>

int prime[1002];

void init(){
	int primelist[200] = {1,2,3,5,7};
	int num = 5;
	int n,i;
	int lim;
	int flag ;
	for(n=9;n<1002;n++){
		lim = (int)sqrt(n) + 1;
		flag = 0;
		for(i=1;primelist[i] < lim;i++){
			if(n % primelist[i] == 0){
				flag = 1;
				break;
			}
		}
		if(flag ==0){
			primelist[num++] = n;
		}
	}
	for(i=0;i<num;i++){
		prime[ primelist[i] ] = 1;
	}
}
int fun(int n){
	if(prime[n] ){
		return 2 + 4 *n;
	}
	int i,j,k;
	int t,p;
	int max = 60000;
	int value;
	for(i=2;i<=n/2;i++){		
		if(n%i){
			continue;
		}
		t = n / i;
		for(j=1;j<=t/2;j++){
			if(t%j)
				continue;
			k = t/j;			
			value = 2*(i*j + j *k + i *k);
			if(value < max)
				max = value;
			
		}
	}
	return max;
}
int main(){
	int tstcase;
	int  n;
	
	init();
		
	scanf("%d", &tstcase);
	while(tstcase --){
		scanf("%d", &n);
		printf("%d\n", fun(n));
	}
}
