#include<iostream>
using namespace std;
enum {
    SIZ = 504,
};
struct Node {
    int pos;
    int dat[SIZ];
};
Node tab[2];
int N, M, K;
int sum[SIZ], low, high;

void fun(){
    Node *pre = tab, *cur=&tab[1], *tmp;
    int i, p, t, v;
    pre->pos = 0, pre->dat[pre->pos++] = 0;
    for(i=1;i<=N && pre->pos>0;i++){
        cur->pos = 0;
        p = pre->dat[0];
        for(t=0; t<pre->pos; t++){
            v = pre->dat[t];
            while(p<=M && sum[p]-sum[v] < low){
                p++;
            }
            while(p<=M && sum[p]-sum[v] <= high){
                cur->dat[cur->pos++]  = p++;
            }
        }
        tmp = cur, cur = pre, pre = tmp;
    }
    if((i > N && pre->pos > 0 && pre->dat[pre->pos-1] == M)){
        printf("possible\n");
    } else {
        printf("impossible\n");
    }
}

void readIn(){
    int t, i;
    sum[0] = 0;
    for(i=1; i<=M; i++){
        scanf("%d", &t);
        sum[i] = sum[i-1] + t;
    }
    double v = sum[M];
    v /= N;
    high = (int)(v) + K;
    low = (int)v;
    if(v - low > 0.0001){
        low++;
    }
    low -= K;
    if(low < 0) low = 0;
}

int main(){

    while(scanf("%d%d%d", &N, &M, &K) > 0){
        readIn();
        fun();
    }
    return 0;
}

