#include<iostream>
using namespace std;
enum {
    SIZ = 72,
};
struct Node {
    int val;
    int len;
    Node *next;
};
Node tree[SIZ][SIZ];
int W,H;

void readIn(){
    char ch;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf(" %c",&ch);
            if(ch>='0' && ch<='9'){
                tree[i][j].val = ch - '0';
            } else {
                tree[i][j].val = -1;
            }
            tree[i][j].len = 0;
            tree[i][j].next = 0;
        }
    }
}
int cmp_tail(Node *l, Node *r){
    if(l==0)
        return -1;
    if(r==0)
        return 1;
    if(l->len != r->len)
        return l->len - r->len;
    while(l&&r&&l->val ==r->val){
        l = l->next;
        r = r->next;
    }
    if(l==0&&r==0)
        return 0;
    return l->val - r->val;
}
int cmp(Node *l, Node *r){
    if(l==NULL)
        return -1;
    else if(r==NULL)
        return 1;
    while(l && l->val ==0)
        l = l->next;
    while(r && r->val ==0)
        r = r->next;
    if(l==0 && r == 0)
        return 0;
    else if(l==0)
        return -1;
    else if(r==0)
        return 1;
    else {
        if(l->len != r->len)
            return l->len - r->len;
        while(l && r && l->val == r->val){
            l = l->next;
            r = r->next;
        }
        if(l==0&&r==0)
            return 0;
        else {
            return l->val - r->val;
        }
    }
}
void print(Node *p){
    while(p){
        printf("%d",p->val);
        p = p->next;
    }
}
void fun(){
    Node *best = NULL;
    for(int i=H-1;i>=0;i--){
        for(int j=W-1;j>=0;j--){
            if(tree[i][j].val < 0)
                continue;
            if(i<H-1&&tree[i+1][j].val >=0){
                if(j<W-1&&tree[i][j+1].val>=0 
                        && cmp_tail(&tree[i+1][j], &tree[i][j+1]) < 0){
                    tree[i][j].len = tree[i][j+1].len + 1;
                    tree[i][j].next = &tree[i][j+1];
                } else {
                    tree[i][j].len = tree[i+1][j].len + 1;
                    tree[i][j].next = &tree[i+1][j];
                }
            } else if(j<W-1&&tree[i][j+1].val >=0){
                tree[i][j].len = tree[i][j+1].len + 1;
                tree[i][j].next = &tree[i][j+1];
            } else {
                tree[i][j].len = 1;
            }
            if(cmp(best, &tree[i][j]) < 0){
                best = &tree[i][j];
            }
        }
    }
    print(best);
    printf("\n");
}
int main(){
    scanf("%d%d",&W,&H);
    while(W+H){
        readIn();
        fun();
        scanf("%d%d",&W,&H);
    }

    return 0;
}

