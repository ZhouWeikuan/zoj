#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 1008,
};

char input[260];
char buffer[Size * Size];
int pos;
void fun(){
	int rec;
	while(input[pos] !=')' && input[pos]!=0){
		rec = 0;
		while(input[pos]<='9'&& input[pos]>='0'){
			rec *= 10;
			rec += input[pos] -'0';
			pos ++;
		}
		if(rec ==0)
			rec = 1;
		if(input[pos]=='('){
			pos ++;
			int save = pos;
			while(rec --){
				pos = save;
				fun();
			}
		}else {
			while(rec --){
				printf("%c", input[pos]);
			}
			pos ++;
		}
	}
	pos ++;
}

int main(){
	int num;
	int end;
	scanf("%d", &num);
	while(num--){
		scanf("%s", input);
		pos = 0;
		fun();
		printf("\n");
	}

	return 0;
}
