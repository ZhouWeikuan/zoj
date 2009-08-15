#include<iostream>
#include<vector>
#include<queue>
using namespace std;
enum {
    SIZ = 1000004,
};
struct Node {
    int a, b;
};
struct a_cmp{
    bool operator ()(const Node&l, const Node&r)const{
        return l.a > r.a;
    }
};
struct b_cmp{
    bool operator ()(const Node&l, const Node&r)const{
        return l.b < r.b;
    }
};

int n, m, p;

int fun(){
    if (scanf("%d%d%d", &n, &m, &p) < 0)
        return 0;
    priority_queue<Node, vector<Node>, a_cmp> qa;
    priority_queue<Node, vector<Node>, b_cmp> qb;
    Node o;
    int i;
    for (i=0; i<n; ++i){
        scanf("%d%d", &o.a, &o.b);
        qa.push(o);
    }
    while(m--){
        while(!qa.empty() && qa.top().a <= p){
            o = qa.top(); qa.pop();
            qb.push(o);
        }
        if (qb.empty()){
            break;
        } else {
            o = qb.top(); qb.pop();
            p += o.b;
        }
    }

    printf("%d\n", p);

    return 1;
}

int main(){

    while(fun() > 0){
        ;
    }

    return 0;
}

