#include<iostream>
#include<cstring>
#include<complex>
using namespace std;
enum {
    SIZ = 108,
    LEN = 51,
};

unsigned m, n, q;
uint64_t tab[LEN][6];
uint64_t cnt[LEN];
char buf[LEN];

void fun(){
    memset(tab, 0, sizeof(tab));
    int i,j,k;
    for (i=3; i<LEN; ++i){
        tab[i][1] = cnt[i];
        for (int k=2; k<=n; ++k){
            for (j=3; j<=10 && i-j>=1; ++j){
                tab[i][k] += cnt[j] * tab[i-j][k-1];
            }
        }
    }
    while(q--){
        scanf("%u", &m);
        printf("%llu\n", tab[m][n]);
    }
}

void readIn(){
    scanf("%u%u%u", &m, &n, &q);
    memset(cnt, 0, sizeof(cnt));
    while(m--){
        scanf("%s", buf);
        ++cnt[strlen(buf)];
    }
}

int main() {
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0; 
}

