#include<stdio.h>

#define MaxSize (50)

char    array[MaxSize];
int     len;

void parse(){
    int i;    
    int pos = 0;
    int pred = 0;
    int cur;
    int parnum;
    int t;
    len = 0;
    
    scanf("%d", &parnum);    
    for(i=0;i<parnum;i++){
        scanf("%d", &cur);
        while(pred < cur){
            array[len ++] = pos++;
            pred ++;
        }
        pos ++;
        t = array[--len];
        t = (pos + 1 - t) / 2;
        if(i == 0 ){
            printf("%d", t);
        } else {
            printf(" %d", t);
        }
    }
    printf("\n");
}

int main(){
    int tstnum;
    
    scanf("%d", &tstnum);
    
    while( tstnum --){
        parse();
        
    }
    return 0;
}
