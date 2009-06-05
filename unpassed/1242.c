#include<stdio.h>

enum {
	InitValue = 810,
	Year = 5730,
};
int amount;

void fun(){
    int radio = InitValue;
    int sum = 0;
    static int tstcase = 1;
    
    while(radio/2 > amount){
		sum += Year;
		radio /= 2;		
	}
	sum += (radio - amount) * Year *2/ radio;
	if(sum < 10000){
		sum /= 100;
		sum *= 100;
	} else {
		sum /= 1000;
		sum *= 1000;
	}
	
	printf("Sample #%d\n",tstcase ++);
	printf("The approximate age is %d years.\n\n",sum);
}

int main(){
    int N,M;
    
    scanf("%d %d", &N, &M);
    while(N || M){
		amount = M/N;
		fun();
		scanf("%d %d", &N, &M);
	}
    
    return 0;
}
