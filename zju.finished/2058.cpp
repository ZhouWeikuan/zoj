#include<iostream>
using namespace std;
enum {
    SIZ = 102,
};
// 由于每行*@不可能连续出现，
//因此根据首字推算@的最小最大出现次数
int head[SIZ];
char buf[SIZ];
int N;

void calc(int cur){
    int i;
    for(i=0; buf[i] && buf[i] == '?';i++){
        ;
    }
    if(buf[i]=='*'){
        head[cur] = (i%2==0)?1:2;
    } else if(buf[i]=='@'){
        head[cur] = (i%2==0)?2:1;
    } else {
        head[cur] = 0;
    }
}
void readIn(){
    for(int i=0;i<N;i++){
        scanf("%s", buf);
        calc(i);
    }
}
void fun(){
    int high = 0, low = 0;
    int t,p;
    for(int i=0;i<N;i++){
        t = (i+1)/2; // 中间的
        p = (i+1) - t; // 两边的，多
        if(head[i]){
            if(head[i] == 1){
                high += t;
                low += t;
            } else {
                high += p;
                low += p;
            }
        } else {
            high += p;
            low += t;
        }
    }
    printf("%d %d\n",high, low);
}
int main(){

    scanf("%d",&N);
    while(N > 0){
        readIn();
        fun();
        scanf("%d",&N);
    }

    return 0;
}
