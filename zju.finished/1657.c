#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int primelist[4000] = {2,3,5,7};
int num = 4;
int even;

void init(){
	int n,i;
	int lim;
	int flag ;
	for(n=9;n<32800;n+=2){
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

int findplace(){
	int hi = num, low = 0;
	int mid;
	
	while(hi > low){
		mid = (hi + low) / 2;
		if( primelist[mid] < even){
			low = mid + 1;
		} else {
			hi = mid;
		}
	}	
	if(hi == low)
		mid = low;
	if(primelist[mid] > even)
		mid --;
	return mid;
}

void fun(){
    int ret = 0;
    int start = 0;
    int end = findplace();
    int sum;
    
    while(end >= start){
		sum = primelist[start] + primelist[end];
		if(sum > even){
			end --;
		} else if(sum < even){
			start ++;
		} else {
			ret ++;
			end --;
			start ++;
		}		
	}
    printf("%d\n", ret);
}

int main(){	
    init();
    
    scanf("%d", &even);
    while(even){
		fun();
		scanf("%d", &even);
	}
    
    return 0;
}
