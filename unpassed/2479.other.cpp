#include <iostream>
#include <cstdio>
using namespace std;
int a,b,n,must;
int area[11],x[11],y[11],num[11];
bool back[21][21];
int tot[12];
bool yes;

void haveatry(int ed) {
    int i,j,k,h,now;
    if (ed==must) {
        yes=true;
        return;
    }
    for (i=0;i<a;++i) {
        for (j=0;j<b;++j)
            if (!back[i][j])
                break;
        if (j<b)
            break;
    }
    for (now=0;now<n;++now) {
        if (num[now]==0)
            continue;
        if ((i+x[now]<=a) && (j+y[now]<=b)) {
            for (k=0;k<x[now];++k) {
                for (h=0;h<y[now];++h)
                    if (back[i+k][j+h])
                        break;
                if (h<y[now])
                    break;
            }
            if (k==x[now]) {
                for (k=0;k<x[now];++k)
                    for (h=0;h<y[now];++h)
                        back[i+k][j+h]=true;
                --num[now];
                haveatry(ed+area[now]);
                if (yes)
                    return;
                ++num[now];
                for (k=0;k<x[now];++k)
                    for (h=0;h<y[now];++h)
                        back[i+k][j+h]=false;
            }
        }
        if ((i+y[now]<=a) && (j+x[now]<=b)) {
            for (k=0;k<y[now];++k) {
                for (h=0;h<x[now];++h)
                    if (back[i+k][j+h])
                        break;
                if (h<x[now])
                    break;
            }
            if (k==y[now]) {
                for (k=0;k<y[now];++k)
                    for (h=0;h<x[now];++h)
                        back[i+k][j+h]=true;
                --num[now];
                haveatry(ed+area[now]);
                ++num[now];
                if (yes)
                    return;
                for (k=0;k<y[now];++k)
                    for (h=0;h<x[now];++h)
                        back[i+k][j+h]=false;
            }
        }
    }
}

bool predo(int x,int nowa) {
    int i;
    if (nowa==must)
        return true;
    if ((x==n) || (nowa>must))
        return false;
    for (i=0;i<=num[x];++i)
        if (predo(x+1,nowa+i*area[x]))
            return true;
    return false;
}

int main() {
    int i,t,z,kind,j;
    for (scanf("%d",&z);z>0;--z) {
        scanf("%d%d%d",&a,&b,&n);
        t=kind=0;
        must=a*b;
        for (i=0;i<n;++i) {
            scanf("%d%d",&x[i],&y[i]);
            t+=x[i]*y[i];
            for (j=0;j<kind;++j)
                if (((x[i]==x[j]) && (y[i]==y[j]))
                        || ((x[i]==y[j]) && (y[i]==x[j]))) {
                    ++num[j];
                    break;
                }
            if (j==kind) {
                x[kind]=x[i];
                y[kind]=y[i];
                area[kind]=x[i]*y[i];
                num[kind++]=1;
            }
        }
        if (t<must) {
            printf("NO\n");
            continue;
        }
        n=kind;
        if (!predo(0,0)) {
            printf("NO\n");
            continue;
        }
        memset(back,false,sizeof(back));
        yes=false;
        haveatry(0);
        printf((yes)?"YES\n":"NO\n");
    }
    return 0;
}

