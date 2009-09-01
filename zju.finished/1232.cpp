#include<iostream>
#include<cstring>
#include<set>
using namespace std;
enum {
    SIZ = 104,
};

int A, B, M, L, K;
unsigned mat[SIZ][SIZ];
unsigned tab[2][SIZ], *cur, *nex;
struct cmp {
    bool operator()(const int&a, const int &b)const{
        if (nex[a] != nex[b])
            return nex[a] < nex[b];
        return a < b;
    }
};

void bfs(){
    memset(nex, -1, sizeof(tab[0]));
    nex[M-1] = 0;
    set<int, cmp> node;
    node.insert(M-1);
    int e, n;
    while(!node.empty()){
        e = *node.begin(); node.erase(node.begin());
        for (int i=0; i<M; ++i){
            if (mat[e][i] == -1) continue;
            if (nex[i] > nex[e] + mat[e][i]){
                if (nex[i] != -1){
                    node.erase(i);
                }
                nex[i] = nex[e] + mat[e][i];
                node.insert(i);
            }
        }
    }
}

void iter(unsigned *cur, unsigned *nex){
    int e, n;
    set<int, cmp> node;
    for (e=0; e<M; ++e){
        nex[e] = cur[e];
        node.insert(e);
    }
    while(!node.empty()){
        e = *node.begin(); node.erase(node.begin());
        for (int i=0; i<M; ++i){
            if (mat[e][i] == -1) continue;
            if (nex[i] > cur[e] && mat[e][i] <= L){
                node.erase(i);
                nex[i] = cur[e];
                node.insert(i);
            } 
            if (nex[i] > nex[e] + mat[e][i]){
                node.erase(i);
                nex[i] = nex[e] + mat[e][i];
                node.insert(i);
            }
        }
    }
}

void fun(){
    unsigned *tmp;
    nex = tab[0];
    bfs();
    cur = tab[0], nex = tab[1];
    for (int i=0; i<K; ++i){
        iter(cur, nex);
        tmp = cur, cur = nex, nex = tmp;
    }
    printf("%u\n", cur[0]);
}

void readIn(){
    scanf("%d%d%d%d%d", &A, &B, &M, &L, &K);
    memset(mat, -1, sizeof(mat));
    int a, b, d;
    while(M--){
        scanf("%d%d%d", &a, &b, &d);
        --a, --b;
        mat[a][b] = mat[b][a] = d;
    }
    M = A + B;
    // generate a nonstop min path;
    for (int k=0; k<A; ++k){
        for (a=0; a<M; ++a){
            if (a==k||mat[a][k] == -1) continue;
            for (b=0; b<M; ++b){
                if (a==b||k==b) continue;
                if (mat[k][b] == -1) continue;
                if (mat[a][b] > mat[a][k] + mat[k][b])
                    mat[a][b] = mat[a][k] + mat[k][b];
            }
        }
    }
}

int main(){
    int tst;

    scanf("%d", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

