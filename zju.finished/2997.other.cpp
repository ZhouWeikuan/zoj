#include<iostream>
// from Zhang Rui
using namespace std;
int const Maxn=5000+3;
int d[Maxn],s[Maxn];
int n,p,q;
bool get=0;
int solve()
{
    int i,can=1,k=0;
    for (i=0;i<=n;i++) d[i]=0;
    for (i=0;i<=n;i++)
        if (i+p<=n) d[i+p]++;
    for (i=0;i<=n;i++)    //....
        if (i+q<=n) d[i]++;
    while (can)
    {
        can=0;
        for (i=0;i<=n;i++)
            if (d[i]==0)
            {
                can=1;
                s[i]=k++;
                if (i+p<=n) d[i+p]--;
                if (i-q>=0) d[i-q]--;// ..
                d[i]=-1;// ......
            }
    }
    if (k>n ) get=1;
    else get=0;
    return 0;
}

int main()
{

    while (scanf("%d%d%d",&n,&p,&q)!=EOF)
    {
        get=0;
        solve();
        if (get)
        {
            printf("YES\n");
            for (int i=1;i<=n;i++)
            {
                if (i>1) printf(" ");
                printf("%d",s[i]-s[i-1]);
            }
            printf("\n");
        }
        else printf("NO\n");
    }
    return 0;
}
