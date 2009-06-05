#include<iostream>

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

int main(){


	return 0;
}
