#include<iostream>

//深度优先搜索，确定最长无重复路径。
using namespace std;
enum {
    SIZ = 28,
};
struct Node {
    int pos;
    int con[SIZ];
};
struct Edge {
    int a;
    int b;
};
Node tree[SIZ];
int vis[SIZ * SIZ];
int num, edge;
int val;

void readIn(){
    int i;
    int a,b;
    for(i=0;i<num;i++){
        tree[i].pos = 0;
    }
    for(i=0;i<edge;i++){
        cin>>a>>b;
        tree[a].con[tree[a].pos ++] = b;
        tree[b].con[tree[b].pos ++] = a;
    }
}
int getKey(int a, int b){
    if(a < b){
        a = a * num + b;
    } else {
        a = b * num + a;
    }
    return a;
}
void dfs(int n, int step){
    if(step > val)
        val = step;
    int t;
    int e;

    for(int i=0;i<tree[n].pos;i++){
        t = tree[n].con[i];
        e = getKey(n, t);
        if(vis[e])
            continue;
        vis[e] = 1;
        dfs(t, step + 1);
        vis[e] = 0;
    }

}

int fun(){
    val = 0;
    for(int i=0;i<num;i++){
        dfs(i,0);
    }

    return val;
}

int main(){
    
    cin>>num>>edge;
    while(num){
        readIn();
        cout<<fun()<<endl;

        cin>>num>>edge;
    }

	return 0;
}
