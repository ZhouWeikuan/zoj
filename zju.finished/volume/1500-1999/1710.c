#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double H,U,D,F;

int main(){
	double cur;
	int day;
	scanf("%lf %lf %lf %lf ", &H, &U, &D, &F);
	while(H > 0){
		day = 1;
		cur = U;
		F = F * U /100;
		while(cur <= H){
			cur -= D;
			if(cur < 0)
				break;
			day ++;
			U -= F;
			if(U < 0)
				U = 0;
			cur += U;
		}
		if( cur >= H){
			printf("success on day %d\n", day);
		} else {
			printf("failure on day %d\n", day);
		}
		
		scanf("%lf %lf %lf %lf ", &H, &U, &D, &F);
	}	

	return 0;
}
