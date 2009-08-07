#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 100004,
};

struct Node {
    unsigned x, p, m;
    bool operator< (const Node&o)const {
        return p < o.p;
    }
    void read(){
        scanf("%u%u%u", &x, &p, &m);
    }
};
int N;
Node d[SIZ];
unsigned ans;

void fun(){
    priority_queue<Node, vector<Node> > q;
    Node o;
    unsigned t;
    for (int i=N-1; i>=0; --i){
        q.push(d[i]);
        while(d[i].x > 0 && !q.empty() ){
            o = q.top(); q.pop();
            t = min(d[i].x, o.m);
            ans += t * o.p;
            d[i].x -= t;
            o.m -= t;
            if (o.m)
                q.push(o);
        }
    }
    printf("%u\n", ans);
}

void readIn(){
    ans = 0;
    scanf("%d", &N);
    unsigned t;
    for (int i=0; i<N; ++i){
        d[i].read();
    }
}

int main(){
    int tst;
    scanf("%d",&tst);
    while (tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

