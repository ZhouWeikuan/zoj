#include<stdio.h>

double sum = 0;

int main(){
    double t;
    int i;
    
    for(i=0;i< 12 ;i++){
        scanf("%lf\n", & t);
        sum += t;
    }
    sum /= 12.0;
    
    printf("$%.2lf\n", sum);       
    
    return 0;
}
