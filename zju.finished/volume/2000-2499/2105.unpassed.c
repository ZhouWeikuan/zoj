#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int value[100];
int mark[100];
int A,B,N;

void fun(){    
    int next;
    int pos = 1;
    int key;
    
    value[0] = 1;
    value[1] = 1;
    memset(mark,0,sizeof(mark));        
    key = value[0] * 7 + value[1];
    while(mark[key] == 0){
        mark[key] = 1;        
        pos ++;
        
        next = A * value[pos-1] + B *value[pos-2];
        next %= 7;        
                
        value[pos] = next;
        key = value[pos-1] *7 + value[pos];
    }
    pos -= 1;
    N = (N-1)% pos;
    printf("%d\n", value[N]);
}


int main(){
    
    scanf("%d %d %d", &A,&B,&N);
    while(A || B || N){
        fun();        
        scanf("%d %d %d", &A,&B,&N);
    }
 
    return 0;   
}
