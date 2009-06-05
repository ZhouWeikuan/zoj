#include<stdio.h>

void compute(int n){
    int first = 1;
    int start = 0;
    
    while(n > 0){
        if(n % 2){
            if(first){
                first = 0;
                printf("%d", start);
            } else {
                printf(" %d", start);
            }            
        }
        n /= 2;
        start ++;
    }
    printf("\n");
}

int main(){
    int num;   
    int value;
    
    scanf("%d", &num);
    while(num -- ){
        scanf("%d", &value);
        compute(value);        
    }
    
}
