#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char vow[26] = {0};
char buffer[1024];

void init(){
	vow['a' - 'a'] = 1; 	vow['e' - 'a'] = 1;
	vow['i' - 'a'] = 1; 	vow['o' - 'a'] = 1;
	vow['u' - 'a'] = 1; 	vow['y' - 'a'] = 1;
}

int check_vow(char *str){
	int i = 0;
	int ret = 0;
	
	while(str[i]){
		while( str[i] && (str[i]==' ' || vow[str[i]-'a'] == 0 )){
			i++;
		}
		if(str[i])
			ret ++;
		while( str[i] && ( str[i] !=' ' && vow[str[i]-'a'] == 1)){
			i++;
		}
	}
	return ret;
}

int fun(){
	int ret;
	char *mid, *last;
	mid = index(buffer,'/');
	*mid = 0;
	ret = check_vow(buffer);
	if(ret != 5)
		return 1;
	mid++;
	last = index(mid,'/');
	*last = 0;
	ret = check_vow(mid);
	if(ret != 7)
		return 2;
	last ++;
	mid = index(last,'\n');
	*mid = 0;
	ret = check_vow(last);
	if(ret !=5 )
		return 3;
	return 0;
}

int main(){
	int t;

	init();

	fgets(buffer, 1024,stdin);
	while(buffer[0] != 'e' || buffer[1] != '/' || buffer[2] != 'o'
		||buffer[3] != '/'|| buffer[4]!='i'||buffer[5]!='\n'){
		t = fun();
		if(t ==0){
			printf("Y\n");
		}else{
			printf("%d\n",t);
		}
		fgets(buffer, 1024, stdin);
	}

	return 0;
}
