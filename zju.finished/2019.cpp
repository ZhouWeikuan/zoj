#include<iostream>
// 组合数学中的差分数列，相当于不断求导
using namespace std;
enum {
    SIZ = 108,
};
int num, pos, cnt;
int dat[SIZ];
int dif[SIZ];

int iterate(){
    int i;
    for(i=pos-2; i>=0; i--){
        dif[i] += dif[i+1];
    }
    return dif[0];
}
void fun(){
    int i;
    pos = 0;
    while(num > 0){
        dif[pos++] = dat[num-1];
        
        --num;
        for(i=0; i<num; i++){
            dat[i] = dat[i+1] - dat[i];
        }
    }
    while(pos > 1 && dif[pos-1] == 0){
        pos--;
    }
    while(cnt > 0){
        i = iterate();
        printf("%d", i);
        if(--cnt)
            printf(" ");
    }
    printf("\n");
}

int readIn(){
    scanf("%d%d", &num, &cnt);
    for(int i=0; i<num; i++){
        scanf("%d", &dat[i]);
    }
    return 1;
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst --){
        readIn();
        fun();
    }
    return 0;
}
