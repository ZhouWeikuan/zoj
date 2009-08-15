#include<iostream>
using namespace std;
enum {
    SIZ = 508,
};
int an, bn;
int A[SIZ], B[SIZ];
int tab[2][SIZ];

int calc(int s[], int b[]){
    int *cur=tab[0], *nex=tab[1], *tmp;
    int i, j, v;
    for (j=0; j+an<=bn; ++j){
        cur[j] = (s[0]-b[j])*(s[0]-b[j]);
        if (j)
            cur[j] = min(cur[j], cur[j-1]);
    }
    for (i=1; i<an; ++i){
        memset(nex, 0, sizeof(tab[0]));
        nex[i] = cur[i-1] + (s[i]-b[i])*(s[i]-b[i]);
        for (j=i+1; j+an-i<=bn; ++j){
            v = cur[j-1] + (s[i] - b[j])*(s[i]-b[j]);
            nex[j] = min(v, nex[j-1]);
        }
        tmp = cur, cur = nex; nex = tmp;
    }
    return cur[bn-1];
}

void fun(){
    int v = 0;
    memset(tab, 0, sizeof(tab));
    if (an >= bn){
        swap(an, bn);
        v = calc(B, A);
    } else { // an < bn
        v = calc(A, B);
    }
    
    printf("%d\n", v);
}
void readIn(){
    int i;
    scanf("%d", &an);
    for(i=0; i<an; i++){
        scanf("%d", &A[i]);
    }
    sort(A, A+an);
    scanf("%d", &bn);
    for(i=0; i<bn; i++){
        scanf("%d", &B[i]);
    }
    sort(B, B+bn);
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

