#include<iostream>
// 将数看作三进制的，各位取[0,1,2]，即除3的余数
// 结果也是三进制的，各位取[-1,0,1]，如果某位超过，本位减3，下一位加1
// 
using namespace std;
enum {
    SIZ = 500000000,
};
int lim;
int tri[22];
int mark[22];
int num;

void init(){
    int t=1;
    for(lim=0; t < SIZ; lim++){
        tri[lim] = t;
        t *= 3;
    }
}
int output(int v){
    bool first = true;
    int cnt = 0;
    for(int i=0;i<22;i++){
        if(mark[i] != v)
            continue;
        cnt++;
        if(first){
            printf("%d", tri[i]);
            first = false;
        } else {
            printf(" %d", tri[i]);
        }
    }
    return cnt;
}
void fun(){
    int i = 0, t;
    memset(mark, 0, sizeof(mark));
    while(num){
        mark[i] = num % 3;
        num /= 3;
        i++;
    }
    for(i=0;i<30;i++){
        if(mark[i]>1){
            mark[i] -= 3;
            mark[i+1] += 1;
        }
    }
    t = output(-1);
    if(t==0)
        printf("-1");
    printf("\n");
    t = output(1);
    if(t==0)
        printf("-1");
    printf("\n\n");
}
int main(){
    init();
    while( scanf("%d",&num) != EOF){
        fun();
    }
    return 0;
}

