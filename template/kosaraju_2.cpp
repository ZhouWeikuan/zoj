/*
PKU2553 The Bottom of a Graph
*/

#include <stdio.h>
#include <memory.h>

#define clr(a) memset(a,0,sizeof(a))
#define N 5005
#define M 50000

typedef struct StrNode{
    int j;
    struct StrNode* next;
}Node;

Node mem[M];
int memp;

void addEdge(Node* e[],int i,int j){
    Node* p = &mem[memp++];
    p->j=j;
    p->next = e[i];
    e[i]=p;
}

int g_DFS_First;
void DFS_conn(Node* e[],int i,int mark[],int f[],int* nf){
    int j; Node* p;
    if(mark[i]) return;
    
    mark[i]=1;
    if(!g_DFS_First) f[i]=*nf;  //反向搜索，获取连通分量编号

    for(p=e[i];p!=NULL;p=p->next){
        j=p->j;
        DFS_conn(e,j,mark,f,nf);
    }
    if(g_DFS_First) f[(*nf)++]=i;   //正向搜索，获取时间戳
}

/*
有向图极大强连通分量
参数：
    邻接表e[]，节点数n。返回极大强连通分支的个数ncon。 
    返回con[i]表示节点i所属强连通分量的编号，0 ~ ncon-1。
*/
int Connection(Node* e[],int n,int con[]){
    int i,j,k,mark[N],ncon;
    int time[N],ntime;  //time[i]表示时间戳为i的节点 
    Node *p,*re[N]; //反向边
    
    //构造反向边邻接表
    clr(re);
    for(i=0;i<n;i++){
        for(p=e[i];p!=NULL;p=p->next)
            addEdge(re,p->j,i);
    }
    
    //正向DFS，获得时间戳 
    g_DFS_First = 1;
    clr(mark); clr(time); ntime=0;
    for(i=0;i<n;i++){
        if(!mark[i])
            DFS_conn(e,i,mark,time,&ntime);
    }
    
    //反向DFS，获得强连通分量 
    g_DFS_First = 0;
    clr(mark); clr(con); ncon=0;
    for(i=n-1;i>=0;i--){
        if(!mark[time[i]]){
            DFS_conn(re,time[i],mark,con,&ncon);
            ncon++;
        }
    }
}


//vars
Node* e[N];
int con[N],ncon;
int n,m;

int d[N];

int main()
{
    int i,j,k,x,y;
    Node *p;
    
    while(scanf("%d",&n)!=EOF && n){
        //init
        memp=0; clr(e);
        //input
        scanf("%d",&m);
        for(k=0;k<m;k++){
            scanf("%d%d",&i,&j); i--; j--;
            addEdge(e,i,j);
        }
        //Connection
        ncon=Connection(e,n,con);
        //work d[]
        clr(d);
        for(i=0;i<n;i++){
            x=con[i];
            for(p=e[i];p!=NULL;p=p->next){
                y=con[p->j];
                if(x!=y) d[x]++;
            }
        }
        //output
        j=0;
        for(i=0;i<n;i++){
            k=con[i];
            if(d[k]==0){
                if(j) printf(" "); j=1;
                printf("%d",i+1);
            }
        }
        puts("");
    }
    
    return 0;
}
