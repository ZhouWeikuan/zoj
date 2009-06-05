#include<iostream>
using namespace std;
// Chordal Graph
enum {
    SIZ = 1008,
};

// little head
template<typename Node, typename cmp = less<Node>  >
class Heap {
  public:
      Heap():b(0), pos(0){}
      void set(Node *n){b = n, pos=0;}
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

struct Node {
    int ptr, cnt, lab;
    int n;
    int e[SIZ];
};
struct Near {
    bool operator()(const Node&a, const Node&b){
        return a.cnt > b.cnt;
    }
};

int num, edge;
int chk[SIZ];
Node tree[SIZ];
Heap<Node, Near> h;
bool mat[SIZ][SIZ];

int fun(){
    int i, cur, j, t;
    for(i=num-1; i>=0; --i){
        cur = h.top(); h.pop();
        tree[cur].lab = i;
        chk[i] = cur;
        for(j=0; j<tree[cur].n; ++j){
            t = tree[cur].e[j];
            if(tree[t].lab >=0 ) continue;
            tree[t].cnt++;
            h.push(t);
        }
    }
    for(i=0; i<num ;i++){
        for(j=i+1;j<num&&mat[chk[i]][chk[j]] == false;j++)
            ;
        for(cur=j+1; cur<num; cur++){
            if(mat[chk[i]][chk[cur]] && !mat[chk[j]][chk[cur]])
                return 0;
        }
    }
    return 1;
}

int readIn(){
    if(scanf("%d%d",&num,&edge)<0)
        return 0;
    h.set(tree);
    memset(mat, false, sizeof(mat));
    for(int i=0; i<num; i++){
        tree[i].n = 0;
        tree[i].ptr = -1;
        tree[i].cnt = 0;
        tree[i].lab = -1;
        h.push(i);
    }
    int a, b;
    for(int i=0; i<edge; i++){
        scanf("%d%d",&a,&b);
        --a, --b;
        tree[a].e[tree[a].n++] = b;
        tree[b].e[tree[b].n++] = a;
        mat[a][b] = mat[b][a] = true;
    }
    return num+edge;
}
int main(){
    const char *ans[2] = {"Imperfect","Perfect"};
    while(readIn()>0){
        printf("%s\n\n", ans[fun()]);
    }
    return 0;
}
