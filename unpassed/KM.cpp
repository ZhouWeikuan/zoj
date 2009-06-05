KM O(n^3)
crazyb0y @ 2007-04-21 23:11

///对KM算法还没有理解，看完了再说
//
//  Author         :  Jin Bin
//  Description    :  KM algorithm with O(n^3) time
//
///////////////////////////////////////////////////
#include<cstdio>
#include<cstring>
#define maxn (1001)
long w[maxn][maxn],lx[maxn],ly[maxn],n;
long fx[maxn],fy[maxn],sy[maxn],slack[maxn],slackx[maxn];
void fix(long e){
    long tmp;
    while(e!=-1){
        sy[e]=fy[e];
        e=fx[fy[e]];
    }
}
long find(long s){
    long u,v,found,min,mini;
    memset(fx,0,sizeof(fx));
    memset(fy,0,sizeof(fy));
    fx[s]=-1;
    for(u=1;u<=n;u++){
        slack[u]=lx[s]+ly[u]-w[s][u];
        slackx[u]=s;
    }
    while(1){
        found=0;
        for(u=1;u<=n;u++)
            if(fy[u]==0&&slack[u]==0){
                found=1;
                if(sy[u]==0){
                    fy[u]=slackx[u];
                    return u;
                }else{
                    fy[u]=slackx[u];
                    fx[sy[u]]=u;
                    for(v=1;v<=n;v++)
                        if(fy[v]==0&&lx[sy[u]]+ly[v]-w[sy[u]][v]<slack[v]){
                            slack[v]=lx[sy[u]]+ly[v]-w[sy[u]][v];
                            slackx[v]=sy[u];
                        }
                }
            }
        if(!found){
            min=0x7fffffff;
            for(u=1;u<=n;u++)
                if(fy[u]==0&&slack[u]<min){
                    min=slack[u];
                    mini=u;
                }
            for(u=1;u<=n;u++){
                if(fx[u])
                    lx[u]-=min;
                if(fy[u])
                    ly[u]+=min;
                slack[u]-=min;
            }
        }
    }
}
void init(){
    memset(sy,0,sizeof(sy));
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    scanf("%ld\n",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%ld",&w[i][j]);
            lx[i]>?=w[i][j];
        }
}
void KM(){
    for(int i=1;i<=n;i++)
        fix(find(i));
}
void out(){
    long i,j,s=0;
    for(i=1;i<=n;i++)
        s+=w[sy[i]][i];
    printf("%ld\n",s);
}
int main(){
    init();
    KM();
    out();
    return 0;
} 

