#include<stdio.h>

int num;

int fun(){
    int i = 0;
    
    while((num & 0x01) != 0x01){
        num >>= 1;
        i ++;
    }
    printf("%d %d\n",num,i);
}

int main(){
    int tstnum;
    
    scanf("%d",&tstnum);
    while(tstnum--){
        scanf("%d", &num);
        fun();        
    }
    
    return 0;
}
