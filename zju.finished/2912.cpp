#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 10004,
};

double sum = 0.0;
struct Node {
    int par;
    int child;
    vector<int>  e;
    void init(){
        par = -1, child = 1;
        e.clear();
    }
};
int num;
Node tree[SIZ];

int dfs(int p){
    int n;
    double d;
    for(vector<int>::iterator it=tree[p].e.begin();
            it!=tree[p].e.end(); ++it){
        n = (*it)>>16; 
        d = (*it)&0x0ffff;
        if (tree[n].par == -1){
            tree[n].par = p;
            tree[p].child += dfs(n);
            sum += d*(num-tree[n].child)*tree[n].child;
        }
    }
    return tree[p].child;
}

int fun(){
    int i;
    scanf("%d ", &num);
    for(i=0; i<num; i++){
        tree[i].init();
    }
    int a, b, d;
    for(i=0; i<num-1; i++){
        scanf("%d%d%d ", &a, &b, &d);
        tree[a].e.push_back((b<<16)+d);
        tree[b].e.push_back((a<<16)+d);
    }
    sum = 0.0;
    dfs(0);
    sum *= 2;
    sum /= num;
    sum /= (num-1);
    printf("%lf\n", sum);
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        fun();
    }

    return 0;
}

