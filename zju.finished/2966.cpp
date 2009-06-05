#include<iostream>
#include<algorithm>

using namespace std;
enum {
    SIZ = 508,
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
    int a, b, k;
    bool operator <(const Node&o)const{
        return k < o.k;
    }
};
const int LIM = SIZ*(SIZ-1)/2;
Node cost[LIM];
union_set<SIZ> us;
int N, E;

void fun(){
    int sum = 0;
    for(int i=0; i<E; i++){
        if (!us.same(cost[i].a, cost[i].b)){
            us.connect(cost[i].a, cost[i].b);
            sum += cost[i].k;
        }
    }
    printf("%d\n", sum);
}

void readIn(){
    scanf("%d%d ", &N, &E);
    us.init(N);
    int j=0;
    for(int i=0; i<E; i++){
        scanf("%d%d%d ", &cost[j].a, &cost[j].b, &cost[j].k);
        if (cost[j].k == 0){
            if (!us.same(cost[j].a, cost[j].b)){
                us.connect(cost[j].a, cost[j].b);
            }
        } else {
            ++j;
        }
    }
    E = j;
    sort(cost, cost + E);
}
int main(){
    int tst;
    scanf("%d ", &tst);

    while(tst--){
        readIn();
        fun();
    }

	return 0;
}

