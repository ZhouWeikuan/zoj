#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<set>
using namespace std;
enum {
    SIZ = 204,
    NUM = 10,
};
const char * strEx = "aeiouy";
set<char> ex;
void init(){
    for (int i=0; strEx[i]; ++i){
        ex.insert(strEx[i]);
        ex.insert(toupper(strEx[i]));
    }
}

struct Node {
    int four;
    char buf[SIZ];
};
Node *next = 0;
Node *getNode(){
    if (next == 0){
        next = new Node();
    }
    memset(next, 0, sizeof(next));
    Node *p = next; next = 0;
    return p; 
}
void putNode(Node *p){
    if (next == 0){
        next = p;
    } else {
        delete p;
    }
}

Node * tree[NUM];

void insert(Node *p){
    if (tree[0])
        putNode(tree[0]);
    for (int i=1; i<NUM; ++i){
        tree[i-1] = tree[i];
    }
    tree[NUM-1] = p;
}

bool isExcept(char e){
    return ex.find(e) != ex.end();
}

bool selfMoreThanFive(Node *p){
    int cnt = 0, most = 0;
    char *s = p->buf;
    for (int i=0; s[i]; ++i){
        if (!isalpha(s[i]) || isExcept(s[i])){
            most = max(most, cnt);
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    most = max(most, cnt);
    p->four = (most > 4);
    return most>5;
}

bool check(Node *p){
    if (selfMoreThanFive(p)){
        return false;
    }
    int same = 0;
    int cnt = 0;
    for (int i=0; i<NUM; ++i){
        if (tree[i] == 0) 
            continue;
        cnt += tree[i]->four;
        if (strcmp(tree[i]->buf, p->buf)==0){
            ++same;
        }
    }
    if (same > 1 || (p->four && cnt > 2))
        return false;
    return true;
}

int main(){
    init();
    const char *ans[2] = { "n", "y" };
    int tn;
    scanf("%d", &tn);
    char tmp[SIZ];
    gets(tmp);
    while(tn--){
        Node * p = getNode();
        gets(p->buf);
        bool t = check(p);
        printf("%s\n", ans[t]);
        insert(p);
    }

    return 0;
}

