#include<iostream>
#include<cmath>
#define inf 99999999
using namespace std;
struct In{
    double x,p;
}a[1003];
int main(){
    int cas,j,i;
    int l,r;
    scanf("%d",&cas);
    while(cas--){
        int N;
        int rr,ll;
        bool g1=true,g2=true;
        scanf("%d",&N);
        for(i=1;i<=N;i++) scanf("%lf %lf",&a[i].x,&a[i].p),getchar();
        if(a[1].p!=0){
            l=(int)(a[1].x*100.0/(a[1].p-0.5));
        }
        else l=inf;
        if(a[1].p!=100){
            r=(int)(a[1].x*100.0/(a[1].p+0.5)+1);
        }
        else r=(int)a[1].x;
        for(j=2;j<=N;j++){
            if(a[j].p!=0){
                ll=(int)(a[j].x*100.0/(a[j].p-0.5));
            }
            else ll=inf;
            if(a[j].p!=100){
                rr=(int)(a[j].x*100.0/(a[j].p+0.5)+1);
            }
            else rr=(int)a[j].x;
            l=min(ll,l);
            r=max(rr,r);
            if(r>l){
                g1=false;
                break;
            }
        }
        if(a[1].p!=0){
            l=(int)(a[1].x*100.0/(a[1].p));
        }
        else l=inf;
        if(a[1].p!=100){
            r=(int)(a[1].x*100.0/(a[1].p+1)+1);
        }
        else r=(int)a[1].x;
        for(j=2;j<=N;j++){
            if(a[j].p!=0){
                ll=(int)(a[j].x*100.0/(a[j].p));
            }
            else ll=inf;
            if(a[j].p!=100){
                rr=(int)(a[j].x*100.0/(a[j].p+1)+1);
            }
            else rr=(int)a[j].x;
            l=min(ll,l);
            r=max(rr,r);
            if(r>l){
                g2=false;
                break;
            }
        }
        if(g2 && g1) printf("Either\n");
        else if(g1 && !g2) printf("Rounding\n");
        else if(!g1 && g2) printf("Truncation\n");
        else printf("Neither\n");
    }
    return 0;
}

