#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
enum {
    SIZ = 301,
    N = 1,
    P = -1,
};

int tab[SIZ][SIZ] = {0};
int ex[SIZ];

void add(int f, int s, int carry){
    if (f > s)
        swap(f, s);
    if (tab[f][s]== -1) return;
    f = carry + tab[f][s];
    if (f >= SIZ) return;
    ex[f] = 1;
}

int mex(int s){
    while(s<SIZ && ex[s]){
        ++s;
    }
    return s;
}

void init(){
    memset(tab, -1, sizeof(tab));
    int f, s, i;
    int av[SIZ];
    for (f=0; f <SIZ; ++f){
        memset(av, 0, sizeof(av));
        tab[f][f] = f;
        av[f] = 1;
        for (s=f+1; s<SIZ; ++s){
            if (av[s]) continue;
            if (tab[f][s] != -1) {
                av[tab[f][s]] = av[s] = 1;
                continue;
            }
            memset(ex, 0, sizeof(ex));
            for (i=0; i<f; i++){
                add(i, s, 0);
                add(i, s, f-i);
            }
            for (i=0; i<s; ++i){
                add(f, i, 0);
                add(f, i, s - i);
            }

            int v = mex(s + 1);
            if (v >= SIZ) continue;
            int d[3] = {f, s, v};
            sort(d, d+3);
            tab[d[0]][d[1]]=d[2];
            tab[d[0]][d[2]]=d[1];
            tab[d[1]][d[2]]=d[0];
            av[s] = av[v] = 1;
        }
    }
}

int main(){
    init();

    int d[3] = {SIZ, SIZ, SIZ};
    while(scanf("%d%d%d ", &d[0], &d[1], &d[2]) > 0){
        sort(d, d+3);
        if (tab[d[0]][d[1]] == d[2]){
            printf("0\n");
        } else {
            printf("1\n");
        }
    }

    return 0;
}

