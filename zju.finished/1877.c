#include<stdio.h>
#include<stdlib.h>

enum {
    MaxSize = 1200,
};
int speed[MaxSize];
int num;

int comp(const int *a, const int *b){
    return *a - *b;
}

int cross[2400];

void fun(){
    int sum = 0;
    int pos = 0;
    int t;
    int first = speed[0];
    int second = speed[1];
    t = first + second;
    
    while( num > 3){
		if(2*second > first + speed[num-2]){
			sum += first * 2 + speed[num-1] + speed[num-2];
			cross[pos++] = (first<<16) + speed[num-1];
			cross[pos++] = first;
			cross[pos++] = (first<<16) + speed[num-2];
			cross[pos++] = first;
			
		} else {
			sum += 2*second + first + speed[num-1];
			cross[pos++] = (first<<16) + second;
			cross[pos++] = first;
			cross[pos++] = (speed[num-2] <<16) + speed[num-1];
			cross[pos++] = second;
		}
        
        num -= 2;        
    }
    if(num <= 1){
        sum += speed[num-1];
        cross[pos++] = first;
    } else if(num == 2){
        sum += speed[num-1];
        cross[pos++] = (first <<16) + second;
    } else { /* num == 3 */
        sum += t;
        cross[pos++] = (first <<16) + second;
        cross[pos++] = first;
        
        sum += speed[num-1];
        cross[pos++] = (first <<16) + speed[num-1];
    }
    printf("%d\n",sum);
    int i;
    for(i=0;i<pos;i++){
        first = cross[i] >> 16;
        second = cross[i] & 0x0ffff;
        if(first){
            printf("%d %d\n",first,second);
        } else {
            printf("%d\n",second);
        }
    }
}

int main(){
    int i;
    
    scanf("%d", &num);
    while(!feof(stdin)){
        for(i=0;i<num;i++){
            scanf("%d", &speed[i]);
        }
        qsort(speed,num,sizeof(int), (int (*)(const void*, const void*))comp);
        fun();
        scanf("%d", &num);
    }
    
    return 0;
}
