#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double first, now;
double diff;

int main(){
	
	scanf("%lf", &first);
	scanf("%lf", &now);
	while(now < 300){
        diff = now - first;
        printf("%.2lf\n", diff);
        first = now;
        scanf("%lf", &now);
    }
    printf("End of Output\n");
	return 0;
}
