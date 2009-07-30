#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
enum {
    SIZ = 101*100*10,
    MaxN = 99999999,
};
// little head
template<typename Node, typename cmp = less<Node>  >
class Heap {
  public:
      Heap(){}
      void set(Node *n){b=n, pos=0;}
      void push(size_t cur); // position in b
      void pop();
      size_t  top();
      bool empty(){
          return pos<=0;
      }
      void erase(size_t p); // position in b
  private:
      void shift_down(size_t );
      void shift_up(size_t);
      Heap(const Heap& );
      Heap& operator=(const Heap& );

      Node *b;
      cmp  c;
      size_t pos;
      size_t h[SIZ];
};
template<typename Node, typename cmp>
void Heap<Node, cmp>::erase(size_t p){ // position in b
    if(b[p].ptr == -1) return;
    p = b[p].ptr;
    b[h[p]].ptr = -1;
    --pos;
    if(p >= pos) return;
    h[p] = h[pos];
    b[h[p]].ptr = p;
    shift_down(p);
}
template<typename Node, typename cmp>
void Heap<Node, cmp>::push(size_t cur){
    if(b[cur].ptr != -1){
        shift_up(b[cur].ptr);
        shift_down(b[cur].ptr);
        return ;
    }
    //printf("in %d\n", cur);
    b[cur].ptr = pos;
    h[pos] = cur;
    shift_up(pos++);
}
template<typename Node, typename cmp>
void Heap<Node, cmp>::shift_down(size_t r){
    size_t p=(r+1)*2-1;
    while(p < pos){
        if(p+1 < pos && c(b[h[p+1]], b[h[p]])){
            ++p;
        }
        if( c(b[h[r]], b[h[p]])){
            break;
        }
        int t = h[r]; h[r] = h[p]; h[p] = t;
        b[h[r]].ptr = r;   b[h[p]].ptr = p;
        r = p;
        p = (r+1)*2 -1;
    }

}

template<typename Node, typename cmp>
void Heap<Node, cmp>::pop(){
    if( pos <=0)
        return;
    //printf("out %d\n", h[0]);
    b[h[0]].ptr = -1;
    if(--pos==0)
        return;
    h[0] = h[pos]; b[h[0]].ptr = 0;
    shift_down(0);
}
template<typename Node, typename cmp>
size_t Heap<Node, cmp>::top(){
    return h[0];
}
template<typename Node, typename cmp>
void Heap<Node, cmp>::shift_up(size_t p){
    size_t r ;
    while(p > 0){
        r = (p-1)/2;
        if( c(b[h[r]], b[h[p]])){
            break;
        }
        int t= h[r];  h[r] = h[p];   h[p] = t;
        b[h[r]].ptr = r;   b[h[p]].ptr = p;
        p = r;
    }
}

struct Node {
    int ptr;
    unsigned lag;
};
struct Near {
    bool operator()(const Node&a, const Node&b){
        return a.lag< b.lag;
    }
};

int N, M, Z;
int cham[10][100];
int mag[10][10];
Node tree[101*100*10];
Heap<Node, Near> hp;

int makePos(int z, int n, int m){
    return z*N*M + n*M + m;
}

void parsePos(int p, int &z, int &n, int &m){
    z = p/(N*M);
    p %=M*N;
    n = p/M;
    p %= M;
    m = p;
}

void fun(){
    memset(tree, -1, sizeof(tree[0])*(Z+1)*M*N);
    hp.set(tree);
    int z=Z, cas=0, chm=0;
    int p = makePos(z, chm, cas);
    int np;
    tree[p].lag = 0;
    hp.push(p);
    while(!hp.empty()){
        p = hp.top(); hp.pop();
        parsePos(p, z, chm, cas);
        if (chm >= N - 1){
            printf("%d\n", tree[p].lag);
            return ;
        }
        // shift to other castle
        for (int c=0; c<M; ++c){
            if (c==cas||mag[cas][c]>z) continue;
            np = makePos(z-mag[cas][c], chm, c);
            if (tree[np].lag > tree[p].lag){
                tree[np].lag = tree[p].lag;
                hp.push(np);
            }
        }
        // upgrade to next chamber
        np = makePos(z, chm+1, cas);
        if (tree[np].lag > tree[p].lag+cham[cas][chm]){
            tree[np].lag = tree[p].lag+cham[cas][chm];
            hp.push(np);
        }
    }
    printf("-1\n");
}

void readIn(){
    scanf("%d%d%d", &N, &M, &Z);
    for (int cas=0; cas<M; ++cas){
        for (int chm=0; chm<N-1; ++chm){
            scanf("%d", &cham[cas][chm]);
        }
    }
    for (int i=0; i<M; ++i){
        for (int j=0; j<M; ++j){
            scanf("%d", &mag[i][j]);
        }
    }
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0;
}

