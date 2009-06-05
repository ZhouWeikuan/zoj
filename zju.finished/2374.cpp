#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 10008,
};
struct Node {
    int p;// parent index;
    int n; // unprocessed child num;
    int cnt; // total marble available;
};
Node tree[SIZ];
int val = 0, num;

void readIn(queue<int> &q){
    tree[0].p = 0; tree[0].n = num; tree[0].cnt = 0;
    tree[1].p = 0;
    int i, n, cnt, d, t;
    for(i=1;i<=num;i++){
        scanf("%d%d%d",&n,&cnt,&d);
        tree[n].cnt = cnt;
        tree[n].n = d;
        if(d==0)
            q.push(n);
        while(d--){
            scanf("%d",&t);
            tree[t].p = n;
        }
    }
}

int fun(){
    queue<int> q;
    readIn(q);
    int cur, p;
    val = 0;
    while(!q.empty()){
        cur = q.front(); q.pop();
        p = tree[cur].p;
        tree[cur].cnt --;
        if(tree[cur].cnt != 0){
            tree[p].cnt += tree[cur].cnt;
            if(tree[cur].cnt > 0){
                val += tree[cur].cnt;
            } else {
                val -= tree[cur].cnt;
            }
        }
        if(--tree[p].n==0){
            q.push(p);
        }
    }
    return val;
}

int main(){
    scanf("%d",&num);
    while(num){
        cout<<fun()<<endl;
        scanf("%d",&num);
    }

    return 0;
}
