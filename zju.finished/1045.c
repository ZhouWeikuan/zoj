#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double value[280];
double input;

void init(){
    int n;
    double sum = 0.0;
    
    for(n = 2; n < 281; n ++) {
		sum += 1.0/n;
		value[n-1] = sum;
	}	
}


int findplace(){
	int hi= 280,low =0;
	int mid;
	
	while(hi > low){
		mid = (hi + low) / 2;
		if(value[mid] > input) {
			hi = mid;
		} else if(value[mid] < input){
			low = mid + 1;
		} else {
			break;
		}
	}
	if(hi == low)
		mid = low;
	if(value[mid] < input)
		mid ++;
	return mid;
}

int main(){
	int n;
	
    init();    
    
    scanf("%lf", &input);
    while(input > 0){
		n = findplace();
		printf("%d card(s)\n", n);
		scanf("%lf", &input);
	}
    
    return 0;
}
