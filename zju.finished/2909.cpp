#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
// LIS variants, to count how many non-decreasing sequences
using namespace std;
enum {
    SIZ = 200004,
};

int N, M;
int dat[SIZ];
int cls[SIZ];
unsigned nex[SIZ];
unsigned fir[SIZ];
int val[SIZ];

// the passed in  is position
struct cmp {
    bool operator ()(int a, int b) const {
        if (dat[a] != dat[b])
            return dat[a] < dat[b];
        return a < b;
    }
};

void output(int num){
    set<int, cmp> tab;
    for (int i=0; i<num; ++i){
        tab.insert(fir[i]);
    }
    bool first = true;
    while(!tab.empty()){
        int p = *tab.begin(); tab.erase(tab.begin());
        if (nex[p] != -1){
            tab.insert(nex[p]);
        }
        if (first){
            first = false;
        } else printf(" ");
        printf("%d", num - cls[p]);
    }
    printf("\n");
}

void fun(){
    int num = 0;
    for (int i=N-1; i>=0; --i){
        int p = lower_bound(val, val+num, dat[i]) - val;
        nex[i] = fir[p];
        cls[i] = p;
        fir[p] = i;
        val[p] = dat[i];
        if (p==num) ++num;
    }
    if (num > M){
        printf("Transportation failed\n");
    } else {
        for (int i=0; i<N; ++i){
            if (i) printf(" ");
            printf("%d", num - cls[i]);
        }
        printf("\n");
        output(num);
    }
}

int readIn(){
    scanf("%d%d", &N, &M);
    if (N == 0) return 0;
    for (int i=0; i<N; ++i){
        scanf("%d", &dat[i]);
    }
    memset(fir, -1, sizeof(fir));
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

