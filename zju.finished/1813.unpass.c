#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const float PI = 3.1415927;

int main(){
	float diameter;
	int revolution;
	int second;
	float distance;	
	float mph;
	int tstcase = 1;
	
	scanf("%f %d %d ", &diameter, &revolution, &second);
	while(revolution > 0 ){
        distance = PI * diameter * revolution / (12 * 5280);
        mph = distance * 3600/second;
        
        printf("Trip #%d: %.2f %.2f\n", tstcase ++, distance, mph);
                
        scanf("%f %d %d ", &diameter, &revolution, &second);    
    }
	
	return 0;
}
