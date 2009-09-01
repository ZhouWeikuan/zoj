#include<iostream>
#include<cstring>
#include<string>
#include<set>
using namespace std;
enum {
    SIZ = 12,
};
struct Node {
    string name;
    int base, dim, memsize;
    int low[SIZ], high[SIZ], sum[SIZ];
    bool operator <(const Node&a)const {
        return name < a.name;
    }
};

char buf[SIZ];
Node one;
int N, R;
set<Node> tab;
int sub[SIZ];

void query(){
    scanf("%s", buf);
    one.name = buf;
    set<Node>::iterator it = tab.find(one);
    const Node &o = *it;
    printf("%s[", o.name.c_str());
    int t = 0;
    for (int i=0; i<o.dim; ++i){
        scanf("%d", &sub[i]);
        if (i==0){
            printf("%d", sub[i]);
        } else {
            printf(", %d", sub[i]);
        }
        t += (sub[i] - o.low[i]) * o.sum[i];
    }
    t *= o.memsize; t += o.base;
    printf("] = %d\n", t);
}

void fun(){
    while(R--){
        query();
    }
}

void readNode(){
    scanf("%s%d%d%d", buf, &one.base, &one.memsize, &one.dim);
    one.name = buf;
    for (int i=0; i<one.dim; ++i){
        scanf("%d%d", &one.low[i], &one.high[i]);
    }
    one.sum[one.dim-1] = 1;
    for (int i=one.dim-2; i>=0; --i){
        one.sum[i] = one.sum[i+1] * (one.high[i+1]-one.low[i+1]+1);
    }
    tab.insert(one);
}

int readIn(){
    if (scanf("%d%d", &N, &R) < 0) return 0;
    tab.clear();
    for (int i=0; i<N; ++i){
        readNode();
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

