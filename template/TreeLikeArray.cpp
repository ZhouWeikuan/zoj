#include<iostream>
#include<cstring>
using namespace std;
// TLE
enum {
    MARK = 104,
    SIZ = 2004,
};

int N, K, P, M;
int dat[SIZ];

// valid range is [1, SIZ)
// This structure is just like bino-heap
template<typename T>
class TreeLikeArray {
    T sum[MARK];
    int diff(int p){
        return p&(p^(p-1));
    }
  public:
    void init(){
        memset(sum, 0, sizeof(sum));
    }
    void add(int pos, int v){
        while(pos < MARK){
            sum[pos] = (sum[pos] + v) % M;
            pos += diff(pos);
        }
    }
    void sub(int pos, int v){
        while (pos < MARK){
            sum[pos] = (sum[pos] + M - v)%M;
            pos += diff(pos);
        }
    }
    // get sum of range (0, p]
    T sumTo(int p){
        T ans = 0;
        while (p > 0){
            ans += sum[p];
            ans %= M;
            p -= diff(p);
        }
        return ans;
    }
    // get sum of range (s, e]
    T sumRange(int s, int e){
        T ans = sumTo(e);
        ans += M - sumTo(s);
        ans %= M;
        return ans;
    }
};

TreeLikeArray<unsigned> tree[SIZ];

unsigned get(int k, int s, int e){
    return tree[k].sumRange(s, e);
}

void add(int k, int t, int v){
    tree[k].add(t, v);
}

void fun(){        
    unsigned j, v;    
    int s, e, t;
    for(int i=N-1; i>=0; --i){        
        t = dat[i];        
        s = max(0, t-P-1);
        e = min((MARK-1), t+P);
        v = get(K, s, e);  // over the least length
        add(K, t, v);
        for(j=K-1; j>=1; j--){
            v = get(j, s, e);
            add(j+1, t, v);
        }        
        add(1, t, 1);
    }
    v = get(K, 0, MARK-1);
    printf("%d\n", v);
}

int readIn(){
    if(scanf("%d%d%d%d", &N, &K, &P, &M)< 0)
        return 0;
    if(K < 1) K = 1;
    for(int i=0; i<N; i++){
        tree[i].init();
        scanf("%d", &dat[i]);
        ++dat[i];
    }
    tree[N].init();
    return 1;
}

int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

