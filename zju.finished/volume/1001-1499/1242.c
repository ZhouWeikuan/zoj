#include<stdio.h>
#include<math.h>

enum {
	InitValue = 810,
	Year = 5730,
};
double amount;

void fun(){
    double radio = InitValue;
    int sum = 0;
    static int tstcase = 1;

	radio /= amount;
	radio = log2(radio);
	radio *= Year;
    
	if(radio < 10000){
		radio /= 100;
		radio = round(radio);
		radio *= 100;
	} else {
		radio /= 1000;
		radio = round(radio);
		radio *= 1000;
	}
	sum = (int) radio;
	
	printf("Sample #%d\n",tstcase ++);
	printf("The approximate age is %d years.\n\n",sum);
}

int main(){
    int N,M;
    
    scanf("%d %d", &N, &M);
    while(N){
		amount = (double)M;
		amount /= N;
		fun();
		scanf("%d %d", &N, &M);
	}
    
    return 0;
}
