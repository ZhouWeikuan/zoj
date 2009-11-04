#include<cstdio>

//«Û¡Ω¥Œdijkstra 
using namespace std;
enum {
    SIZ = 1000004,
    MaxN = 999999999,
};

struct Node {
    int ptr;
    int val;
    Node *link;
};
Node tree[SIZ * 2];
Node in[SIZ];
Node out[SIZ];
int num;
int ptr[SIZ];
int top, next;
Node *cur = NULL;
void shift_down(int );
void shift_up(int);
void push(int t){
    ptr[top] = t;
    cur[t].ptr = top;
    shift_up(top++);
}
int pop(){
    int ret = ptr[0],t;
    cur[ret].ptr = -1;
    --top;
    if(top){
        t = ptr[top];
        ptr[0] = t;
        cur[t].ptr = 0;
        shift_down(0);
    }
    return ret;
}
void update(int t){ // parameter:  cur[x].ptr;
    shift_up(cur[t].ptr);
}
void shift_up(int s){
    int p,t;
    while(s){
        p = s/2;
        if(cur[ptr[p]].val <= cur[ptr[s]].val)
            break;
        t = ptr[p]; ptr[p] = ptr[s]; ptr[s] = t;
        cur[ptr[p]].ptr = p; cur[ptr[s]].ptr = s;
        s = p;
    }
}
void shift_down(int p){
    int s, t;
    s = 2 * p + 1;
    while(s < top){
        if(s+1 < top && cur[ptr[s]].val > cur[ptr[s+1]].val){
            s ++;
        }
        if(cur[ptr[p]].val <= cur[ptr[s]].val)
            break;
        t = ptr[p]; ptr[p] = ptr[s]; ptr[s] = t;
        cur[ptr[p]].ptr = p; cur[ptr[s]].ptr = s;
        p = s;
        s = 2 *p + 1;
    }
}

void readIn(){
    int q, a,b,v;
    scanf("%d%d", &num, &q);
    for(a=1;a<=num;a++){
        in[a].val = out[a].val = MaxN;
        in[a].link = out[a].link = 0;
        in[a].ptr = out[a].ptr = -1;
    }
    next = 0;
    while(q--){
        scanf("%d%d%d", &a,&b,&v);
        tree[next].ptr = b; tree[next].val = v; 
        tree[next].link = out[a].link; out[a].link = &tree[next];
        next ++;
        
        tree[next].ptr = a; tree[next].val = v;
        tree[next].link = in[b].link; in[b].link = &tree[next];
        next++;
    }
}
void compute_in(){
    int one, a;
    Node *t;
    in[1].val = 0;
    cur = in;
    top = 0;
    push(1);
    while(top > 0){
        one = pop();
        for(t = in[one].link; t!=0; t=t->link){
            if(in[one].val + t->val >= in[t->ptr].val)
                continue;
            in[t->ptr].val = in[one].val + t->val;
            if(in[t->ptr].ptr == -1){
                push(t->ptr);
            } else {
                update(t->ptr);
            }
        }
    }
}

void compute_out(){
    int one, a;
    Node *t;
    out[1].val = 0;
    cur = out;
    top = 0;
    push(1);
    while(top > 0){
        one = pop();
        for(t = out[one].link; t!=0; t=t->link){
            if(out[one].val + t->val >= out[t->ptr].val)
                continue;
            out[t->ptr].val = out[one].val + t->val;
            if(out[t->ptr].ptr == -1){
                push(t->ptr);
            } else {
                update(t->ptr);
            }
        }
    }

}

int fun(){
    compute_in();
    compute_out();
    int ret = 0;
    for(int i=1;i<=num;i++){
        ret += in[i].val;
        ret += out[i].val;
    }
    return ret;
}

int main(){
    int tstcase;
    scanf("%d ", &tstcase);
    while(tstcase --){
        readIn();
        printf("%d\n", fun());
    }

	return 0;
}
