#include<iostream>
#include<algorithm>
using namespace std;
enum {
    SIZ = 5004,
};

struct Node {
    int a, b;
    bool operator<(const Node&o)const{
        if (a!=o.a)
            return a < o.a;
        return b > o.b;
    }
};

int N;
Node tree[SIZ];

void fun(){
    int ans = 0, cur = 0, page = 0, npage = 0;
    while(cur < N && npage < N){
        if (tree[cur].a <= page){
            npage = max(npage, tree[cur].b);
            ++cur;
        } else {
            ++ans;
            page = npage + 1;
        }
    }
    printf("%d\n", ans);
}

void readIn(){
    scanf("%d", &N);
    for (int i=0; i<N; ++i){
        scanf("%d%d", &tree[i].a, &tree[i].b);
    }
    sort(tree, tree + N);
}

int main(){
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        fun();
    }

    return 0;
}

