#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
enum {
    SIZ = 300,
};
struct Node {
    int a, b;
    bool operator<(const Node&o)const {
        return b < o.b;
    }
};
int N, M;
Node tree[SIZ];
int tab[SIZ][SIZ];

void fun(){
    memset(tab, 0, sizeof(tab));
    for (int i=0; i<N; ++i){
        for (int j=1; j<=M&&j<=i+1; ++j){
            tab[i+1][j] = max(tab[i+1][j], tab[i][j]);
            tab[i+1][j] = max(tab[i+1][j], tab[i][j-1] + tree[i].a + tree[i].b*(j-1));
        }
    }
    printf("%d\n", tab[N][M]);
}

void readIn(){
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; ++i){
        scanf("%d", &tree[i].a);
    }
    for (int i=0; i<N; ++i){
        scanf("%d", &tree[i].b);
    }
    sort(tree, tree+N);
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

