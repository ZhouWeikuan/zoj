#include<iostream>
using namespace std;
// 使用四边形原理来优化？
enum {
    SIZ     = 100,
    MAXV    = 0x7ffffff,
};
struct Node {
    int val;
    int end;
};

int K, L;
int F[SIZ];
int S[SIZ];
char kname[SIZ], lname[SIZ];
Node mat[SIZ][SIZ];//for key i, when j is to be inserted

void fun(){
    int i, j, k, pv, v;
    mat[K-1][L].val = 0;
    mat[K-1][L].end = L;
    for(j=L-1; j>=0; j--){
        mat[K-1][j].val = mat[K-1][j+1].val + S[L] - S[j];
        mat[K-1][j].end = L;
    }
    for(i=K-2; i>=0; i--){
        mat[i][L].val = 0;
        mat[i][L].end = L;
        for(j=L-1; j>=0; j--){
            mat[i][j].val = 0;
            mat[i][j].end = L;
            for(k=0; k+j<L; k++){
                mat[i][j].val += F[j+k] * (k+1);
            }
            pv = mat[i][j].val;
            for(k=L-1; k>j; k--){ // at least one is inserted into j
                pv -= (k-j+1) * F[k];
                v   = pv + mat[i+1][k].val ;
                if(v <= mat[i][j].val){
                    mat[i][j].val = v;
                    mat[i][j].end = k;
                }
            }
        }
    }
    j = 0;
    //printf("%d\n", mat[0][0].val);
    for(i=0; i<K; i++){
        printf("%c: ", kname[i]);
        for(k=mat[i][j].end; j<k; j++){
            printf("%c", lname[j]);
        }
        printf("\n");
    }
}
void readIn(){
    scanf("%d%d",&K,&L);
    scanf("%s", kname);
    scanf("%s", lname);
    S[0] = 0;
    int i;
    for(i=0; i<L; i++){
        scanf("%d", &F[i]);
        S[i+1] = S[i] + F[i];
    }
    S[L+1] = F[L] = 0;
    /*
    char buf[SIZ];
    int l = 0, v = 0;
    for(l=0; l<L; l += i){
        scanf("%s", buf);
        for(i=0; buf[i]; i++){
            v += F[l+i] * (i + 1);
        }
    }
    printf("v = %d\n", v);
    */
}
int main(){
    int tst, n=0;
    scanf("%d", &tst);
    while(tst--){
        printf("Keypad #%d:\n", ++n);
        readIn();
        fun();
        printf("\n");
    }
    return 0;
}

