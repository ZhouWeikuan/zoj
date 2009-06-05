#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 10008,
};

struct Node {
    int val;
    int lim;
    bool operator<(const Node&rhs) const{
        if(lim != rhs.lim)
            return lim < rhs.lim;
        return val > rhs.val;
    }
};

Node tree[SIZ];
int num;

struct Cmp {
    bool operator()(const int &l,  const int &r) const {
        return tree[r].val < tree[l].val;
    }
};

int readIn(){
    if(scanf("%d", &num) <= 0)
        return 0;
    for(int i=0;i<num;i++){
        scanf("%d%d", &tree[i].val, &tree[i].lim);
    }
    sort(tree, tree+num);
    return 1;
}

int fun(){
    priority_queue<int, vector<int>, Cmp> q;
    int sum = 0;
    int t;
    for(int i=0;i< num;i++){
        if(q.size() < tree[i].lim){// push
            q.push(i);
            sum += tree[i].val;
        } else {// replace
            t = q.top();
            if(tree[t].val < tree[i].val){
                q.pop();
                q.push(i);
                sum -= tree[t].val;
                sum += tree[i].val;
            }
        }
    }

    return sum;
}

int main(){

    while(readIn() > 0){
        printf("%d\n", fun());
    }

    return 0;
}

