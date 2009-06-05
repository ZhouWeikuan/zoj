#include<iostream>
using namespace std;
enum {
    SIZ = 508,
};
struct Node {
    int v;
    Node *p;
};
int n, m;
int a[SIZ];
int b[SIZ];
Node mat[SIZ][SIZ];

void dump(Node *p, int s){
    n = s;
    while(s--){
        a[s] = b[(p - mat[0])%SIZ];
        p = p->p;
    }
}

void fun(){
    int i, j, s, v;
    Node *p;
    memset(mat[0], 0, sizeof(mat[0]));
    for(i=1; i<=n; i++){
        s = 0, p = 0;
        for(j=1; j<=m; j++){
            mat[i][j] = mat[i-1][j];
            if(b[j] < a[i] && mat[i][j].v > s){
                s = mat[i][j].v ;
                p = &mat[i][j];
            }
            if(a[i] == b[j] && mat[i][j].v < s + 1){
                mat[i][j].v = s + 1;
                mat[i][j].p = p;
            }
        }
    }
    s = 0, p = 0;
    for(j=1; j<=m; j++){
        if(mat[n][j].v > s){
            s = mat[n][j].v;
            p = &mat[n][j];
        }
    }
    dump(p, s);
}

int readIn(){
    scanf("%d", &n);
    int i;
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(i=1; i<=m; i++){
        scanf("%d", &b[i]);
    }
    return 1;
}
void output(){
    printf("%d\n", n);
    if(n == 0) return;
    printf("%d", a[0]);
    for(int i=1; i<n; i++){
        printf(" %d", a[i]);
    }
    printf("\n");
}
int main(){
    int tst=0;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
        output();
        if(tst){
            printf("\n");
        }
    }
    return 0;
}

