#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 100,
};

char buffer[Size];
int conv(int start,int end){
	end --;
	while(buffer[end] =='0'){
		end --;
	}
	int ret = 0;
	while(end >= start){
		ret *= 10;
		ret += buffer[end] - '0';
		end --;
	}
	return ret;

}
void fun(){
	int a,b,c;
	int i = 0;
	while(buffer[i] !='+'){
		i++;
	}
	buffer[i] = 0;
	a = conv(0,i);
	i++;
	b = i;
	while(buffer[i] !='='){
		i++;
	}
	buffer[i] = 0;
	b = conv(b,i ++);
	c = i;
	while(buffer[i])
		i++;
	c = conv(c,i);
	if(a + b == c){
		printf("True\n");
	} else {
		printf("False\n");
	}
}

int main(){
	int tstcase;
	
	scanf("%s", buffer);	
	while(buffer[0] !='0' || buffer[1]!='+' 
		|| buffer[2]!='0' || buffer[3]!='='
		||buffer[4]!='0'|| buffer[5]){
		fun();
		scanf("%s", buffer);	
	}

	printf("True\n");

	return 0;
}
