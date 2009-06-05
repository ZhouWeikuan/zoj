#include<iostream>
#define MaxN 52

using namespace std;

int  n, maxValue;
int  path[MaxN][MaxN];
int  inClique[MaxN];

void dfs(int inGraph[])
{
    int i, j;
    int Graph[MaxN];

    if ( inClique[0]+inGraph[0]<=maxValue ) 
        return;
    if ( inClique[0]>maxValue ) 
        maxValue=inClique[0];

    /*对于图中的所有点*/
    for (i=1; i<=inGraph[0]; i++){
        /*把节点放置到团中*/
        ++inClique[0];
        inClique[inClique[0]]=inGraph[i];
        /*生成一个新的子图*/
        Graph[0]=0;
        for (j=i+1; j<=inGraph[0]; j++){
            if (path[inGraph[i]][inGraph[j]] ){
                Graph[++Graph[0]]=inGraph[j];
            }
        }
        dfs(Graph);
        /*从团中删除节点*/
        --inClique[0];
	}
}
int main()
{
    int inGraph[MaxN];
    int i, j;
    cin >>n;
    while (n > 0)
    {
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                cin >>path[i][j];
        maxValue = 1;
        /*初始化*/
        inClique[0]= 0;
        inGraph[0] = n;
        for (i=0; i<n; i++) inGraph[i+1]=i;
        dfs(inGraph);
        cout<<maxValue<<endl;
        cin >>n;
    }
    return 0;
}
