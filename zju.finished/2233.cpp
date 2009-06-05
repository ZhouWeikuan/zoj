#include<iostream>
#include<cstring>
#include<set>
using namespace std;
enum {
    SIZ = 108,
};
struct Node {
    int n;
    int d[SIZ];
};
Node tank[SIZ];
set<int> s[SIZ];
double dat[2][SIZ];
double eps = 1e-4;

int T,N,M;

bool same(double *a, double *b){
    for(int i=1; i<=N; i++){
        if( (a[i]>b[i]&&a[i]-b[i]>eps) || (b[i]>a[i]&&b[i]-a[i]>eps))
            return false;
    }
    return true;
}

void loop(double *cur, double *nex){
    memset(nex, 0, sizeof(dat[0]));
    int i,j;
    double t;
    for(i=1; i<=N; i++){
        if(tank[i].n==0){
            nex[i] = cur[i];
            continue;
        }
        t = cur[i]/tank[i].n;
        for(j=0; j<tank[i].n; j++){
            nex[tank[i].d[j]] += t;
        }
    }
}

void output(double *cur){
    for(int i=1; i<=N; i++){
        printf("%.3lf\n", cur[i]);
    }
    printf("\n");
}

void fun(){
    double *cur = dat[0], *nex=dat[1], *tmp;
    do{
        loop(cur, nex);
        tmp=cur, cur=nex, nex=tmp;
    }while(!same(cur, nex));
    output(cur);
}

void readIn(){
    scanf("%d%d ", &N,&M);
    for(int i=1; i<=N; i++){
        scanf("%lf ", &dat[0][i]);
        s[i].clear();
    }
    int a,b;
    for(int i=1; i<=M; i++){
        scanf("%d%d ", &a,&b);
        s[a].insert(b);
        s[b].insert(a);
    }
    for(int i=1; i<=N; i++){
        tank[i].n = s[i].size();
        a=0;
        for(set<int>::iterator it=s[i].begin();
                it!=s[i].end(); ++it){
            tank[i].d[a++] = *it;
        }
    }
}

int main(){
    scanf("%d ", &T);
    while(T--){
        readIn();
        fun();
    }

    return 0;
}

