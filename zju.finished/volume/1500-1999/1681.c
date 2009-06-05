#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int num;
enum {
	MAXVALUE = 151200,
};
int cubic[60];
int cpos;

int hedral[100];
int hpos;

void init(){
	int i;
	int value = 0;
	for(i=0; value < MAXVALUE; i++){
		value = i * i *i;
		cubic[i] = value;
	}
	cpos = i; value = 0;
	for(i=0; value < MAXVALUE; i++){
		value = i * (i + 1) * (i+2);
		value /= 6;
		hedral[i] = value;
	}
	hpos = i;
}

int find_cubic(){
	int hi = cpos, low = 0;
	int mid;
	while(hi > low){
		mid = (hi + low )/ 2;
		if(cubic[mid] < num){
			low = mid + 1;
		} else if(cubic[mid] > num){
			hi = mid;
		} else {
			break;
		}
	}
	if(hi == low)
		mid = low;
	if(cubic[mid] > num)
		mid --;
	return mid;
}
int find_hedral(int n){
	int hi = hpos, low = 0;
	int mid;
	while(hi > low){
		mid = (hi + low )/ 2;
		if(hedral[mid] < n){
			low = mid + 1;
		} else if(hedral[mid] > n){
			hi = mid;
		} else {
			break;
		}
	}
	if(hi == low)
		mid = low;
	if(hedral[mid] > n)
		mid --;
	return mid;
}
int fun(){
	int croot = find_cubic();
	int max = cubic[croot];
	int cube, t;
	
	if(max == num){
		goto end;
	}
	while(croot >= 0){
		cube = cubic[croot];
		t = find_hedral(num - cube);
		
		cube += hedral[t];
		if(max < cube) {
			max = cube;
		}
		croot --;
	}	
end:
	return max;
}

int main(){
	int tstcase;

	init();

	scanf("%d", &num);
	while(num > 0){
		printf("%d\n", fun());
		scanf("%d", &num);
	}

	return 0;
}
