#include<iostream>
using namespace std;
enum {
    SIZ = 23,
    LEN = 1200000,
};
int bit[SIZ];
int mask[SIZ];
int val[LEN];
int con[SIZ];
int dif[SIZ];
int num;
int st[LEN],top;

void init(){
    int i,b=0;
    for(i=0;i<SIZ;i++){
        bit[i] =  1<<i;
        b <<=1; b++;
        mask[i] = b;
    }
}
int readIn(){
    if(scanf("%d",&num) <= 0)
        return 0;
    num--;
    for(int i=0;i<num;i++){
        scanf("%d%d",&con[i],&dif[i]);
        dif[i] -= con[i];
    }
    scanf("%d",&con[num]);
    dif[num] = 0;
    return 1;
}
void test(){
    int v,n,i,t;
    val[0] = 100;
    top = 0;
    st[top++] = 0;
    while(top > 0){
        v = st[--top];
        for(i=0;i<num;i++){
            if( (v&bit[i])!=0 
                    || val[v] < con[i]){
                continue;
            }
            n = v | bit[i];
            t = val[v] + dif[i];
            if(t > 100) t = 100;
            else if(t<0)
                continue;
            if(t > val[n]){
                val[n] = t;
                st[top++] = n;
            }
        }
    }
}
int fun(){
    memset(val, -1, sizeof(int)*(bit[num]));
    test();
    if(val[mask[num-1]] >= con[num])
        return 1;
    return 0;
}

int main(){
    init();
    while(readIn()){
        if(fun() ){
            printf("clear!!!\n");
        } else {
            printf("try again\n");
        }
    }

    return 0;
}
