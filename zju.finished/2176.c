#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    int num;
    int sum;
    int speed,pre,now;
    
    scanf("%d", &num);
    while(num > 0){
        scanf("%d %d", &speed, &pre);
        sum = speed * pre;
        num--;
        while(num --){
            scanf("%d %d", &speed, &now);
            sum += speed * (now-pre);
            pre = now;
        }
        printf("%d miles\n", sum);
        scanf("%d", &num);
    }
 
    return 0;   
}
