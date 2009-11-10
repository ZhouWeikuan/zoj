#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int primelist[200] = {1,2,3,5,7};
int num = 5;

void init(){
	int n,i;
	int lim;
	int flag ;
	for(n=9;n<1000;n++){
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
}

int findplace(int n){
	int hi = num, low =0 ;
	if(n < num)	
		hi = n;
	int mid;
	while(hi > low){
		mid = (hi + low) / 2;
		if(primelist[mid] < n){
			low = mid + 1;
		} else if(primelist[mid] > n){
			hi = mid;
		} else {
			break;
		}
	}
	if(hi ==low)
		mid = low;
	if(primelist[mid] == n){
		mid ++;
	}
	return mid;
}

void fun(int n, int k){
	int start, end;
	printf("%d %d:", n, k);
	
    n = findplace(n);
    if(n%2 ==0){
		if(2*k > n){
			start = 0;
			end = n;
		} else {
			start = n/2;
			end = start + k;
			start -= k;
		}
	} else {
		if(2*k-1>n){
			start = 0;
			end = n;
		} else {
			start = n/2;
			end = start + k;
			start -= k - 1;
		}
	}	
		
	for( ; start < end;start ++){
		printf(" %d", primelist[start]);
	}
	printf("\n");
}

int main(){
	int n,k;	
    init();
    
    scanf("%d %d",  &n, &k);
    while(! feof(stdin)){							
		fun(n,k);		
		printf("\n");
		scanf("%d %d",  &n, &k);	
	}
	
    return 0;
}
