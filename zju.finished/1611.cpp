#include<iostream>
using namespace std;
enum {
    SIZ = 5008,
};
struct Node{
    int m, p;
};
int num, sum;
Node tree[100];
int tab[2][SIZ];

int fun(){
    int *pre=tab[0], *cur=tab[1], *tmp;
    int i, j, v;
    memset(pre, -1, sizeof(tab[0]));
    pre[0] = 0;
    for(i=0; i<num; i++){
        memset(cur, -1, sizeof(tab[0]));
        for(j=0; j<sum; j++){
            if(pre[j]<0) continue;
            if(cur[j] < pre[j]){
                cur[j] = pre[j];
            }
            v = j + tree[i].m;
            if(v<=sum && cur[v] < pre[j] + tree[i].p){
                cur[v] = pre[j] + tree[i].p;
            }
        }
        tmp = cur, cur = pre, pre = tmp;
    }
    v = -1, j = -1;
    for(i=0; i<=sum; i++){
        if(pre[i] > v){
            v = pre[i];
            j = i;
        }
    }
    printf("%d %d\n", j, v);
}

int readIn(){
    static char buf[30];
    int n, k, t;
    num = 0;
    scanf("%d%s", &sum, buf);
    scanf("%d", &n);
    while(n--){
        scanf("%s%d ", buf, &k);
        while(k--){
            scanf("%d%s%d%s", &t,buf,&tree[num++].m, buf);
        }
    }
    for(t=0; t<num; t++){
        scanf("%d ", &tree[t].p);
    }
    return 0;
}
int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

