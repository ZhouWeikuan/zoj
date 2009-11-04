#include<stdio.h>

#define MaxSize (5000020)

int  table[MaxSize] = {0,0,0,1,0,1,2,1,0,1,2};
int num;

void init(){
    int t;
    int i;
    for(i=11;i<MaxSize;i++){
        t = i/2;
        table[i] = table[t] + table[i-t];
    }
}

int fun(){
    int t;
    if(num < MaxSize){
        return table[num];
    }
    t = num /2;
    return table[t] + table[num - t];
}

int main(){    
    init();
    
    scanf("%d",&num);
    while( ! feof(stdin)){
        printf("%d\n", fun());
        scanf("%d",&num);
    }    
    return 0;
}
