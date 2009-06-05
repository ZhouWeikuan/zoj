#include<iostream>
using namespace std;
char str[2][300];

int cmp(char *a, char *b){
    int r=1;
    for(;*a&&*b&&*a==*b;){
        ++a,++b;
    }
    while(*b){
        ++r;
        ++b;
    }
    return r;
}

void fun(){
    char *pre=str[0], *cur=str[1], *tmp;
    int len, num, res=0;
    scanf("%d", &num);
    scanf("%s", pre);
    res += strlen(pre);
    for(;num>1; --num){
        scanf("%s", cur);
        res += cmp(pre, cur);
        tmp = cur, cur = pre, pre=tmp;
    }
    printf("%d\n", res);
}

int main(){
    int tst=0, tn;
    scanf("%d", &tn);
    while(tst++ < tn){
        fun();
        if(tst != tn) 
            printf("\n");
    }
    return 0;
}

