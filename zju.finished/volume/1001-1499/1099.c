#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 100,
};
char buffer[Size];
int  pos;
char input[Size];
int  num;


int main(){
	
	pos = 0;
	scanf("%s ", input);
	while(1){
		num = strlen(input);
		if(num==4 && (strcmp(input,"<br>")==0||strcmp(input,"<hr>")==0)){
			if(input[1] =='b'){ /* br */
				if(pos ==0){
					printf("\n");
				} else {
					buffer[pos] =0;
					printf("%s\n",buffer);
					pos = 0;
				}
			} else { /* hr */
				if(pos !=0){
					buffer[pos] = 0;
					printf("%s\n",buffer);
					pos = 0;
				}
				int i;
				for(i=0;i<80;i++)
					printf("-");
				printf("\n");
			}
		} else {
			if(pos == 0){
				strcpy(buffer,input);
				pos = num;
			} else if(pos + num + 1 <= 80){
				buffer[pos++] = ' ';
				strcpy(buffer+pos, input);
				pos += num;
			} else {
				buffer[pos] = 0;
				printf("%s\n",buffer);
				strcpy(buffer,input);
				pos = num;
			}
		}
		
		if(feof(stdin))
			break;
		scanf("%s ", input);
	}	
	if(pos){
		buffer[pos] = 0;
		printf("%s\n",buffer);
	}

	return 0;
}
