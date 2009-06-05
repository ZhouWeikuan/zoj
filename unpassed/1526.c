#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double save[100004];

void calc(int n){
    if(n==0)
        return;
    if(save[n])
        return;
    calc(n-1);
    int start = (n-1) *100+1;
    int end = n*100;
    double ret = save[n-1];
    while( start < end){        
        ret += log10(start);
        start++;
    }
}

int main(){
    int n;
    double result;
    
    int num;
    int start;
    scanf("%d", &num);
    while(num --){
        scanf("%d", &n);
        start = n/100;
        calc(start);
        result = save[start];
        for(start = start *100 +1; start <=n ; start++){
            result += log10(start);
        }
        start = result + 1;
        printf("%d\n", start);
    }
    
    return 0;   
}
