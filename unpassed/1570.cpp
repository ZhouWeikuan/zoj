#include<iostream>
#include<cstring>
#include<set>
using namespace std;
enum {
    SIZ = 104,
};

int ans = 0;
int N, K;
int b[4];
int c[4];
int a[14];
int par[14];
set<string> tab;

void init(){
    par[0] = 1;
    for (int i=1; i<14; ++i)
        par[i] = i * par[i-1];
}

void test(int d){
    if (d>=4){
        int t = 0;
        string s;
        for (int i=0; i<N; ++i){
            if (a[i] != -1){
                s += 'A' + a[i];
                ++t;
            } else {
                s += 'Z';
            }
        }
        if (tab.find(s)==tab.end()){
            ans += par[N-t];
            tab.insert(s);
        }
        return;
    }
    for (int i=0; i<N; ++i){
        if (a[b[d]]!=-1 && a[b[d]]!=i) continue;
        bool f = (a[b[d]]==i);
        a[b[d]] = i;
        if (a[i]==-1 || a[i]==c[d]){
            bool t = (a[i]==c[d]);
            if (!t)
                a[i] = c[d];
            test(d+1);
            if (!t)
                a[i] = -1;
        }
        if (!f){
            a[b[d]] = -1;
        }
    }
}

void search(){
    memset(a, -1, sizeof(a));
    test(0);
}

void dfs(int d){
    if (d >= 4){
        if ((c[0]*b[0]+c[1]*b[1]+c[2]*b[2]+c[3]*b[3])%N != K)
            return;
        search();
        return;
    }
    for (int i=0; i<N; ++i){
        bool f = false;
        for (int j=0; j<d; ++j){
            if (c[j]==i){
                f = true;
                break;
            }
        }
        if (!f){
            c[d] = i;
            dfs(d+1);
        }
    }
}

void fun(){
    ans = 0;
    tab.clear();
    dfs(0);
    printf("%d\n", ans);
}

int readIn(){
    if (scanf("%d%d",&N,&K) < 0) return 0;
    for (int i=0; i<4; ++i)
        scanf("%d", &b[i]);
    return 1;
}

int main(){
    init();
    while(readIn() > 0){
        fun();
    }

    return 0;
}

