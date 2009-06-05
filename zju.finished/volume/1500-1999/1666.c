#include<stdio.h>

enum {
	MaxCoin = 18,
	MaxValue = 305,
};

int  coins[MaxCoin] ;
int  kinds[MaxValue][MaxCoin];
int  values[MaxValue] = {0,1,1,1};
void init(){
	int i;
    for(i=0;i<MaxCoin;i++){
		coins[i] = (i+1)*(i+1);
		kinds[i][0] = 1;
		kinds[1][i] = 1;
		kinds[2][i] = 1;
		kinds[3][i] = 1;
	}

}

void calc(int n){
	if(values[n] != 0){
		return;
	}
	int i;
	int t;
	int sum = 0;
	for(i=0;coins[i] <= n;i++){
		;
	}
	int max = i;
	int keep = 0;
	
	for(i=0;i<max;i++){
		t = n - coins[i];
		keep = 0;
		while(t > 0){
			calc(t);
			if(i>0){
				sum += kinds[t][i-1];
			} else {
				sum += 1;
				break;
			}
			t -= coins[i];
		}
		if(t==0)
			sum += 1;
		
		kinds[n][i] = sum;		
	}
	for(i=max;i<MaxCoin;i++){
		kinds[n][i] = sum;
	}
	values[n] = sum;
}

int main(){
    int num;
    
    init();
    
    scanf("%d",&num);
    while(num){
		calc(num);
		printf("%d\n",values[num]);
		scanf("%d",&num);
	}    
    return 0;
}
