#include<iostream>
#include<algorithm>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
/* 标准做法: 利用dp，从不可行点推导所有的可行点，再找下一个不可行点再推*/
enum {
    SIZ = 301,
};
bool tab[SIZ][SIZ][SIZ] = {false};
inline void mark(int t, int b, int c){
    int a[] = {t, b, c};
    sort(a, a+3);
    tab[a[0]][a[1]][a[2]] = true;
}
void init(){
    int i, j, k, t;
    for (i=0; i<SIZ; ++i){
        for (j=i; j<SIZ; ++j){
            for (k=j; k<SIZ; ++k){
                if (tab[i][j][k]) continue;
                // printf("%d %d %d\n", i, j, k);
                for (t=i+1; t<SIZ; ++t)
                    mark(t, j, k);
                for (t=j+1; t<SIZ; ++t)
                    mark(i, t, k);
                for (t=1; t+k<SIZ; ++t){
                    mark(i, j+t, k+t);
                    mark(i+t, j, k+t);
                    mark(i+t, j+t, k);
                }
                for ( ; t+j<SIZ; ++t){
                    mark(i+t, j+t, k);
                }
                break;
            }
        }
    }
}

int fun(void){
    int a[3];
    if (scanf("%d%d%d", &a[0], &a[1], &a[2]) < 0)
        return 0;
    sort(a, a+3);
    printf("%d\n", tab[a[0]][a[1]][a[2]]);
    return 1;
}

int main(){
    init();
    while(fun()){
        ;
    }
    return 0;
}

