#include<iostream>
using namespace std;
// TLE
enum {
    MARK = 108,
    SIZ = 2008,
};

int N, K, P, M;
int dat[SIZ];
int tab[MARK][SIZ];

int get(int k, int s, int e){
    int v = 0;
    for(;s<e; s++){
        v += tab[s][k];
        v %= M;
    }
    return v;
}
inline void add(int k, int t, int v){
    tab[t][k] += v;
    tab[t][k] %= M;
}
void fun(){        
    int i, j, s, e, v, t;    
    memset(tab, 0, sizeof(tab));
    for(i=0; i<N; i++){        
        t = dat[i];        
        s = max(0, t-P);
        e = min(100, t+P) + 1;
        v = get(K, s, e);  // over the least length
        add(K, t, v);
        for(j=K-1; j>=1; j--){
            v = get(j, s, e);
            add(K, t, v);
        }        
        add(1, t, 1);
    }
    v = 0;
    for(i=0; i<=100; i++){
        v += tab[i][K];
        v %= M;
    }
    printf("%d\n", v);
}

int readIn(){
    if(scanf("%d%d%d%d", &N, &K, &P, &M)< 0)
        return 0;
    if(K < 1) K = 1;
    for(int i=0; i<N; i++){
        scanf("%d", &dat[i]);
    }
    return 1;
}

int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

