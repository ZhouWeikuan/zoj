#include<stdio.h>

int mid;
int num;

void process(){
    int pred;
    int suff;
    int t;
    int remid;
    
    for(pred = 90000; pred > 0 ; pred -= 10000){
        suff = 9;        
        t = pred + mid + suff;
        remid = t % num;
        if(remid == 0){            
            break;
        }
            
        suff -= remid;            
        if(suff >=0){
            t -= remid;
            break;
        }
    }
    
    if(pred){
        pred /= 10000;
        printf("%d %d %d\n",pred, suff, t/num);
    } else {
        printf("0\n");
    }
    
}

int main(){
    int tstcount;
    int a,b,c;
    
    scanf("%d\n", &tstcount);
    while(tstcount --){
        scanf("%d\n", &num);
        scanf("%d %d %d\n", &a,&b,&c);
        mid = a*1000 + b*100 + c*10;
        process();
    }
    
    return 0;
}
