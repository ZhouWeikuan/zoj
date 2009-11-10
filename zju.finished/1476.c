#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int clock[60];

int main(){
	int s, d;
	int t;
	
	scanf("%d %d ", &s, &d);
	while(s){
		memset(clock,0,sizeof(clock));
		t = 0;
		clock[s] = 1;
		while(s != 0){
			s +=  s*d;
			s %= 60;
			if(clock[s] == 1){
				t = -1;
				break;
			} else {
				clock[s] = 1;
			}
			t ++;
		}
		if(t >=0)
			printf("%d\n", t);
		else {
			printf("Impossible\n");
		}
		scanf("%d %d ", &s, &d);	
	}
    
    return 0;
}
