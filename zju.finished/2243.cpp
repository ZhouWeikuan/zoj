#include<iostream>
using namespace std;
enum {
    SIZ = 50008,
};
struct Node {
    int p;
    struct Node  *l,*r;
    char name[16];
};
struct Node_cmp{
    bool operator()(const Node *l, const Node*r) const{
        return strcmp(l->name, r->name)< 0;
    }
};
Node node[SIZ];
Node *tree[SIZ];
Node *save[SIZ];
int num;
int parse(char *p){
    p = strchr(p,'/');
    p++;
    return atoi(p);
}
void readIn(){
    int i;
    for(i=0;i<num;i++){
        tree[i] = &node[i];
        scanf("%s", node[i].name);
        node[i].p = parse(node[i].name);
        node[i].l = node[i].r = NULL;
    }
    tree[i] = &node[i];
    sort(tree, tree + num, Node_cmp() );
}
void output(Node *r){
    if(r == NULL)
        return;
    printf("(");
    output(r->l);
    printf(r->name);
    output(r->r);
    printf(")");
}
/*
 * 采用从根到叶查找时，这时复杂度为O(n^2)
 *  如果从叶到根查找时，复杂度为O(n)，因为每个结点最多被访问一次
 */
int fun(){
    int i, top = -1;
    save[++top] = tree[0];
    for(i=1;i<num;i++){
        if(save[top]->p > tree[i]->p){
            save[top]->r = tree[i];
            save[++top] = tree[i];
        } else {
            while(top >= 0 && save[top]->p < tree[i]->p){
                --top;
            }
            if(top >= 0){
                save[top]->r = tree[i];
            }
            tree[i]->l = save[top+1];
            save[++top] = tree[i];
        }
    }
    output(save[0]);
    printf("\n");
    return 0;
}
int main(){
    
    scanf("%d",&num);
    while(num > 0){
        readIn();
        fun();
        scanf("%d",&num);
    }

    return 0;
}
