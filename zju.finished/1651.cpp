#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
// TLE
enum {
    LEN = 15,
};
struct Node {
    unsigned f, d, p;
};
int num;
unsigned dead[LEN];
unsigned proc[LEN];
bool use[1<<LEN];
Node tree[1<<LEN];

void trace(unsigned s){
    vector<int> v;
    while(tree[s].p != -1){
        v.push_back(tree[s].p + 1);
        s &= ~(1<<tree[s].p);
    }
    printf("%d", v.back());
    v.pop_back();
    for (int i=v.size()-1; i>=0; --i){
        printf(" %d", v[i]);
    }
    printf("\n");
}

void fun(){
    memset(tree, -1, sizeof(tree));
    memset(use, false, sizeof(use));
    unsigned cur = 0, nex;
    tree[cur].f = 0, tree[cur].d = 0, tree[cur].p = -1;
    queue<unsigned> q;
    q.push(cur);
    use[cur] = true;
    while(!q.empty()){
        cur = q.front(); q.pop();
        use[cur] = false;
        for (int i=0; i<num; ++i){
            if (cur & (1<<i)) continue;
            nex = cur | (1<<i);
            unsigned d = tree[cur].f + proc[i];
            if (d <= dead[i]){
                d = 0;
            } else {
                d -= dead[i];
            }
            d += tree[cur].d;
            if (d < tree[nex].d){
                tree[nex].f = tree[cur].f + proc[i];
                tree[nex].d = d;
                tree[nex].p = i;
                if (!use[nex]){
                    use[nex] = true;
                    q.push(nex);
                }
            }
        }
    }
    cur = (1<<num) - 1;
    printf("%u\n", tree[cur].d);
    trace(cur);
}

int readIn(){
    if(scanf("%d",&num)<0)
        return 0;
    for(int i=0; i<num; i++){
        scanf("%d%d", &proc[i], &dead[i]);
    }
    return 1;
}

int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

