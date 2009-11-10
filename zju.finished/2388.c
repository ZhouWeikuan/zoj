#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sum, diff;

int main(){
    int tstcase;
    int a,b;
    
    scanf("%d", &tstcase);
    while(tstcase -- ){
		scanf("%d %d", &sum, &diff);
		if(sum < diff || (sum + diff) %2 ==1){
			printf("impossible\n");
		} else {
			a = (sum + diff)/2;
			b = sum - a;
			printf("%d %d\n", a,b);
		}
	}
    
    return 0;
}
