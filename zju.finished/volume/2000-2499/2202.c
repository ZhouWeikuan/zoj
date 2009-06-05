#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pos;

/*注意 110, 101 这种情况 */ 

int main(){
	char pred,now;
	long long first, second, third ,t;
    
	scanf("%c", &now);
    while(now !='0'){
		now -= '0';
		pred = now;
		first = second = 1;
		third = 0;
		
		scanf("%c", &now);
		while(now != '\n'){
			now -= '0';
			third = second;
			if(now ==0){
				third = first;
			}else if((pred == 1 || (pred==2 && now <=6) )){
				third += first;
			}
			pred = now;
			t = first;
			first = second;
			second = third;
			third = t;
			
			scanf("%c", &now);
		}
		printf("%lld\n", second);

		scanf("%c", &now);
	}
    
    return 0;
}

