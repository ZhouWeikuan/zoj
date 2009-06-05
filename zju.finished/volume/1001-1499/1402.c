#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
    Size = 40,  
};

int meal[Size];
int num;
int sum;

void fun(){
    int i;
    int half = sum/2;
    int value = 0;
    
    for(i=0;i<num && value < half; i++){
        value += meal[i];
    }
    if(value == half){
        printf("Sam stops at position %d and Ella stops at position %d.\n", i, i+1);
    } else {
        printf("No equal partitioning.\n");
    }
    
}

int main(){
    int i;
    
    scanf("%d", &num);
    while(num){
        sum = 0;
        for(i=0;i<num;i++){
            scanf("%d ", &meal[i]);
            sum += meal[i];
        }
        if(sum %2 ){
            printf("No equal partitioning.\n");
        } else {
            fun();
        }
        
        scanf("%d", &num);
    }
 
    return 0;   
}
