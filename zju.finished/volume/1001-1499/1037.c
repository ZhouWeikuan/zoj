#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    int num,m,n;
    int tstcase = 0;
    double value;
    double crossvalue = sqrt(2.0);
    
    scanf("%d", &num);
    while(num --){
		tstcase ++;
		scanf("%d %d", &m, &n);
		if(m%2 && n%2){
			value = m*n + crossvalue - 1;
		} else {
			value = m*n;
		}
		printf("Scenario #%d:\n",tstcase);
		printf("%.2lf\n",value);
		
		printf("\n");
		
	}
    
    return 0;
}
