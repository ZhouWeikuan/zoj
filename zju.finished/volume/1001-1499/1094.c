#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 40,	
};

typedef struct {
    int row;
    int col;  
}Node;

Node stack[Size];
int  pos;

Node matrix[Size];
int num;

char buffer[256];

int fun(){
	int i;
	int ret = 0;	
	pos = 0;	
	
	for(i=0; buffer[i]; i++){
        if(buffer[i] =='('){
            continue;
        } else if(buffer[i] == ')'){
            if(pos < 2)
                return -1;            
            int second = pos -1;
            pos -= 2;
            
            if(stack[pos].col != stack[second].row)
                return -1;
            
            ret += stack[pos].row * stack[pos].col * stack[second].col;
            stack[pos].col = stack[second].col;
            pos ++;
        } else {
            int t = buffer[i] -'A';
            stack[pos] = matrix[t];
            pos++;
        }
        
    }
    
    return ret;
}

int main(){
	int i;
	char c;
	int row,col;
	int t;
		
	scanf("%d ", &num);
	for(i=0;i<num;i++){
        scanf("%c %d %d ", &c,&row,&col);
        matrix[c-'A'].row = row;
        matrix[c-'A'].col = col;
    }
    scanf("%s", buffer);
    while(!feof(stdin)){
        t = fun();
        if(t >=0){
            printf("%d\n", t);
        } else {
            printf("error\n");
        }
        scanf("%s", buffer);
    }
	
	return 0;
}
