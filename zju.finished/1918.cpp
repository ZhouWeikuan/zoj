#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 1444,
};
struct Node{
    int t,c;
};
int N, T, M;// load limit, ferry time, car time;
int car[SIZ];
Node tree[SIZ];

void fun(){
    tree[0].t = 0, tree[0].c = 0;
    int i, no, nt, nc;
    for(i=0; i<M; i++){
        nc = tree[i].c + 1;
        for(no = i; no<M && no-i<N; no++){
            nt = max(tree[i].t, car[no]) + T;
            if(no + 1 != M){
                nt += T;
            }
            if(tree[no+1].t > nt || (tree[no+1].t==nt&&tree[no+1].c>nc)){
                tree[no+1].t = nt;
                tree[no+1].c = nc;
            }
        }
    }
    printf("%d %d\n", tree[i].t, tree[i].c);
}
void readIn(){
    scanf("%d%d%d",&N, &T, &M);
    for(int i=0; i<M; i++){
        scanf("%d", &car[i]);
        tree[i].t = 99999999;
        tree[i].c = 99999999;
    }
    tree[M].t = 99999999;
    tree[M].c = 99999999;
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
