#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 64,	
};

int num;
char digit[Size][Size];
char buffer[Size];
char outputbuffer[Size];

void init(){
	int i;
	char c;
	num = strlen(digit[0]);
	memcpy(outputbuffer,digit[0],sizeof(char)*(num+1));
	for(i=0;i<num;i++){
		digit[0][i] -= '0';
	}
	for(i=1;i<num;i++){
		c = digit[i-1][0];
		memmove(digit[i],&digit[i-1][1], sizeof(char)*(num-1));
		digit[i][num-1] = c;
	}
}

int comp(const char *a, const char *b){
	int i;
	for(i=0;i<num;i++){
		if(a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}
int mult(char *s,char *d,int n){
	int carry = 0;
	int i;
	s[num] = 0;
	for(i=num-1;i>=0;i--){
		carry = d[i] * n + carry;		
		s[i] = carry % 10;
		carry /= 10;		
	}
	return carry;
}

void fun(){
	int i;
	int flag = 0;
	init();
	qsort(digit,num,sizeof(char)*Size,(int(*)(const void*,const void*))comp);
	for(i=2;i<=num;i++){
		flag = mult(buffer,digit[0],i);
		if(flag || comp(buffer,digit[i-1]) !=0 ){
			flag = 1;
			break;
		}
	}
	for(i=0;i<num;i++){
		digit[0][i] += '0';
	}
	if(flag ){
		printf("%s is not cyclic\n",outputbuffer);
	} else {
		printf("%s is cyclic\n",outputbuffer);
	}
}

int main(){    
    
    scanf("%s", digit[0]);
    while(!feof(stdin)){
		fun();
				
		scanf("%s", digit[0]);	
	}
    
    return 0;
}
