#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char input[20];
char left[20];
int lpos;
char right[20];
int rpos;

int trans(char *p){
	int i = 0;
	int j = 0;
	while(p[i]){
		input[i] = p[i] - '0';
		i++;
	}
	input[i] = 0;
	while(i > 0){
		i --;
		p[j] = input[i];
		j++;
	}
	p[j] = 0;
	return j;
}

int fun(){
    int i = 0,j = 0;
    int carry = 0;
    int sum = 0;
    
    while(i < lpos && j < rpos){
		carry += left[i] + right[j];
		i++, j++;
		carry /= 10;
		if(carry){
			sum ++;
		}
	}
	
	while(i < lpos ){
		carry += left[i];
		i++;
		carry /= 10;
		if(carry){
			sum ++;
		}
	}
	
	while(j < rpos){
		carry += right[j];
		j ++;
		carry /= 10;
		if(carry ){
			sum ++;
		}
	}
	return sum;
}

int main(){
 	int t;
 	
 	scanf("%s %s", left, right);
 	while(left[0] != '0' || strlen(left) > 1 || right[0] != '0' || strlen(right) > 1){
		lpos = trans(left);
		rpos = trans(right);
		t = fun();
		if(t ){
			printf ("%d carry operation", t);
			if(t > 1)
				printf("s");
			printf(".\n");
		} else {
			printf("No carry operation.\n");
		}		
		scanf("%s %s", left, right);
	}
 	
    
    return 0;
}
