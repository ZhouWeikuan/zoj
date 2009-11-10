#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<strings.h>

enum {
	Size = 100,
};

char buffer[Size][Size];
int charnum;
int digit[Size];
int dignum;
int mark[Size * 2];
int pos;

int mycomp(int *a, int *b){
	return *a - *b;
}

int main(){
	int len;
	
	charnum = dignum= pos =0;
	scanf("%s", buffer[charnum]);
	len = strlen(buffer[charnum]);
	while(len > 1 || buffer[charnum][0]!='.'){
		while(1){
			char c;
			len --;
			c = buffer[charnum][len];
			buffer[charnum][len] = 0;
			len --;
			if(buffer[charnum][len] <='9' && buffer[charnum][len]>='0'){
				mark[pos] = 1;
				digit[dignum++] = atoi(buffer[charnum]);
			} else {
				charnum ++;
				mark[pos] = 0;
			}
			pos ++;
			if(c =='.')
				break;
			scanf("%s", buffer[charnum]);
			len = strlen(buffer[charnum]);
		}
		qsort(buffer, charnum, sizeof(buffer[0]), strcasecmp);
		qsort(digit,dignum,sizeof(int),mycomp);
		
		int i,j = 0,k = 0;
		for(i=0;i<pos;i++){
			if(mark[i] == 1){
				printf("%d",digit[k]);
				k++;
			}else{
				printf("%s",buffer[j]);
				j++;
			}
			if(i!= pos-1){
				printf(", ");
			}else {
				printf(".");
			}
		}
		printf("\n");

		charnum = dignum= pos =0;
		scanf("%s", buffer[charnum]);
		len = strlen(buffer[charnum]);	
	}

	return 0;
}
