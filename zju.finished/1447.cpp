#include<iostream>
#include<string>
#include<map>
using namespace std;
enum {
    SIZ = 14,
};
unsigned par[SIZ];
unsigned tab[SIZ][SIZ];
unsigned init(){
    par[0] = 1;
    for (int i=1; i<SIZ; ++i){
        par[i] = i * par[i-1];
    }
    tab[0][0] = 1;
    for (int i=1; i<SIZ; ++i){
        for (int j=0; j<=i; ++j){
            tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
        }
    }
}

int N, M;
map<string, unsigned> idx;
unsigned ans;
unsigned pos[SIZ];
unsigned rnk[SIZ];

void fun(){
    int i, j;
    for (i=0; i<M; ++i)
        rnk[i] = pos[i];
    sort(rnk, rnk+M);
    i = 0, j = 0;
    ans = 0;
    while(i < M){
        while (j < rnk[i] ){
            ans += tab[N-j-1][M-i-1] * par[M];
            ++j;
        }
        ++i, ++j;
    }
    for (i=0; i<M; ++i){
        for (j=0; j<M; ++j){
            if (rnk[i] == pos[j]){
                pos[j] = i;
                break;
            }
        }
    }
    for (i=M-1; i>=0; --i){
        ans += par[i] * pos[i];
        for (j=i-1; j>=0; --j){
            if (pos[j] > pos[i]){
                --pos[j];
            }
        }
    }
    ++ans;
    printf("%d\n", ans);
}

int readIn(){
    if (scanf("%d%d", &N, &M) < 0) return 0;
    static char buf[40];
    string s;
    idx.clear(); 
    int nex = 0;
    for (int i=0; i<N; ++i){
        scanf("%s", buf);
        s = buf;
        idx.insert(make_pair(s, nex++));
    }
    for (int i=0; i<M; ++i){
        scanf("%s", buf);
        s = buf;
        pos[i] = idx[s];
    }
    return 1;
}

int main(){
    init();

    while(readIn() > 0){
        fun();
    }

    return 0;
}

