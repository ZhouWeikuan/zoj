#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int stack[125004];
int pos=0;

int main(){
    int num;
    int t;
    
    scanf("%d", &num);
    while(!feof(stdin)){
        pos =0;
        while(num--){
            scanf("%d", &t);
            if(pos == 0 || stack[pos-1] ==t){
                stack[pos ++] = t;
                if(pos >= 125004)
                    pos --;
            } else {                
                pos --;                
            }            
        }
        printf("%d\n",stack[0]);
        scanf("%d", &num);
    }
 
    return 0;   
}
