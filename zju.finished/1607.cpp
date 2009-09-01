#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 104,
};

int N, M, cur;
int val[SIZ];
int tab[2][SIZ][SIZ]; // a, b 

int search0(int, int);
int search1(int a, int b){
    if (tab[1][a][b]!=-1)
        return tab[1][a][b];
    int t = cur - a - b;
    int v = min(t, M);
    int s = cur, r;
    for (int i=1; i<=v; ++i){
        if (t==i){
            r = val[a];
        } else {
            r = search0(a, b+i);
        }
        s = min(s, r);
    }
    return tab[1][a][b] = s;
}

int search0(int a, int b){
    if (tab[0][a][b]!=-1)
        return tab[0][a][b];
    int t = cur - a - b;
    int v = min(t, M);
    int s = 0, r;
    for (int i=1; i<=v; ++i){
        if (t==i){
            r = (a + t) + b - val[b];
        } else {
            r = search1(a+i, b);
        }
        s = max(s, r);
    }
    return tab[0][a][b] = s;
}

void fun(){
    memset(val, -1, sizeof(val));
    for (int i=0; i<=N; ++i){
        memset(tab, -1, sizeof(tab));
        cur = i;
        val[i] = search0(0, 0);
    }
    printf("%d\n", val[N]);
}

int readIn(){
    if (scanf("%d%d", &N,&M) < 0)
        return 0;
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

