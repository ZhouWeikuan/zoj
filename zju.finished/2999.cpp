#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
enum {
    SIZ = 30004,
};
struct Node {
    char name[256];
    int cld;
    int nex;
    int a, b;
    void init(){
        cld = nex = a = b = -1;
    }
    bool isChild(Node &p){
        return (a>=p.a)&&(b<=p.b);
    }
};

int num;
Node tree[SIZ];
struct cmp {
    bool operator ()(int a, int b) const {
        return strcmp(tree[a].name, tree[b].name) < 0;
    }
};
map<int, int, cmp> tab;
map<int, int, cmp>::iterator it;
int stk[SIZ], pos, seq;

void fun(){
    int p, c;
    tree[num].init(); // for non-existent ones...
    tree[num+1].a = tree[num+1].b = -2;
    scanf("%d", &pos);
    while(pos -- > 0){
        scanf("%s%s", tree[num].name, tree[num+1].name);
        it = tab.find(num);
        if (it==tab.end()){
            c = num;
        } else {
            c = it->second;
        }
        it = tab.find(num+1);
        if (it==tab.end()){
            p = num + 1;
        } else {
            p = it->second;
        }
        if (tree[c].isChild(tree[p])){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

void enStk(int p){
    tree[p].a = ++seq;
    stk[pos++] = p;
}

void deStk(){
    --pos;
    tree[stk[pos]].b = ++seq;
}

void dfs(){
    seq = 0;
    pos = 0;
    enStk(0);
    while(pos > 0){
        int t = stk[pos-1];
        if (tree[t].cld >= 0){
            enStk(tree[t].cld);
            tree[t].cld = -1;
        } else if (tree[t].nex >=0){
            deStk();
            enStk(tree[t].nex);
        } else {
            deStk();
        }
    }
}

int readIn(){
    if (scanf("%s%d", tree[0].name, &num) < 0)
        return 0;
    tab.clear();
    tree[0].init();
    tab.insert(make_pair(0, 0));
    ++num;
    pos = 1;
    int p, c;
    for (int i=1; i<num; ++i){
        scanf("%s%s", tree[num].name, tree[num+1].name);
        it = tab.find(num);
        if (it == tab.end()){
            strcpy(tree[pos].name, tree[num].name);
            tree[pos].init();
            tab.insert(make_pair(pos, pos));
            c = pos++;
        } else {
            c = it->second;
        }

        it = tab.find(num+1);
        if (it == tab.end()){
            strcpy(tree[pos].name, tree[num+1].name);
            tree[pos].init();
            tab.insert(make_pair(pos, pos));
            p = pos++;
        } else {
            p = it->second;
        }

        tree[c].nex = tree[p].cld;
        tree[p].cld = c;
    }
    dfs();

    return 1;
}

int main(){
    int tn = 0;
    while(readIn() > 0){
        if (tn++) printf("\n");
        printf("Project %d\n", tn);
        fun();
    }

    return 0;
}

