#include<stdio.h>
#include<string.h>

int next[100];

/* 这个现在还有点问题 */
int ZhuHong_getnext(char *str){
	int i,j;
	
	next[0] = -1;	
		
	for(i=1; str[i]; i++){
		j = next[i-1];
		while(j >= 0 && str[i-1] != str[j]){
			j = next[j];
		}
		j++;
		if(str[i] == str[j]) {
			next[i] = next[j];
		} else {
			next[i] = j;
		}
	}
}

int getnext(char *str){
	int i,j;
	
	next[0] = -1;	
		
	for(i=1; str[i]; i++){
		j = next[i-1];
		while(j >= 0 && str[i-1] != str[j]){
			j = next[j];
		}
		
		next[i] = j + 1;
	}
}

int match(char *txt, char *p){
	int i= 0,j =0;
	int start = 0;
	
	while(txt[i]){
		if(txt[i] == p[j]){
			i++;j++;
		} else {
			start += j - next[j];
			j = next[j];
			if(j < 0){
				j = 0;				
				i++;				
			}
		}
		if(p[j] ==0){
			return start;
		}
	}
	
	return -1;
}

int main(){
	int n;
	char text[] ="xyxyyxyxyyxyxyxx";	
	char pattern[]	= "xyxyyxyxyxx";
	
	ZhuHong_getnext(pattern);
	//getnext(pattern);
	n = match(text,pattern);
	printf("%d\n", n);
	
	return 0;
}
