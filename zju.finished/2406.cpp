#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
struct Node {
    int dis;
    int cnt;
    int v[SIZ];
};
struct cmp{
    bool operator()(Node*l, Node*r) const{
        if(l->dis != r->dis)
            return l->dis < r->dis;
        for(int i=0;i<l->cnt&&i<r->cnt;i++){
            if(l->v[i]!=r->v[i])
                return l->v[i]<r->v[i];
        }
        return true;
    }
};
Node tree[SIZ*10], *t[SIZ*10];
int v[SIZ];
int top,num;
int tab[SIZ][SIZ];
int mark[SIZ];
int NV,NR;
int SV,DV;
int MaxDist;

int readIn(){
    scanf("%d",&NV);
    if(NV <= 0)
        return 0;
    scanf("%d",&NR);
    memset(tab,0,sizeof(tab));
    memset(mark,0,sizeof(mark));
    int a, b, s;
    for(int i=0;i<NR;i++){
        scanf("%d%d%d",&a,&b,&s);
        tab[a][b] = tab[b][a] = s;
    }
    scanf("%d%d%d",&SV,&DV,&MaxDist);
    return 1;
}
void travel(int cur, int dis){
    if(dis > MaxDist )
        return;
    if(cur == DV){
        t[num] = &tree[num];
        tree[num].dis = dis; tree[num].cnt = top;
        for(int i=0;i<top;i++){
            tree[num].v[i] = v[i];
        }
        num++;
        return;
    }
    for(int i=1;i<=NV;i++){
        if(tab[cur][i] == 0 || mark[i] == 1)
            continue;
        mark[i] = 1; v[top++] = i;
        travel(i, dis + tab[cur][i]);
        mark[i] = 0; --top;
    }
}
void fun(){
    static int tstcase = 0;
    num = top = 0;
    mark[SV] = 1;
    v[top++] = SV;
    travel(SV, 0);
    mark[SV] = 0;
    --top;
    
    sort(t, t+num, cmp());
    if(tstcase++)
        cout<<endl;
    printf("Case %d:\n", tstcase);
    for(int i=0;i<num;i++){
        printf(" %d:", t[i]->dis);
        for(int j=0;j<t[i]->cnt;j++){
            printf(" %d", t[i]->v[j]);
        }
        printf("\n");
    }
}

int main(){
    while(readIn()){
        fun();
    }
    return 0;
}
