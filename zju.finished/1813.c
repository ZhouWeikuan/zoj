#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const double PI = 3.1415927;

int main(){
	int tstcase = 0;
	
	double R, dis, MPH, second;
	int rev;
	
	scanf("%lf %d %lf ", &R, &rev, &second);
	while(rev != 0) {
		dis = PI * R * rev /12 /5280;
		MPH = dis * 3600 / second;
		printf("Trip #%d: %.2lf %.2lf\n", ++tstcase, dis, MPH);
		
		scanf("%lf %d %lf ", &R, &rev, &second);
	}
	return 0;
}
