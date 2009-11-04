#include<stdio.h>

int num;
int seq[1020];
int score[1020];
int maxscore;

void init(){
    maxscore = 1;
    score[num-1] = 1;    
}

void calc(int pos){
    int i;
    int t = 0;
    for(i=pos+1;i<num;i++){
        if(seq[i] > seq[pos]){
            t = t < score[i]? score[i]:t;
        }
    }
    score[pos] = ++t;
    maxscore = maxscore < t? t:maxscore;
}

void fun(){
    int i = num-2;
    init();
    while(i>=0){
        calc(i);
        i--;
    }
}

int main(){
    int tstnum;
    int i;
    
    scanf("%d",&tstnum);
    while(tstnum -- ){        
        scanf("%d", &num);
        for(i=0;i<num;i++){
            scanf("%d", &seq[i]);
        }
        
        fun();
        printf("%d\n",maxscore);
        if(tstnum >0 )
            printf("\n");
    }
    return 0;
}
