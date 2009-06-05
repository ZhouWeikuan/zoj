#include <cstdio>
#include <cstring>
#include <algorithm>
#define MaxN 100010
using namespace std;

int x[MaxN],y[MaxN],k[MaxN],d[MaxN];
int arr[MaxN];
int N,CNT;

bool cmp_x(int i, int j){
    if (x[i]<x[j]) return true;
    else if (x[i]==x[j] && y[i]<y[j]) return true;
    return false;
}

bool cmp_y(int i, int j){
    if (y[i]<y[j]) return true;
    else if (y[i]==y[j] && x[i]<x[j]) return true;
    return false;
}

int getSum(int idx){
    int res;
    for (res=0;idx;idx-=idx&-idx)res+=arr[idx];
    return res;
}

void add(int idx){for (;idx<=CNT;idx+=idx&-idx) arr[idx]++;}
void del(int idx){for (;idx<=CNT;idx+=idx&-idx) arr[idx]--;}

void solve(){
    int i,j,t,res;
    for (i=0;i<N;i++){
        scanf("%d %d", x+i,y+i);
        k[i]=i; d[i]=0;
    }
    sort(k,k+N,cmp_x);
    CNT=1; t=x[k[0]]; x[k[0]]=CNT; d[k[0]]++; d[k[N-1]]--;
    for (i=1;i<N;i++){
        if (x[k[i]]==t) x[k[i]]=CNT;
        else{
            d[k[i-1]]--;
            d[k[i]]++;
            t=x[k[i]];
            x[k[i]]=++CNT;
        }
    }
    sort(k,k+N,cmp_y);
    memset(arr,0,sizeof(arr));
    i=0; res=0;
    while (i<N){
        for (j=i+1;j<N;j++)
            if (y[k[j]]!=y[k[i]]) break;
        for (t=i;t+1<j;t++){
            res+=getSum(x[k[t+1]]-1)-getSum(x[k[t]]);
        }
        for (t=i;t<j;t++){
            if (d[k[t]]==1) add(x[k[t]]);
            else if (d[k[t]]==-1) del(x[k[t]]);
        }
        i=j;
    }
    printf("%d\n", res+N);
}

int main(){
    while (EOF != scanf("%d", &N) && N)
        solve();
    return 0;
}
