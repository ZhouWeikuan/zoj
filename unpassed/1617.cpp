#include<iostream>
#include<set>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
enum {
    SIZ = 26,
};
struct Node {
    int ind, out;
    bool ref; // a ref to itself;
    bool nex[SIZ];
};

Node tree[SIZ];
set<int> top, pro;
set<int>::iterator it;
int pos;
char buf[1000];

void remove(int t){
    if (tree[t].ref){
        tree[t].ref = false;
        tree[t].out = 1;
        ++tree[t].ind;
    }

    if (tree[t].out){
        for (int i=0; i<SIZ; ++i){
            if (!tree[t].nex[i]) continue;
            tree[t].nex[i] = 0;
            if (--tree[i].ind<=0){
                top.insert(i);
                pro.erase(i);
            }
        }
    }
    tree[t].out = 0;
}

int getFirstOut(){
    for (it=pro.begin(); it!=pro.end(); ++it){
        if (tree[*it].out){
            return *it;
        }
    }
    return -1;
}

void merge(set<string> &v){
    pos = 0;
    while(!v.empty()){
        int t = 250;
        for (set<string>::iterator it=v.begin(); it!=v.end(); ++it){
            if (t > (*it)[0])
                t = (*it)[0];
        }
        vector<string> tmp;
        for (set<string>::iterator it=v.begin(); it!=v.end(); ++it){
            if (t!=(*it)[0]) {
                continue;
            }
            tmp.push_back(*it);
        }
        buf[pos++] = t;
        for (int i=0; i<tmp.size(); ++i){
            v.erase(tmp[i]);
            string s;
            for (int j=1; tmp[i][j]; ++j){
                s += tmp[i][j];
            }
            if (s[0]){
                v.insert(s);
            }
        }
    }
    buf[pos] = 0;
}

void fun(){
    for (it=pro.begin(); it!=pro.end(); ){
        if (tree[*it].ind<=0){
            top.insert(*it);
            pro.erase(it++);
        } else {
            ++it;
        }
    }
    set<string> v;
    while(!pro.empty() || !top.empty()){
        if (top.empty()){
            if (!pro.empty()){
                int t = getFirstOut();
                top.insert(t);
            }
        } else {
            string s;
            while(!top.empty()){
                int t = *top.begin();
                top.erase(t);
                remove(t);
                s += 'a' + t;
            }
            v.insert(s);
        }
    }
    merge(v);
    if (pos <= 12){
        printf("%s\n", buf);
    } else {
        printf("impossible\n");
    }
}

int readIn(){
    int n, a, b;
    if (scanf("%d", &n) < 0) return 0;
    memset(tree, 0, sizeof(tree));
    top.clear(); pro.clear();
    while(n--){
        scanf("%s", buf);
        a = buf[0] - 'a';
        b = buf[1] - 'a';
        if (tree[a].nex[b]==false){
            if (a!=b){
                ++tree[b].ind;
            } else {
                tree[b].ref = true;
            }
            ++tree[a].out;
            tree[a].nex[b] = true;
        }
        pro.insert(a);
        pro.insert(b);
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

