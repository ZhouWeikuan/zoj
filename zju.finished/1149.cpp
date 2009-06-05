#include<iostream>
using namespace std;
enum {
    SIZ = 180000,
};
int m[6];
int a[SIZ];
int b[SIZ];
int tab[2][SIZ];
int half;

void dp(int p, int *now, int *nex){
    int v = p + 1;
    memset(nex, 0, sizeof(int)*(half+10));
    int i,j, t;
    for(i=half; i>=0; --i){
        if(now[i] == 0) continue;
        nex[i] = 1;
        for(j=0, t=v+i;t<=half&&j<m[p]; j++,t+=v){
            nex[t] = 1; 
        }
    }
}
bool fun(){
    int *pre=tab[0], *cur=tab[1], *tmp;
    int i;

    memset(pre, 0, (half+10)*sizeof(int));
    pre[0] = 1;
    for(i=0; i<3; i++){
        dp(i, pre, cur);
        tmp = pre, pre=cur, cur=tmp;
    }
    memcpy(a, pre, sizeof(int)*(half+10));

    memset(pre, 0, (half+10)*sizeof(int));
    pre[0] = 1;
    for(i=0; i<3; i++){
        dp(i+3, pre, cur);
        tmp = pre, pre=cur, cur=tmp;
    }
    memcpy(b, pre, sizeof(int)*(half+10));
    for(i=0; i<=half; i++){
        if(a[i] && b[half-i]){
            return true;
        }
    }
    return false;
}

int init(){
    int t;
    half = 0;
    for(int i=0; i<6; i++){
        if(m[i] > 10){
            m[i] %= 10;
            m[i] += 10;
        }
        half += m[i] * (i + 1);
    }
    if(half == 0)
        return -1;
    if(half % 2){
        return 0;
    }
    half /= 2;
    return 1;
}
int main(){
    int tstcase = 0;
    int flag;

    while(scanf("%d%d%d%d%d%d", 
                &m[0], &m[1], &m[2], &m[3], &m[4], &m[5]) > 0){
        flag = init();
        if(flag == -1){
            break;
        }
        printf("Collection #%d:\n", ++tstcase);
        if(flag==1 && fun()){
            printf("Can ");
        } else {
            printf("Can't ");
        }
        printf("be divided.\n\n");
    }
    return 0;
}

