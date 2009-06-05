#include<iostream>
using namespace std;
enum {
    SIZ = 10008,
};
int tab[SIZ];
int N,M;
int cnt, val;
int top, save[SIZ];

void fun(){
    val = cnt = 0;
    int t;
    memset(tab, 0, sizeof(tab));
    for(int i=0; i< N; i++){
        for(int j=0;j<M;j++){
            scanf("%d",&t);
            if(val < t){
                val = t;
            }
            ++tab[t];
            if(tab[t] > cnt){
                cnt = tab[t];
            }
        }
    }
    int cur = 0;
    for(int i=1;i<=val;i++){
        if(tab[i] >= cnt)
            continue;
        if(tab[i] > cur){
            cur = tab[i];
            top = 0; save[top++] = i;
        } else if(tab[i] == cur){
            save[top++] = i;
        }
    }
    for(int i=0;i<top;i++){
        printf("%d ", save[i]);
    }
    printf("\n");
}
int main(){
    scanf("%d%d",&N,&M);
    while(N && M){
        fun();
        scanf("%d%d",&N,&M);
    }
    return 0;
}
