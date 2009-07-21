#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 2008,
    LEN = 8,
};

template<int N>
class union_set {
    int par[N];
    int num;
  public:
    void init(int n);
    int getPar(int a);
    bool same(int a, int b);
    void connect(int a, int b);
};

template<int N>
void union_set<N>::init(int n){
    num = n;
    for(int i=0;i<num;i++){
        par[i] = i;
    }
}

template<int N>
int union_set<N>::getPar(int a){
    int p = par[a];
    while(p != par[p]){
        p = par[p];
    }
    return par[a] = p;
}

template<int N>
bool union_set<N>::same(int a, int b){
    a = getPar(a); b = getPar(b);
    return (a == b);
}

template<int N>
void union_set<N>::connect(int a, int b){
    a = getPar(a); b = getPar(b);
    if(a < b){
        par[b] = a;
    } else if(a > b){
        par[a] = b;
    } 
}

struct Node {
    char d;
    short a, b;
    bool operator <(const Node&o) const {
        return d >= o.d;
    }
};

char truck[SIZ][LEN];
bool use[SIZ];
int num;
union_set<SIZ> us;

int getDis(int a, int b){
    int r = 0;
    for (int i=0; truck[a][i]; ++i){
        r += (truck[a][i]!=truck[b][i]);
    }
    return r;
}

int fun(){
    int i,j;
    Node o;
    priority_queue<Node> q;
    us.init(num + 4);

    for (i=0; i<num; ++i){
        scanf("%s ", truck[i]);
        for (j=0; j<i; ++j){
            o.d = getDis(i, j);
            o.a = i; o.b = j;
            q.push(o);
        }
    }
    int l = num - 1;
    int r = 0;
    while(l){
        o = q.top(); q.pop();
        if (!us.same(o.a, o.b)){
            r += o.d;
            us.connect(o.a, o.b);
            --l;
        }
    }

    return r;
}

int main(){
    scanf("%d ", &num);
    while(num){
        int t = fun();
        printf("The highest possible quality is 1/%d.\n", t);
        scanf("%d ", &num);
    }
    return 0;
}

