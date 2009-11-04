#include<stdio.h>
#include<math.h>

enum {
	Size = 1000002,
};

char isprime[Size]= {0,0,1,1};

void calc(int n){	
	int t = 0;
	int i;
	int lim;
	int div;	
    
    if(isprime[n])
    	return;
    
	lim = sqrt(n) + 1;
	for(i=2;i<lim;i++){
		if(n%i ==0){
			t ++;
			div = n / i;
			calc(div);
			if(isprime[div] == 1){
				isprime[n] = 2;
			} else {
				isprime[n] = 3;
			}
			break;
		}
	}
	if(t ==0){
		isprime[n] = 1;
	}
}

int main(){
    int num;
    
    scanf("%d",&num);
    while(!feof(stdin)){
		calc(num);
		if(isprime[num] == 2){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		scanf("%d",&num);
	}      
    
    return 0;
}
