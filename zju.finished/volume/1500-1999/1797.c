#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lcm;
int other;

int get_gcd(){
	int a = lcm;
	int b = other;
	if(a < b){
		a = b;
		b = lcm;
	}
	int t;
	while(b > 0){
		t = a %b;
		a = b;
		b = t;		
	}
	return a;
}

int get_lcm(){
    int t = get_gcd();
    other /= t;
    lcm *= other;
}

int main(){
    int tstcase;
    int num;
    int t;
    
    scanf("%d", &tstcase);
    while(tstcase --){
		lcm = 1;
		scanf("%d", &num);
		while(num --){
			scanf("%d", &other);
			if(lcm % other !=0){
				get_lcm();
			}
		}
		printf("%d\n", lcm);
	}
    
    return 0;
}
