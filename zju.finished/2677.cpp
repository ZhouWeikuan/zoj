#include<iostream>
using namespace std;
enum {
    SIZ = 50008,
    PIP = 100008,
};
struct Node {
    int a,b;
    int cost;
};
int n,m;
long long s;
int par[PIP];
int ptr[PIP];
Node tree[PIP];
struct cmp{
    bool operator()(const int &a, const int &b) const {
        return tree[a].cost < tree[b].cost;
    }
};

int get_par(int a){
    int pa = par[a];
    while(pa != par[pa]){
        pa = par[pa];
    }
    return par[a] = pa;
}

bool same(int a, int b){
    int pa = get_par(a), pb = get_par(b);
    return pa==pb;
}

void conn(int a, int b){
    int pa = get_par(a), pb = get_par(b);
    int t = pa<pb?pa:pb;
    par[a] = par[b] = par[pa] = par[pb] = t;
}

int readIn(){
    int i,t;
    if(scanf("%d%d%llu ", &n, &m, &s) < 0)
        return 0;
    for(i=1; i<=n; i++){
        par[i] = i;
    }
    for(i=0; i<m; i++){
        scanf("%u%u%u", &tree[i].a, &tree[i].b, &tree[i].cost);
        ptr[i] = i;
    }
    sort(ptr, ptr+m, cmp() );
    for(i=m-1; i>=0; i--){
        t = ptr[i];
        if(!same(tree[t].a, tree[t].b)){
            conn(tree[t].a, tree[t].b);
            ptr[i] = -1;
        }
    }
    return 1;
}

void fun(){
    int cnt = 0, t = 0, v;
    for(int i=0;i<m;i++){
        if(ptr[i] < 0 ){
            continue;
        }
        v = tree[ptr[i]].cost;
        if(v <= s){
            s -= v;
            ptr[t++] = ptr[i];
            cnt ++;
        } else {
            break;
        }
    }
    printf("%d\n", cnt);
    if(t){
        printf("%d", ptr[0] + 1);
    }
    for(int i=1; i<t; i++){
        printf(" %d", ptr[i] + 1);
    }
    printf("\n");
}

int main(){
    int tstcase = 0;
    while( readIn() > 0){
        if(tstcase != 0){
            printf("\n");
        }
        tstcase++;
        fun();
    }

    return 0;
}

