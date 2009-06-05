#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double lower;
double e;
double faraway;
void init(){
    e = exp(1.0);
    faraway = 100;
}

void fun(){
	double start = e;
	double end = faraway;
	double value = log(lower)/lower;
	
	double mid;
	while(end - start > 0.0000001){
		mid = (start + end) /2;
		if( log(mid)/mid > value){
			start = mid;
		} else {
			end = mid;
		}
	}
	printf("%.5lf\n", mid);
}

int main(){
    
    init();
    
    scanf("%lf", &lower);
    while(!feof(stdin) ){
		if(lower > e){
			printf("-1\n");
		} else {
			fun();
		}
		
		scanf("%lf", &lower);
	}
    
    
    return 0;
}
