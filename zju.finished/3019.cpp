#include<iostream>
#include<algorithm>
using namespace std;
enum {
    SIZ = 10004,
};
int N, M;
int tab[2][SIZ];

void fun(){
    int v = 0;
    int i=0, j=0;
    while(i<N && j<M){
        int t = tab[0][i] - tab[1][j];
        if (t == 0){
            ++v;
            ++i, ++j;
        } else if(t < 0){
            ++i;
        } else {
            ++j;
        }
    }
    printf("%d\n", v);
}

int readIn(){
    if (scanf("%d%d ", &N, &M) <= 0)
        return 0;
    int i;
    for (i=0; i<N; ++i){
        scanf("%d ", &tab[0][i]);
    }
    for (i=0; i<M; ++i){
        scanf("%d ", &tab[1][i]);
    }
    sort(tab[0], tab[0]+N);
    sort(tab[1], tab[1]+M);
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

