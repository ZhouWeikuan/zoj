#include<stdio.h>

int main(){
    int a,b;
    
    scanf("%d %d", &a, &b);    
    while(! feof(stdin)){
        printf("%d\n", a+ b);
        scanf("%d %d", &a, &b);
    }
    
    return 0;
    
}   
    
