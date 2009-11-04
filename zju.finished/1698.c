#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 100,
};

int table[26];
char buffer[Size];
int  num;

void init(){
	int i;
	int t;
	for(i=0;i<26;i++){
		t='a' + i;
		switch(t){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				table[i] = 1;
				break;
			default:
				table[i] = 0;
				break;
		}
	}

}

int fun(){
	int i;
	int flag =0;
	/* check for vowal */
	for(i=0; buffer[i]; i++){
		if(table[buffer[i] -'a'] ){
			flag = 1;
			break;
		}
	}
	if(flag ==0) return 0;
	for(i=1; buffer[i];i++){
		if(buffer[i] == buffer[i-1]){
			if(buffer[i] == 'e' || buffer[i] =='o'){
				;
			} else {
				flag = 0;
				break;
			}
		}
	}
	if(flag ==0) return 0;
	int t;
	for(i=2;buffer[i];i++){
		t  = table[buffer[i] -'a'];
		t += table[buffer[i-1] -'a'];
		t += table[buffer[i-2] -'a'];
		if(t==0 || t==3)
			return 0;
	}
	return 1;
}



int main(){
	int i;
	
	init();
	scanf("%s", buffer);
	while(strcmp(buffer,"end")!=0){
		if(fun() ) {
			printf("<%s> is acceptable.\n", buffer);
		} else {
			printf("<%s> is not acceptable.\n", buffer);
		}
		for(i=0;buffer[i];i++)
			buffer[i] = 0;
		scanf("%s", buffer);
	}	

	return 0;
}
