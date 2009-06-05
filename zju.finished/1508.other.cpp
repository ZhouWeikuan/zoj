#include<iostream.h>
const int maxn=50010;

typedef struct
{
    int u,v,w;
}E;

E edge[maxn];
int d[maxn];
int maxb;
int n;

// i,j,w
//d[j]-d[i-1]>=w = d[i-1]<=d[j]-w;
//d[i]-d[i-1]>=0 = d[i-1]<=d[i];
//d[i]-d[i-1]<=1 = d[i]<=d[i-1]+1
void Bellman_Ford()
{
    int i,t;
    for(i=0;i<=maxb;i++) d[i]=0;
    bool flag=true;
    while(flag){
        flag=false;
        for(i=0;i<n;i++){
            t=d[edge[i].u]+edge[i].w;
            if(d[edge[i].v]>t){
                d[edge[i].v]=t;
                flag=true;
            }
        }
        for(i=1;i<=maxb;i++){
            if(d[i]>d[i-1]+1) {
                d[i]=d[i-1]+1;
                flag=true;
            }
        }
        for(i=maxb;i>0;i--){
            if(d[i-1]>d[i]){
                d[i-1]=d[i];
                flag=true;
            }
        }
    }
}
int main()
{
    int i,u,v,w;
    while(cin>>n){
        maxb=-1;
        for(i=0;i<n;i++){
             cin>>u>>v>>w;
             if(maxb<v) maxb=v;
             edge[i].u=v;
             edge[i].v=u-1;
             edge[i].w=-w;
        }
        Bellman_Ford();
        cout<<d[maxb]-d[0]<<endl;
    }
    return 0;
}
