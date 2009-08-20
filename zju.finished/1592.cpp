#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 1000004,
    LEN = 14,
};

int N, L;
map<int, int> tab[LEN];
map<int, int>::iterator it;
int last[LEN];
char dat[SIZ];

void fun(){
    int i, pos=0, j=0;
    int cur;
    for(j=0; j<L; ++j){
        cur = 0;
        for (i=13; i>=1; --i){
            it = tab[i].find(last[i]);
            if (it != tab[i].end()){
                cur = it->second;
                break;
            }
        }
        dat[pos++] = '0' + cur;
        for (i=1; i<=13; ++i){
            if (N + j>=i){
                tab[i][last[i]] = cur;
            }
            last[i] <<= 1;
            last[i] += cur;
            last[i] &= ~(1<<i);
        }
    }
    dat[pos] = 0;
    printf("%s\n", dat);
}

int readIn(){
    if (scanf("%d%d", &N,&L)<0) 
        return 0;
    scanf("%s", dat);
    for (int i=0; i<LEN; ++i){
        tab[i].clear();
    }
    int l;
    memset(last, 0, sizeof(last));
    for (int i=0; dat[i]; ++i){
        for (l=1; l<=13; ++l){
            if (i>=l){
                tab[l][last[l]] = dat[i]-'0';
                last[l] &= ~(1<<(l-1));
            }
            last[l] *= 2;
            last[l] += dat[i] - '0';
        }
    }

    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

