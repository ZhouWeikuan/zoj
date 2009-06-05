#include<iostream>
#include<algorithm>

using namespace std;
enum {
    SIZ = 508,
    MaxN = 99999999,
};
// little head
template<typename Node, typename cmp = less<Node>  >
class Heap {
  public:
      Heap(Node *n):b(n), pos(0){}
      void push(size_t cur);
      void pop();
      size_t  top();
      bool empty(){
          return pos<=0;
      }
  private:
      void update(size_t );
      Heap(const Heap& );
      Heap& operator=(const Heap& );

      Node *b;
      cmp  c;
      size_t pos;
      size_t h[SIZ];
};
template<typename Node, typename cmp>
void Heap<Node, cmp>::push(size_t cur){
    if(b[cur].ptr != -1){
        update(b[cur].ptr);
        return ;
    }
    b[cur].ptr = pos;
    h[pos++] = cur;
    update(pos-1);
}
template<typename Node, typename cmp>
void Heap<Node, cmp>::pop(){
    if( pos <=0)
        return;
    b[h[0]].ptr = -1;
    pos --;
    h[0] = h[pos]; b[h[0]].ptr = 0;
    int r = 0, p = (r+1)*2-1;
    while(p < pos){
        if(p+1 < pos && c(b[h[p+1]], b[h[p]])){
            p ++;
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
size_t Heap<Node, cmp>::top(){
    return h[0];
}
template<typename Node, typename cmp>
void Heap<Node, cmp>::update(size_t p){
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
    int ptr, dis, n;
    int no[SIZ];
    int val[SIZ];
};
struct Near {
    bool operator()(const Node&a, const Node&b){
        return a.dis< b.dis;
    }
};
Node tree[SIZ];
int tmp[SIZ];
int N,M;

inline double calc(int a, int b, int d){
    double ans;
    if(a < b){
        ans = b;
        d -= (b-a);
    } else {
        ans = a;
        d -= (a-b);
    }
    if(d > 0){
        ans += static_cast<double>(d)/2;
    }
    return ans;
}

void fun(){
    double ans = 0.0;
    int a,b,v,d;
    unsigned key = -1;
    tree[0].dis = 0;
    Heap<Node, Near> q(tree);
    q.push(0);
    while(!q.empty()){
        a = q.top(); q.pop();
        for(int i=0;i<tree[a].n;i++){
            b = tree[a].no[i];
            v = tree[a].val[i];
            d = tree[a].dis + v;
            if(d < tree[b].dis){
                tree[b].dis = d;
                q.push(b);
            }
        }
    }
    int t = 0;
    d = 0;
    for(int i=0; i<N;i++){
        if(tree[i].dis > d){
            d = tree[i].dis;
            t = 0;
            tmp[t++] = i;
            key = (-1<<16) + i;
        } else if(tree[i].dis == d){
            tmp[t++] = i;
        }
    }
    ans = d;
    while(t -- >= 0){
        a = tmp[t];
        for(int i=0;i<tree[a].n; i++){
            b = tree[a].no[i];
            v = tree[a].val[i];
            double meet = calc(tree[a].dis, tree[b].dis, v);
            if(meet > ans){
                ans = meet;
                key = (a<<16) + b;
            }
        }
    }
    a = (key>>16)&0x0ffff;
    b = (key)&0x0ffff;
    printf("The last domino falls after %.1lf seconds, ", ans);
    if(a > SIZ){
        if(b > SIZ){
            printf("at key domino 1.\n");
        } else {
            b ++;
            printf("at key domino %d.\n", b);
        }
    } else {
        a++,b++;
        if(a > b){
            int t = a; a= b; b= t;
        }
        printf("between key dominoes %d and %d.\n", a,b);
    }
}

void readIn(){
    int i,a,b,v;
    for(i=0;i<N;i++){
        tree[i].ptr = -1; tree[i].dis = MaxN; tree[i].n = 0;
    }
    for(i=0; i<M; i++){
        scanf("%d%d%d ", &a, &b, &v);
        a --, b --;
        tree[a].no[tree[a].n] = b;
        tree[a].val[tree[a].n] = v;
        tree[a].n ++;
        tree[b].no[tree[b].n] = a;
        tree[b].val[tree[b].n] = v;
        tree[b].n ++;
    }
}

int main(){
    int tstcase = 0;
    scanf("%d%d", &N, &M);
    while(N + M){
        tstcase ++;
        readIn();
        printf("System #%d\n", tstcase);
        fun();
        printf("\n");
        scanf("%d%d", &N, &M);
    }

    return 0;
}
