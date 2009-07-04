#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
enum {
    SIZ = 1004,
};

struct Node {
    char m;
    int x, y;
    int w, h;
    int l, r;

    static int next;
    static void reset();
    static int getNext();
};
int Node::next;
void Node::reset(){
    Node::next = 0;
}
int Node::getNext(){
    return Node::next++;
}

Node tree[SIZ];
char dat[SIZ];
char out[SIZ][SIZ];


int build_tree(){
    int p = Node::getNext();
    tree[p].m = dat[p];
    tree[p].x = tree[p].y = -1;
    tree[p].l = tree[p].r = -1;
    if (!isalpha(tree[p].m)){
        tree[p].l = build_tree();
        tree[p].r = build_tree();
    }
    return p;
}

void bottom_up_wh(int p){
    if (isalpha(tree[p].m)){
        tree[p].w = tree[p].h = 2;
        return;
    }
    int l = tree[p].l;
    int r = tree[p].r;
    bottom_up_wh(l);
    bottom_up_wh(r);
    if (tree[p].m == '-'){
        tree[p].w = max(tree[l].w, tree[r].w);
        tree[p].h = tree[l].h + tree[r].h;
    } else {
        tree[p].h = max(tree[l].h, tree[r].h);
        tree[p].w = tree[l].w + tree[r].w;
    }
}

void top_down_wh(int p){
    if (isalpha(tree[p].m))
    {
        return;
    }
    int l = tree[p].l;
    int r = tree[p].r;
    tree[l].x = tree[p].x;
    tree[l].y = tree[p].y;
    if (tree[p].m == '|'){
        tree[r].w = tree[r].w * tree[p].w / (tree[l].w + tree[r].w);
        tree[l].w = tree[p].w - tree[r].w;
        tree[l].h = tree[r].h = tree[p].h;
        tree[r].x = tree[p].x;
        tree[r].y = tree[p].y + tree[l].w;
    } else {
        tree[r].h = tree[r].h * tree[p].h / (tree[l].h + tree[r].h);
        tree[l].h = tree[p].h - tree[r].h;
        tree[l].w = tree[r].w = tree[p].w;
        tree[r].y = tree[p].y;
        tree[r].x = tree[p].x + tree[l].h;
    }
    top_down_wh(l);
    top_down_wh(r);
}

void fill(){
    int i;
    out[0][tree[0].w] = '*';
    out[0][tree[0].w+1] = 0;
    for (i=1; i<tree[0].h; ++i){
        if (out[i][tree[0].w-1] == '-'){
            out[i][tree[0].w] = '*';
        } else {
            out[i][tree[0].w] = '|';
        }
        out[i][tree[0].w+1] = 0;
    }
    for (i=0; i<=tree[0].w; ++i){
        if (out[tree[0].h-1][i]=='|'){
            out[tree[0].h][i] = '*';
        } else{
            out[tree[0].h][i] = '-';
        }
    }
    out[tree[0].h][i] = 0;
}

void output(){
    int i;
    for (i=0; i<=tree[0].h; ++i){
        printf("%s\n", out[i]);
    }
}

bool check(int x, int y, char v){
    return (x>=0&&y>=0&&out[x][y]==v);
}

void draw(int p){
    if (!isalpha(tree[p].m)){
        draw(tree[p].l);
        draw(tree[p].r);
        return ;
    }
    int i;
    out[tree[p].x][tree[p].y] = tree[p].m;
    for (i=1; i<tree[p].w; ++i){
        if (check(tree[p].x-1, tree[p].y+i, '|')){
            out[tree[p].x][tree[p].y+i] = '*';
        } else {
            out[tree[p].x][tree[p].y+i] = '-';
        }
    }
    for (i=1; i<tree[p].h; ++i){
        if (check(tree[p].x+i, tree[p].y-1, '-')){
            out[tree[p].x+i][tree[p].y] = '*';
        } else {
            out[tree[p].x+i][tree[p].y] = '|';
        }
    }
}

void fun(){
    bottom_up_wh(0);
    tree[0].x = tree[0].y = 0;
    top_down_wh(0);
    memset(out, ' ', sizeof(out));
    draw(0);
    fill();
    output();
}

void readIn(){
    scanf("%s ", dat);
    Node::reset();
    build_tree();
}

int main(){
    int tst, n=0;
    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        printf("%d\n", ++n);
        fun();
    }

    return 0;
}

