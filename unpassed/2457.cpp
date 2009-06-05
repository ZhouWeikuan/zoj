#include<iostream>
using namespace std;
//Wrong Answer
enum {
    SIZ = 1008,
};
struct Node{
    int val;
    Node *link;
};
int N, M;
int pre[SIZ];
int use[SIZ];
int tmp[SIZ];
Node *cnt[SIZ];
Node tree[SIZ*10];

void fun(){
    int i,j,nex;
    Node *p;
    for(i=0; i<M; i++){
        if(cnt[i] == 0) continue;
        for(j=0;j<M; j++){
            if(pre[j] == -1) continue;
            if(tree[use[j]-1].link != 0
                && tree[use[j]-1].val%M == i) continue;
            p = cnt[i];
            nex = (j * p->val)%M;
            while(pre[nex] == -1){
                pre[nex] = j;
                use[nex] = p - tree + 1;
                p = p->link;
                if(!p )break;
                nex = (j * p->val)%M;
            }
        }
    }
    for(i=M-1; i>=1&&pre[i]==-1; i--) 
        ;
    if(i < 1){
        printf("1\n");
        return;
    }
    printf("%d\n", i);

    N = 0;
    while(i!=0){
        tmp[N++] = use[i];
        i = pre[i];
    }
    sort(tmp, tmp+N);
    for(i=0; i<N; i++){
        printf("%s%d", i?" ":"", tmp[i]);
    }
    if(N)
        printf("\n");
}

int readIn(){
    if(scanf("%d%d",&N,&M)<0)
        return 0;
    memset(pre, -1, sizeof(pre));
    memset(use, -1, sizeof(use));
    memset(cnt, 0, sizeof(cnt));
    int i,t;
    for(i=0; i<N; i++){
        scanf("%d", &tree[i].val);
        t = tree[i].val % M;
        if(use[t] == -1){
            use[t] = i + 1;
            pre[t] = 0;
        } else {
            tree[i].link = cnt[t];
            cnt[t] = &tree[i];
        }
    }

    return 1;
}

int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

