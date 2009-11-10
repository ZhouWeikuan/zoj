#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 1024,	
};

char pattern[Size];

int fun(){
	int i=0;
	char c;
	
	scanf("%c", &c);
	while(c!='\n'){  
        if(pattern[i] == c)
            i++;
        scanf("%c", &c); 
    }
    
    return pattern[i] ==0;
}

int main(){
	
	scanf("%s ", pattern);
	while(!feof(stdin)){
        if(fun()){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        scanf("%s ", pattern);
    }
	
	return 0;
}
