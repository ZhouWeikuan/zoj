#include<stdio.h>

char Fabo[1000005] = {1,2};
const char *ans[3] = {"yes","no","no"};

int main(){
    int t;
    int i;
    for(i=2;i<1000005;i++){
        t = Fabo[i-1] + Fabo[i-2];
        Fabo[i] = t%3;
    }
    
    scanf("%d",&t);
    while(!feof(stdin)){
        printf("%s\n",ans[Fabo[t]]);
        scanf("%d",&t);
    }    
    
    return 0;
}
