#include<iostream>

using namespace std;
enum {
    VexNum = 1008,
    EdgeNum = 15008,
};
struct Node {
    int a,b;
    int w,u;
    bool operator<(const Node&rhs) const {
        return w<rhs.w;
    }
};

int par[VexNum];
int vn,en;
Node edge[EdgeNum];

void init(){
    for(int i=0;i<vn;i++){
        par[i] = i;
    }
}
int getPar(int a){
    int p = par[a];
    while(p != par[p]){
        p = par[p];
    }
    return par[a] = p;
}
int in_same(int a, int b){
    a = getPar(a); b = getPar(b);
    return (a == b);
}
void connect(int a, int b){
    a = getPar(a); b = getPar(b);
    if(a < b){
        par[b] = a;
    } else if(a > b){
        par[a] = b;
    } 
}

void fun(){
    int ans=0,val=0;
    for(int i=0;ans<vn-1;i++){
        if(!in_same(edge[i].a, edge[i].b)){
            ans++;
            connect(edge[i].a, edge[i].b);
            edge[i].u = 1;
            val = edge[i].w;
        }
    }
    printf("%d\n%d\n",val,ans);
    for(int i=0;i<en;i++){
        if(edge[i].u == 0)
            continue;
        printf("%d %d\n", edge[i].a+1, edge[i].b+1);
    }
}

int main(){
    while(scanf("%d%d",&vn,&en) > 0){
        for(int i=0;i<en;i++){
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
            edge[i].a--, edge[i].b--;
            edge[i].u = 0;
        }
        init();
        sort(edge, edge+en);
        fun();
    }
	return 0;
}

