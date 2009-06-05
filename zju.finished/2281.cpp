
#include<vector>
#include<iostream>
using namespace std;
enum {
    SIZ = 1000008,
    MaxN = 2000000008,
};
struct Edge{
    int r, c;
};
int dis[SIZ];
char mark[SIZ];
vector<Edge> edge[SIZ];
struct Node {
    int val;
    int pos;
    int room[SIZ];
    void clear(){ val =-1, pos = 0;}
    void update(int p, bool add){
        val = max(dis[p], val);
        if(!add)    return;
        room[pos++] = p;
        mark[p] = 1;
    }
};
Node tab[2];
int n,m;
int start, end;

int readIn(){
    if(scanf("%d%d",&n,&m) <0) return 0;
    int a, b, c;
    Edge one;
    for(a=1;a<=n; a++){
        mark[a] = 0;
        dis[a] =  0;
        edge[a].clear();
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&a,&b,&c);
        one.r = a, one.c = c;
        edge[b].push_back(one);
        one.r = b;
        edge[a].push_back(one);
    }
    scanf("%d%d",&start,&end);
    return 1;
}

int fun(){
    dis[start] = MaxN;
    Node *cur=&tab[0], *nex=&tab[1], *tmp;
    cur->clear(); nex->clear();
    cur->update(start, true);
    int t,i,v,o;
    while(dis[end] < cur->val){
        while(cur->pos > 0){
            t = cur->room[--cur->pos];
            mark[t] = 0;
            for(i=0; i<edge[t].size(); i++){
                o = edge[t][i].r;
                v = min(edge[t][i].c, dis[t]);
                if(dis[o] < v){
                    dis[o] = v;
                    nex->update(o, mark[o]==0);
                }
            }
        }
        tmp = cur; cur=nex; nex=tmp;
        nex->clear();
    }
    return dis[end];
}

int main(){

    while(readIn()>0){
        printf("%d\n", fun());
    }

    return 0;
}

