#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
    Size = 10008,  
};

int light;
int num;

int main(){
    int i;
    int first, second;
    int t;
    
    scanf("%d", &num);
    while(!feof(stdin)){
        first = second = 0;
        for(i =0; i< num;i++){
            scanf("%d", &light);
            t = i &0x01;
            if(t ){
                first += light ==0;
                second += light!=0;
            } else {
                first += light!=0;
                second += light==0;
            }            
        }
        if(first < second){
            printf("%d\n", first);
        } else {
            printf("%d\n", second);
        }
        
        scanf("%d", &num);    
    }
 
    return 0;   
}
