#include<iostream>
using namespace std;
enum {
    SIZ = 1000,
    MaxV = -99999999,
    SAS = 0,
    SAF = 1,
    FAS = 2,
    FAF = 3,
};
struct Node{
    int t, a, b;
};
int n, m;
int req[SIZ];
int start[SIZ];
Node tree[SIZ*10];
const char* type[4] = {
    "SAS", "SAF", "FAS", "FAF"
};

int proc(const Node&o){
    if(o.b == MaxV) return 0;
    switch(o.t){
    case SAS:
        if(start[o.a]==MaxV || start[o.a] < start[o.b])
            start[o.a] = start[o.b];
        else return 0;
        break;
    case SAF:
        if(start[o.a]==MaxV ||start[o.a] < start[o.b] + req[o.b])
            start[o.a] = start[o.b] + req[o.b];
        else return 0;
        break;
    case FAS:
        if(start[o.a]==MaxV ||start[o.a] + req[o.a]< start[o.b])
            start[o.a] = start[o.b] - req[o.a];
        else return 0;
        break;
    case FAF:
        if(start[o.a]==MaxV ||start[o.a] + req[o.a]< start[o.b] + req[o.b])
            start[o.a] = start[o.b] - req[o.a] + req[o.b];
        else return 0;
        break;
    }
    return 1;
}
bool fun(){
    int i;
    start[0] = 0;
    for(int j=0; j<n; j++){
        for(i=0; i<m; i++){
            proc(tree[i]);
        }
        for(i=0; i<n; i++){
            if(start[i] < 0) start[i] = 0; // make sure all non-negative
        }
    }

    for(i=0; i<m;i++){
        if(proc(tree[i])) // make sure no loop
            return false;
    }
    for(i=0; i<n; i++){
        printf("%d %d\n", i+1, start[i]);
    }

    return true;
}

int readIn(){
    scanf("%d", &n);
    if(n == 0) return 0;
    int a, b,i;
    for(i=0; i<n; i++){
        scanf("%d", &req[i]);
        start[i] = MaxV;
    }
    m = 0;
    static char buf[20];
    scanf("%s", buf);
    while(buf[0] != '#'){
        scanf("%d%d", &a, &b);
        for(i=0; i<4 && strcmp(buf, type[i])!=0; i++){
            ;
        }
        tree[m].t = i;
        tree[m].a = a-1;
        tree[m].b = b-1;
        m++;
        scanf("%s", buf);
    }
    return n;
}
int main(){
    int tst=0;
    while(readIn() > 0){
        printf("Case %d:\n", ++tst);
        if(!fun()){
            printf("impossible\n");
        }
        printf("\n");
    }
    return 0;
}
