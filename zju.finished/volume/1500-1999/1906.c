#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 与m互素的剩余类个数为 O(m) , O(m) = m (1 - 1/p1)(1-1/p2)...(1-1/pn) 

	其中，　p1,p2,...pn为m的素因子 
*/

int primelist[1240] = {2,3,5,7};
int num = 4;

void init(){
	int n,i;
	int lim;
	int flag ;
	for(n=9;n<10000;n+=2){
		lim = (int)sqrt(n) + 1;
		flag = 0;
		for(i=0;primelist[i] < lim;i++){
			if(n % primelist[i] == 0){
				flag = 1;
				break;
			}
		}
		if(flag ==0){
			primelist[num++] = n;
		}
	}	
}

int value;
int stack[2000];
int pos;
int fun(){
    int lim = sqrt(value) + 1;
    int i, flag;
    int sum = value;
    
    pos = 0;
    for(i=0; primelist[i] < lim; i++){
		flag = 0;
		while(value % primelist[i] ==0){
			flag ++;
			value /= primelist[i];
		}
		if(flag ){			
			stack[pos ++] = primelist[i];
			lim = sqrt(value ) + 1;
			flag = 0;
		}
	}
	if(value > 1)
		stack[pos ++] = value;		
	
	for(i=0;i<pos; i++){
		sum -= sum/stack[i];
	}
	printf("%d\n", sum);
}

int main(){
    
    init();
    scanf("%d", &value);
    while(value >0 ){
		fun();
		scanf("%d", &value);	
	}
    
    return 0;
}
