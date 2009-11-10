#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char cust[1024];
char alphabet[27];
int salon;

int fun(){
    int ret = 0;
    int i;
    int t ;
    for(i=0; cust[i]; i++){
        t = cust[i] - 'A';
        switch(alphabet[t]){
            case 0:
                if(salon){
                    salon --;
                    alphabet[t] = 1;
                } else {
                    alphabet[t] = 10;
                }                
                break;
            case 1:
                salon ++;
                alphabet[t] = 0;
                break;
            case 10:
                alphabet[t] = 0;
                ret ++;
                break;
        }
    }
    
    return ret;
}

int main(){
    int t;
    
    scanf("%d", &salon);
    while( salon ){
        scanf("%s", cust);
        t = fun();
        
        if(t ){
            printf("%d customer(s) walked away.\n",t);
        } else {
            printf("All customers tanned successfully.\n");
        }
        
        scanf("%d", &salon);
    } 
    
    return 0;   
}
