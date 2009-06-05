#include<iostream>
using namespace std;
enum {
    SIZ = 108,
    S = 0,
    R = 1,
    P = 2,
    W = 0,
    L = 1,
};
int tree[SIZ][2];
int n,k;

inline int getWin(int v){
    v += 2;
    v %= 3;
    return v;
}
inline int getLose(int v){
    v += 1;
    v %= 3;
    return v;
}

int getVal(char c){
    switch(c){
    case 'p':
        return P;
    case 's':
        return S;
    case 'r':
        return R;
    }
    return -1;
}

int readIn(){
    static char buf[20];
    int a,b;
    int v0,v1; 
    scanf("%d ", &n);
    if(n == 0) return 0;
    memset(tree, 0, sizeof(tree));
    scanf("%d ", &k);
    int lim = k * n * (n -1) / 2;
    while(lim--){
        scanf("%d%s", &a, buf);
        v0 = getVal(buf[0]);
        scanf("%d%s", &b, buf);
        v1 = getVal(buf[0]);
        a--,b--;
        if(v0 == v1){
            ;
        } else if(getWin(v0) == v1){
            tree[a][W]++;
            tree[b][L]++;
        } else if(getLose(v0) == v1){
            tree[a][L]++;
            tree[b][W]++;
        }
    }
    return n;
}
void fun(){
    double t;
    for(int i=0; i<n; i++){
        if(tree[i][W] + tree[i][L] == 0){
            printf("-\n");
            continue;
        }
        t = tree[i][W] + tree[i][L];
        t = tree[i][W] / t;
        printf("%.3lf\n", t);
    }
}
int main(){
    int tstcase = 0;
    while( readIn() > 0){
        if(tstcase++){
            printf("\n");
        }
        fun();
    }

    return 0;
}

