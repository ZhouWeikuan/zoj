#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
};

// little head
template<typename Node, typename cmp = less<Node>  >
class Heap {
  public:
      Heap(){}
      void set(Node *n){b=n,pos=0;}
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
    if(--pos==0)
        return;
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

struct Node{
    unsigned cnt, dis;
    int ptr;
    bool operator<(const Node &r)const{
        return dis < r.dis;
    }
};
Heap<Node> h;
int num, pn;
Node tree[SIZ];
unsigned mat[SIZ][SIZ];

void rank(){
    int cur, i;
    unsigned v;
    tree[2].cnt = 1;
    tree[2].dis = 0;
    h.set(tree);
    h.push(2);
    while(!h.empty()){
        cur = h.top(); h.pop();
        for(i=1; i<=num; i++){
            if(mat[cur][i] == 0 || tree[i].dis <= tree[cur].dis) continue;
            v = tree[cur].dis + mat[cur][i];
            if(tree[i].dis > v){
                tree[i].dis = v;
                h.push(i);
            }
            tree[i].cnt += tree[cur].cnt;
        }
    }
}
void fun(){
    rank();
    printf("%u\n", tree[1].cnt);
}
int readIn(){
    scanf("%d",&num);
    if(num == 0) return 0;
    scanf("%d",&pn);
    memset(mat, 0, sizeof(mat));
    int a, b, d,i;
    for(i=0; i<pn; i++){
        scanf("%d%d%d",&a,&b,&d);
        mat[a][b] = mat[b][a] = d;
    }
    for(i=1; i<=num; i++){
        tree[i].cnt = 0;
        tree[i].dis = -1;
        tree[i].ptr = -1;
    }
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

