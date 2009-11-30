#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
/* 博弈论 */
/* 当求点k=tab[f][s](f<s)值时，先求出k的不可能值notk，
 *          除去所有的notk后，剩下最小的那个值就是k
 * 即若想知道当f, s时, k的值，那么notk为
 *      0) 以前已经求出的值，即tab[f][i](i<s)和tab[i][s](i<f)
 *      1) 固定f, 当i<s时, notk=tab[f][i] + s - i 
 *      2) 固定s, 当i<f时, notk=tab[i][s] + f - i
 *      3) 同时滑动f,s，即当i<f时, notk=tab[f-i][s-i];
 **/ 
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
                add(i, s-f+i, 0);
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
    
    /*
    for (int i=0; i<SIZ; ++i){
        for (int j=i; j<SIZ; ++j){
            if (tab[i][j] < j) continue;
            printf("%d %d %d\n", i, j, tab[i][j]);
        }
    }
    */
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

