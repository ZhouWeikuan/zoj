//抄别人的，现在还看不懂
#define MAXN 100004
#define MIN(a,b) (((a)>(b))?(b):(a))

#include <iostream>
#include <cmath>

typedef struct point
{
    double x,y;
}POINT,*POINT_PTR;

POINT p[MAXN];
int n,label[MAXN],state;
double tempa,tempb;

inline int dcmp(double a,double b)
{
    if(a-b<1e-10&&b-a<1e-10)return 0;
    if(a>b)return 1;
    return -1;
}

inline bool cmp(const POINT &a,const POINT &b)
{
    return dcmp(a.x,b.x)<0;
}

inline bool cmp2(const int &a,const int &b)
{
    return dcmp(p[a].y,p[b].y)<0;
}

inline double dis(POINT a,POINT b)
{
    tempa=a.x-b.x;
    tempb=a.y-b.y;
    return sqrt(tempa*tempa+tempb*tempb);
}

double search(int s,int t)
{
    int i,j,mid;
    double ret(1e300);
    mid=(s+t)>>1;
    if(s>=t)return ret;
    for(i=mid;i>=s&&!dcmp(p[i].x,p[mid].x);--i);
    ret=search(s,i);
    for(i=mid;i<=t&&!dcmp(p[i].x,p[mid].x);++i);
    ret=MIN(ret,search(i,t));
    state=0;
    for(i=mid;i>=s&&dcmp(p[mid].x-p[i].x,ret)<=0;--i)label[++state]=i;
    for(i=mid+1;i<=t&&dcmp(p[i].x-p[mid].x,ret)<=0;++i)label[++state]=i;
    std::sort(label+1,label+state+1,cmp2);
    for(i=1;i<=state;++i)
        for(j=1;j<=10;++j)
            if(i+j<=state)
                ret=MIN(ret,dis(p[label[i]],p[label[i+j]]));
    return ret;
}

double solve(void)
{
    std::sort(p+1,p+n+1,cmp);
    return search(1,n);
}

int main(void)
{
    int i;
    while(true)
    {
        scanf("%d",&n);
        if(0==n)break;
        for(i=1;i<=n;++i)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        printf("%.2lf\n",solve()/2);
    }

    return 0;
}
