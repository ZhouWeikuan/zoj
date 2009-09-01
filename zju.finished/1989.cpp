#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
enum {
    SIZ = 30004,
};

struct Node {
    int no, sal, hei;
    bool operator <(const Node&o) const {
        return sal < o.sal;
    }
};

int N, M;
Node tree[SIZ];
int par[SIZ];
int sub[SIZ];
map<int, int> noTab;
map<int, int>::iterator it;

struct cmp {
    bool operator ()(const int&a, const int&b)const{
        return tree[a].hei >= tree[b].hei;
    }
};

void solve(){
    int no;
    while(M--){
        scanf("%d", &no);
        it = noTab.find(no);
        if (it==noTab.end()){
            printf("-1 -1\n");
        } else {
            no = it->second;
            printf("%d %d\n", par[no]<0?0:tree[par[no]].no, sub[no]);
        }
    }
}

void fun(){
    priority_queue<int, vector<int>, cmp> q;
    for (int i=0; i<N; ++i){
        sub[i] = 0;
        par[i] = -1;
        while(!q.empty()){
            int s = q.top();
            if (tree[s].hei <= tree[i].hei){
                par[s] = i;
                q.pop();
            } else {
                break;
            }
        }
        q.push(i);
    }
    for (int i=0; i<N; ++i){
        if (par[i] == -1) continue;
        sub[par[i]] += sub[i] + 1;
    }
    solve();
}

void readIn(){
    scanf("%d%d",&N,&M);
    for (int i=0; i<N; ++i){
        scanf("%d%d%d", &tree[i].no, &tree[i].sal, &tree[i].hei);
        par[i] = sub[i] = -1;
    }
    sort(tree, tree+N);
    noTab.clear(); 
    for (int i=0; i<N; ++i){
        noTab.insert(make_pair(tree[i].no, i));
    }
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

