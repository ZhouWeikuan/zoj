#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

enum {
	Size = 1000000,		
};
int prime[78498] = {2,3,5,7};
int pos = 4;

void init(){
	int n = 9;	
	int i;	
	
	while(n < Size){                
        for(i=0; prime[i] * prime[i] < n; i++){
            if(n% prime[i] ==0){                
                break;
            }
        }
        if(n % prime[i] !=0){
            prime[pos++] = n;
        }
        n+=2;
    }
    
}

int find(int n){
    int hi, low;
    int mid;
    low = 0;    
    if(n > 78498){
        hi = 78498;
    } else {
        hi = n;
    }
    
    while(hi >low){
        mid = (hi + low)/2;
        if(prime[mid] == n){
            return mid;
        } else if (prime[mid] < n){
            low = mid + 1;
        } else {
            hi = mid;
        }
    }
    if(hi == low)
        mid = low;
    if(prime[mid] == n)
        return mid;
    return -1;
}

int main(){
	int num;
	int i,t;
	
	init();
	
	scanf("%d", &num);
	while(num){
        for(i=0; prime[i] < num;i++){
            t = find(num - prime[i]);
            if(t >=0){
                break;
            }
        }
        printf("%d = %d + %d\n", num, prime[i], prime[t]);
        scanf("%d", &num);
    }
	
	return 0;
}
