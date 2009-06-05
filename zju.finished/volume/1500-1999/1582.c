#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 100,	
};
char correct[Size];
int cpos;
char wrong[Size];
int wpos;


int fun(){
	int i;
	cpos = strlen(correct) -1;
	correct[cpos] = 0;
	wpos = strlen(wrong) -1;
	wrong[wpos] = 0;
	for(i=0; correct[i] && wrong[i] ; i++){
        if(correct[i] != wrong[i])
            break;
    }
    
    return (cpos + wpos - i - i);
}

int main(){
	int tstnum;
	int cost;
	int num;
	
	scanf("%d\n", &tstnum);
	while(tstnum --){
        scanf("%d", &cost);
        fgets(correct,Size,stdin);
        fgets(correct,Size,stdin);
        fgets(wrong,Size,stdin);        
        num = fun();
        printf("%d\n", num * cost);
        
    }
	
	return 0;
}
