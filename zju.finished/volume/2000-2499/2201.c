#include<stdio.h>


int main(){
    int tstnum;
    int a,b;
    
    scanf("%d", &tstnum);
    while(tstnum --){
        scanf("%d %d", &a,&b);
        if(a < b){
            printf("NO BRAINS\n");
        } else {
            printf("MMM BRAINS\n");
        }
    }
    return 0;
}
