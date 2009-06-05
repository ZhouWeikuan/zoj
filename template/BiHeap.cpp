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
      Heap(){}
      void set(Node *n){b=n, pos=0;}
      void push(size_t cur); // 在b中的位置
      void pop();
      size_t  top();
      bool empty(){
          return pos<=0;
      }
      void erase(size_t p); // 在b中的位置
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
void Heap<Node, cmp>::erase(size_t p){ // 在b中的位置
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
    int dis;
    int n;
    int no[SIZ];
    int val[SIZ];
};
struct Near {
    bool operator()(const Node&a, const Node&b){
        return a.dis< b.dis;
    }
};
