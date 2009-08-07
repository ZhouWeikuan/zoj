#include<iostream>
#include<vector>
#include<queue>
using namespace std;
enum {
    SIZ = 1004,
};

int N, M, Y;

struct Node {
    int X, K;
    double unfair;
    void calc(){
        double cur = X*M - K*Y;
        double nex = X*M - K*Y - Y;
        cur /= Y; cur /= M;
        nex /= Y; nex /= M;
        if (cur < 0) cur = -cur;
        if (nex < 0) nex = -nex;
        unfair = nex - cur;
    }
    bool operator <(const Node&o)const{
        return unfair < o.unfair;
    }
};
Node tree[SIZ];
struct cmp{
    bool operator()(const int a, const int b) const {
        return !(tree[a] < tree[b]);
    }
};

void fun(){
    int rem = M % Y;
    if (rem == 0) return;
    int i;
    priority_queue<int, vector<int>, cmp> q;
    for (i=0; i<N; ++i){
        q.push(i);
    }
    while(rem-- > 0){
        i = q.top(); q.pop();
        ++tree[i].K;
        tree[i].calc();
        q.push(i);
    }
}

void readIn(){
    scanf("%d%d%d",&N,&M,&Y);
    int u = M / Y;
    for (int i=0; i<N; ++i){
        scanf("%d",&tree[i].X);
        tree[i].K = u*tree[i].X;
        tree[i].calc();
    }
}

void output(){
    printf("%d", tree[0].K);
    for (int i=1; i<N; ++i){
        printf(" %d", tree[i].K);
    }
    printf("\n");
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
        output();
    }

    return 0;
}

