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
    if(!g_DFS_First) f[i]=*nf;  // reverse search, get the number for the connected part

    for(p=e[i];p!=NULL;p=p->next){
        j=p->j;
        DFS_conn(e,j,mark,f,nf);
    }
    if(g_DFS_First) f[(*nf)++]=i;   // normal search, to get the time mark
}

/*
 Get the maximum strong connect part for directed graph
parameters:
    neighbouring table e[], node number n, returned ncon the number of maximum strong connected part
    returned con[], con[i] to represent the number of strong connected part of node i, the range is 0 ~ ncon-1
*/
int Connection(Node* e[],int n,int con[]){
    int i,j,k,mark[N],ncon;
    int time[N],ntime;  //time[i] to represent the node which timestamp is i
    Node *p,*re[N]; //reverse edge
    
    // construct the reverse neighbouring table
    clr(re);
    for(i=0;i<n;i++){
        for(p=e[i];p!=NULL;p=p->next)
            addEdge(re,p->j,i);
    }
    
    // DFS, to get the timestamp
    g_DFS_First = 1;
    clr(mark); clr(time); ntime=0;
    for(i=0;i<n;i++){
        if(!mark[i])
            DFS_conn(e,i,mark,time,&ntime);
    }
    
    // reverse DFS to get the strong connected part
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
