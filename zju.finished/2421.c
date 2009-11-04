#include<stdio.h>
enum {
    MaxSize = 500020,
};
int reca[MaxSize] = {0, 1, 3};
char mark[3020000] = {0};

void init(){
    int m;
    int t;
    for(m=1;m<MaxSize;m++){
        t = reca[m-1] -m;
        if( t > 0 && mark[t] ==0){
            mark[t] = 1;
            reca[m] = t;
        } else {
            t = reca[m-1] +m;
            reca[m] = t;
            mark[t] = 1;
        }        
    }
}

int main(){
    int num;
    init();
    
    scanf("%d",&num);
    while(num >= 0){
        printf("%d\n",reca[num]);
        
        scanf("%d",&num);
    }
    return 0;
}
