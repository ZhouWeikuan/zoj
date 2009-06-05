#include<iostream>
using namespace std;
// data help me much!
enum {
    SIZ = 1008,
};
struct Node {
    int pos;
    int start;
    int val[SIZ];
    void conv(char *s, int =0);
    void getSum(const Node&a, const Node&b);
    void getSub(const Node&a, const Node&b);
    void getMult(const Node&a, int m);
    void getAGG(const Node&a);
};
void Node::getAGG(const Node&a){
    int cry = 0, i;
    for(i=0; i<a.start; i++){
        if(pos <= i){
            val[pos++] = 0;
        }
    }
    for(; i<a.pos+a.start; i++){
        if(pos <= i){
            val[pos++] = 0;
        }
        cry += a.val[i-a.start] + val[i];
        val[i] = cry %10;
        cry /= 10;
    }
    while(cry > 0){
        if(pos <= i){
            val[pos++] = 0;
        }
        cry += val[i];
        val[i] = cry % 10;
        cry /= 10;
        i++;
    }
}
void Node::conv(char *s, int len){
    if(len == 0) 
        len = strlen(s);
    start   = 0;
    pos     = 0;
    for(len--; len>=0; len--){
        val[pos++] = s[len]-'0';
    }
}
void Node::getSum(const Node&a, const Node&b){
    int cry = 0, i;
    start = pos = 0;
    for(i=0; i<a.pos&&i<b.pos; i++){
        cry += a.val[i] + b.val[i];
        val[pos++] = cry % 10;
        cry /= 10;
    }
    for(; i<a.pos; i++){
        cry += a.val[i];
        val[pos++] = cry %10;
        cry /= 10;
    }
    for(; i<b.pos; i++){
        cry += b.val[i];
        val[pos++] = cry % 10;
        cry /= 10;
    }
    while(cry > 0){
        val[pos++] = cry % 10;
        cry /= 10;
    }
}
void Node::getSub(const Node&a, const Node&b){
    start = pos = 0;
    int cry =0, i;
    for(i=0; i<b.pos; i++){
        cry += a.val[i];
        cry -= b.val[i];
        val[pos++] = (cry + 10)%10;
        if(cry < 0){
            cry = -1;
        } else {
            cry = 0;
        }
    }
    for(; i<a.pos; i++){
        cry += a.val[i];
        val[pos++] = (cry + 10)%10;
        if(cry < 0) cry = -1;
        else cry = 0;
    }
    while(pos > 1 && val[pos-1] == 0){
        pos--;
    }
}
void Node::getMult(const Node&a, int m){
    pos = start = 0;
    if(m == 0){
        val[pos++] = 0;
        return;
    }
    int cry = 0, i;
    for(i=0; i<a.pos; i++){
        cry += m*a.val[i];
        val[pos++] = cry % 10;
        cry /= 10;
    }
    while(cry > 0){
        val[pos++] = cry % 10;
        cry /= 10;
    }
}

int width;
Node tree[SIZ];
char str[SIZ];

void line(const Node &one){
    int i = width - one.pos - one.start;
    while(i--){
        printf(" ");
    }
    for(i=one.pos-1; i>=0; i--){
        printf("%c", one.val[i] + '0');
    }
    printf("\n");
}
void output(int lim, char op){
    int i, t;
    tree[1].val[tree[1].pos++] = op - '0';
    line(tree[0]);
    line(tree[1]);
    t = width - max(tree[1].pos, tree[2].pos);
    for(i=0; i<t; i++){
        printf(" ");
    }
    for(; i<width; i++){
        printf("-");
    }
    printf("\n");
    if(op != '*'||(op == '*' && tree[1].pos <= 2)){
        line(tree[2]);
        return;
    }
    for(i=2; i<lim; i++)
        line(tree[i]);
    t = width - max(tree[lim-1].pos, tree[lim].pos);
    for(i=0; i<t; i++){
        printf(" ");
    }
    for(; i<width; i++){
        printf("-");
    }
    printf("\n");
    line(tree[lim]);
}
void fun(){
    int lim, i, p;
    for(i=0; isdigit(str[i]); i++){
        ;
    }
    p = i;
    tree[0].conv(&str[0], p);
    tree[1].conv(&str[i+1]);
    width = max(tree[0].pos, tree[1].pos+1);
    lim = 3;
    if(str[i] == '+'){
        tree[2].getSum(tree[0], tree[1]);
        width = max(width, tree[2].pos);
    }else if(str[i] == '-'){
        tree[2].getSub(tree[0], tree[1]);
        width = max(width, tree[2].pos);
    } else { // *
        lim = 2 + tree[1].pos;
        tree[lim].start = tree[lim].pos = 0;
        for(i=0; i<tree[1].pos; i++){
            tree[i+2].getMult(tree[0], tree[1].val[i]);
            tree[i+2].start = i;
            tree[lim].getAGG(tree[i+2]);
            width = max(width, tree[i+2].pos + tree[i+2].start);
        }
        width = max(width, tree[lim].pos);
    }
    output(lim, str[p]);
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        scanf("%s ", str);
        fun();
        printf("\n");
    }

    return 0;
}

