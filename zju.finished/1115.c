#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char buffer[1024];

int fun(){
    int ret;
    int i;
    int n = 0;
    for(i=0; buffer[i]; i++){
		n += buffer[i] -'0';
	}
    
    while(n >= 10){
		ret = 0;
		while(n){
			ret += n%10;
			n/= 10;
		}
		n = ret;
	}
	return n;
}

int main(){
    int num;    
    
    scanf("%s", buffer);
    while(buffer[0] != '0'){
		printf("%d\n", fun() );
		
		scanf("%s", buffer);
	}
    
    return 0;
}
