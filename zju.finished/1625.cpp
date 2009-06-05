#include<iostream>
// Wrong Answer
using namespace std;
enum {
    LEN = 20,
    SIZ = 1<<LEN,
};
unsigned long long T;
int N, val;
unsigned dis[SIZ];
int tab[2][LEN];

void conv(unsigned v, int *p){
    int i;
    for(i=N-1; i>=0; i--){
        p[i] = v % 2;
        v /= 2;
    }
}
void output(int *p) {
    printf("%d", p[0]);
    for(int i=1; i<N; i++){
        printf(" %d", p[i]);
    }
    printf("\n");
}
inline unsigned getNeibour(int t, int *p){
    return p[(t+N-2)%N] + p[(t+N-1)%N] + p[(t+1)%N] + p[(t+2)%N];
}
void fun(){
    int *pre, *cur, *tmp;
    unsigned i,j,t;
    pre = tab[0], cur = tab[1];
    for(i=0;dis[val]==-1 && i < T; i++){
        dis[val] = i;
        // printf("%d %d\n", val, i);
        val = 0;
        for(j=0; j<N; j++){
            t = getNeibour(j, pre);
            cur[j] = pre[j];
            if(cur[j] && (t<=1||t==3)){
                cur[j] = 0;
            } else if(!cur[j] && (t==2||t==3)){
                cur[j] = 1;
            }
            val *= 2;
            val += cur[j];
        }
        tmp = pre, pre = cur, cur = tmp;
    }
    // printf("%d %d\n", val, i);
    if(i == T){
        output(pre);
        return;
    }
    T -= dis[val];
    j = i - dis[val];
    j = T % j;
    j += dis[val];
    for(i=0; dis[i]!=j; i++)
        ;
    conv(i, pre);
    output(pre);
}
int readIn(){
    if(scanf("%d%llu", &N, &T)< 0)
        return 0;
    val = 0;
    for(int i=0; i<N; i++) {
        scanf("%d", &tab[0][i]);
        val *= 2;
        val += tab[0][i];
    }
    memset(dis, -1, sizeof(dis));
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

