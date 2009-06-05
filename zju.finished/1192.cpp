#include<iostream>
using namespace std;
enum {
    SIZ = (1<<20),
    PAT = 108,
};
// little head
template<typename Node, typename cmp = less<Node>  >
class Heap {
  public:
      Heap(){}
      void setBase(Node *n){
          b = n;
          pos = 0;
      }
      void push(size_t cur); // 将base中的cur位置元素压入
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

struct Patch {
    unsigned time;
    char req[24];
    char out[24];
};
struct Node {
    unsigned step;
    unsigned ptr;
};
struct Near {
    bool operator()(const Node&a, const Node&b){
        return a.step < b.step;
    }
};
Node rec[SIZ];
Heap<Node, Near> heap;
int bn, pn;
Patch pat[PAT];

bool inline bittest(unsigned v, int p){
    return (v>>p)&0x01;
}
unsigned match(unsigned one, Patch &p){
    bool v;
    for(int i=0; i<bn; i++){
        v = bittest(one, i);
        if( (p.req[i]=='+'&&v==false)||(p.req[i]=='-'&&v==true)){
            return -1;
        }
        if(p.out[i]=='+'){
            one |= (1<<i);
        } else if(p.out[i]=='-'){
            one &= ~(1<<i);
        }
    }
    return one;
}
void fun(){
    int i;
    unsigned cur, nex;
    heap.setBase(rec);
    nex = (1<<bn);
    cur = nex-1;
    memset(rec, -1, sizeof(rec));
    rec[cur].step = 0;
    heap.push(cur);
    while(!heap.empty()){
        cur = heap.top(); heap.pop();
        if(cur == 0){
            break;
        }
        for(i=0; i<pn; i++){
            nex = match(cur, pat[i]);
            if(nex != -1 && rec[nex].step > rec[cur].step + pat[i].time){
                rec[nex].step = rec[cur].step + pat[i].time;
                heap.push(nex);
            }
        }
    }
    if(rec[0].step == -1){
        printf("Bugs cannot be fixed.\n\n");
    } else {
        printf("Fastest sequence takes %d seconds.\n\n", rec[0].step);
    }
}

int readIn(){
    scanf("%d%d", &bn, &pn);
    for(int i=0; i<pn; i++){
        scanf("%d%s%s", &pat[i].time, pat[i].req, pat[i].out);
    }
    return bn+pn;
}
int main(){
    int tst = 1;
    while(readIn() > 0){
        printf("Product %d\n", tst++);
        fun();
    }
    return 0;
}

