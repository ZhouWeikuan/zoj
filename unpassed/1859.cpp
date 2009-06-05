#include<iostream>
using namespace std;
// L为总长度，取前n个车，使用len(n) >= 2*L;
// 较大一部分在mark上反映出来
// Wrong Answer
enum {
    SIZ = 108,
};
struct Node{
    int pre;
    int cur;
};
Node mark[SIZ*SIZ];
int num, lim;
int car[SIZ*2];
int sum[SIZ*2];

void fun(){
    memset(mark, -1, sizeof(mark[0])*(lim+8));
    mark[0].pre = 0, mark[0].cur = 0; 
    int i,j,t,last=-1, rem=0;
    for(i=0; i<num; i++){
        for(j=lim-1; j>=0; j--){
            if(mark[j].pre == -1) continue;
            if(sum[i] - j > lim){
                break;
            }
            t = j + car[i];
            if(t <=lim && mark[t].cur == -1){
                mark[t].cur = i;
                mark[t].pre = j;
                if(last < i){
                    last = i;
                    rem = t;
                } 
            }
        }
    }
    memset(car, 0, sizeof(car));
    i = rem;
    while(i>0){
        car[mark[i].cur] = 1;
        i = mark[i].pre;
    }
    printf("%d\n", ++last);
    for(i=0; i<last; i++){
        printf("%s\n", car[i]?"port":"starboard");
    }
}

int readIn(){
    if(scanf("%d", &lim)<0)
        return 0;
    lim *= 100;
    num = 0; sum[0] = 0;
    int t;
    scanf("%d", &t);
    while(t > 0){
        if(sum[num] < 2*lim){
            car[num++] = t;
            sum[num] = sum[num-1] + t;
        }
        scanf("%d", &t);
    }
    return 1;
}
int main(){

    while(readIn() > 0){
        fun();
    }
    return 0;
}

