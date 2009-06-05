#include<iostream>
#include<cstring>
// TLE
using namespace std;
enum {
    SIZ = 104,
};
int N, S, T;

int mat[SIZ][SIZ];
int rev[SIZ][SIZ];
unsigned dis[SIZ];
bool mark[SIZ];

int findMin()
{
    int r = -1;
    for(int i=0; i<N; i++){
        if(mark[i]) continue;
        if( r==-1 || dis[r] > dis[i])
            r = i;
    }
    return r;
}

void expand(int p)
{
    for(int i=0; i<N; i++){
        if(!mark[i] && mat[p][i] >=0 && dis[i] > dis[p] + mat[p][i]){
            dis[i] = dis[p] + mat[p][i];
        }
    }
}

int search(int p)
{
    if(p==T) return 1;
    for(int i=0; i<N; i++){
        if(mark[i]) continue;
        if(mat[p][i] >=0 && dis[i] == dis[p] + mat[p][i])
        {
            mark[i] = true;
            if(search(i))
            {
                rev[p][i] = mat[p][i];
                mat[p][i] = -1;
                return 1;
            }
        }
        if(rev[p][i] >=0 && dis[p] == dis[i] + rev[p][i])
        {
            mark[i] = true;
            if(search(i))
            {
                mat[p][i] = rev[p][i];
                rev[p][i] = -1;
                return 1;
            }
        }
    }
    return 0;
}

int fun()
{
    if (S == T) return -1;
    memset(mark, false, sizeof(mark));
    memset(dis, -1, sizeof(dis));
    memset(rev, -1, sizeof(rev));
    dis[S] = 0;
    int p;
    while((p=findMin()) >=0){
        mark[p] = true;
        expand(p);
    }
    int ret = -1;
    do
    {
        memset(mark, false, sizeof(mark));
        mark[S] = true;
        ++ret;
    }while(search(S));
    return ret;
}

int readIn()
{
    if (scanf("%d ", &N)< 0)
        return 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d ", &mat[i][j]);
        }
    }
    scanf("%d%d ", &S, &T);
    return 1;
}
int main()
{
    while(readIn() > 0){
        int v = fun();
        if ( v < 0) {
            printf("inf\n");
        }
        else {
            printf("%d\n", v);
        }
    }
}
