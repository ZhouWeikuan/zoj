#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 108,
};

char buffer[Size][Size];
char match[Size * 10];
int len, pos;

void rotate(){
	len = strlen(buffer[0]);
	int i,j;
	for(i=1;i<len;i++){
		memmove(&buffer[i][0], &buffer[0][i], len - i);
		memmove(&buffer[i][len-i], &buffer[0][0], i);
		buffer[i][len] = 0;
	}
	qsort(buffer, len, sizeof(buffer[0]),strcmp);
	
	i = 1,j = 0;
	for(; i<len;i++){
		if(strcmp(buffer[i], buffer[j]) != 0){
			if(i!=j){
				++ j;
				strcpy(buffer[j],buffer[i]);				
			}
		}
	}
	pos = j + 1;
}


int fun(){
    int ret = 0, i;
    char save;
    rotate();
    for(i=0; match[i+len-1] != 0; i++){
		save = match[i + len ];
		match[i+len] = 0;
		
		if(bsearch(&match[i], buffer, pos, sizeof(buffer[0]),strcmp) != 0){
			ret ++;
		}		
		
		match[i+len] = save;
	}
	return ret;
}

int main(){
    
    scanf("%s %s", match,buffer[0]);
    while(!feof(stdin)){
		printf("%d\n", fun());
		scanf("%s %s", match,buffer[0]);
	}
    
    return 0;
}
