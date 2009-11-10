#include<stdio.h>

#define MaxSize (10020)

short stack[MaxSize]; /* The user to be checked */
short slen = 0;

typedef struct {
    short favornum; /* number to show how many people love her */    
    short lovernum;
    short lovers[3];
}Node ;

Node passion[MaxSize];
int num;
int votenum;
int maxcore;

void push(int d){
    if(passion[d].favornum == -1){
        return;
    }
    maxcore --;
    passion[d].favornum = -1;
    stack[slen ++ ] = d;
}

int fun(){
    int i,j,t;
    
    do {
        while(slen > 0){
            i = stack[--slen];
            for(j=0;j<passion[i].lovernum;j++){
                t = passion[i].lovers[j];
                if( passion[t].favornum > 0&& --passion[t].favornum ==0){            
                    push(t);                
                }
            }        
        }
        for(i=1; i<=num;i++){
            if( passion[i].lovernum == 0){
                push(i);
                continue;
            }        
            if(passion[i].favornum <=0){
                push(i);
                continue;
            }
            for(j=0;j<passion[i].lovernum;j++){
                t = passion[i].lovers[j];
                if(passion[t].lovernum == 0 || passion[t].favornum == -1){
                    push(i);
                    break;
                }
            }        
        }        
    }while(slen > 0);
    
    return maxcore;
}

int main(){
    int tstnum;
    scanf("%d",&tstnum);
    
    while( tstnum --){
        scanf("%d %d", &num, &votenum);
        memset(passion, 0, sizeof(Node) * (num+1));
        slen = 0;
        maxcore = num;
        
        while( votenum --){
            int index, t;
            int d;
            scanf("%d %d", &index, &t);
            passion[index].lovernum = t;
            while(t --){
                scanf("%d", &d);
                passion[index].lovers[t] = d;
                passion[d].favornum ++;                
            }            
        }
        printf("%d\n",fun());
    }
    
    return 0;
}
