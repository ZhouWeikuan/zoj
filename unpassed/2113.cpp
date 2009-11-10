#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <map>
#include <vector>
// TLE, don't know how to optimise the loop
using namespace std;
enum {
    SIZ = 2004,
    LIM = 1<<15,
};

struct Atom {
    bool isVar;
    bool isNeg;
    string var;
    int val;
};

struct Loop {
    int cnt;
    int s, e;
    void clear(){}
};

struct Line {
    string dest;
    vector<Atom> vec;

    void clear(){
        vec.clear();
    }
};

struct Node {
    bool isLine;
    Loop loop;
    Line line;
    void clear(){
        line.clear();
        loop.clear();
    }
};

int num, pos, lin;
Node tree[SIZ];
map<string, int> tab;
char buf[300];

bool isLoop(){
    return strncmp(buf, "LOOP", 4) == 0 && isdigit(buf[4]);
}

void pack(char *s){
    int j=0;
    for (int i=0; s[i]; ++i){
        if (!isblank(s[i])){
            s[j++] = s[i];
        }
    }
    s[j] = 0;
}

void getInput(){
    gets(buf); 
    ++lin;
    pack(buf);
}

void exe(Node &);
void exeLine(Node &o){
    int ans = 0, t;
    vector<Atom> &v = o.line.vec;
    for (int i=0; i<v.size(); ++i){
        if (v[i].isVar){
            t = tab[v[i].var];
        } else {
            t = v[i].val;
        }
        if (v[i].isNeg){
            t = -t;
        } 
        ans += t;
    }
    ans %= LIM;
    if (ans < 0) ans += LIM;
    tab[o.line.dest] = ans;
}

void exeLoop(Node &o){
    for (int i=0; i<o.loop.cnt; ++i){
        for (int j=o.loop.s; j<o.loop.e; ){
            if (tree[j].isLine){
                exeLine(tree[j]);
                ++j;
            } else {
                exeLoop(tree[j]);
                j = tree[j].loop.e;
            }
        }
    }
}

void embrace(Node &o){
    for (int i=o.loop.s; i<o.loop.e; ){
        if (tree[i].isLine){
            ++i;
        } else {
            embrace(tree[i]);
            i = tree[i].loop.e;
        }
    }
    int cur = &o-tree;
    if (cur + 1 < pos && tree[cur+1].loop.e == o.loop.e){
        o.loop.s = tree[cur+1].loop.s;
        o.loop.cnt *= tree[cur+1].loop.cnt;
        o.loop.cnt %= LIM;
    }
}

void fun(){
    for (int i=0; i<pos; ){
        if (tree[i].isLine){
            ++i;
        } else {
            embrace(tree[i]);
            i = tree[i].loop.e;
        }
    }

    for (int i=0; i<pos; ){
        if (tree[i].isLine){
            exeLine(tree[i]);
            ++i;
        } else {
            exeLoop(tree[i]);
            i = tree[i].loop.e;
        }
    }
    for (int i=0; i<pos; ++i){
        tree[i].clear();
    }
}

void createLineNode();
void createLoop(){
    Node &o = tree[pos++];
    o.isLine = false;
    o.loop.cnt = atoi(&buf[4]);
    o.loop.s = pos;
    getInput();
    if (buf[0] == '{'){
        getInput();
        while(buf[0]!='}'){
            createLineNode();
            getInput();
        }
    } else {
        createLineNode();
    }
    o.loop.e = pos;
}

void createAssign(){
    char *p = strchr(buf, '=');
    char *s;
    *p++ = 0;
    Node &o = tree[pos++];
    o.isLine = true;
    o.line.dest = buf;
    Atom a;
    a.isNeg = false;
    while(*p){
        for (s=p; *p && (*p!='+'&&*p!='-'); ++p)
            ;
        char ch = *p; *p=0;
        if (isdigit(*s)){
            a.isVar = false;
            a.val = atoi(s);
        } else {
            a.isVar = true;
            a.var = s;
        }
        *p = ch;
        o.line.vec.push_back(a);
        a.isNeg = (*p=='-');
        if (*p)
            ++p;
    }
}

void createLineNode(){
    if (isLoop()){
        createLoop();
    } else {
        createAssign();
    }
}

int readIn(){
    pos = 0; 
    tab.clear();
    scanf("%d ", &num);
    lin = 0;
    while(lin<num){
        getInput();
        createLineNode();
    }
}

void output(){
    map<string, int>::iterator it;
    for (it=tab.begin(); it!=tab.end(); ++it){
        printf("%s=%d\n", it->first.c_str(), it->second);
    }
}

int main(){
    int tn;

    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        fun();
        output();
    }

    return 0;
}

