#include<iostream>

using namespace std;
enum {
    Num = 12,
    Day = 32,
};
struct Node {
    int pos;
    int tax[Day];
};
int N,K;
int dis[2][Num];
Node mat[Num][Num];

void readIn(){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            mat[i][j].pos = 0;
        }
    }
    int d,v;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==j)
                continue;
            scanf("%d", &d);
            mat[i][j].pos = d;
            for(int x=0;x<d;x++){
                scanf("%d",&v);
                mat[i][j].tax[x] = v;
            }
        }
    }
}

void fun(){
    int *pred = dis[0], *now=dis[1], *tmp;
    int i,loop, f, v;
    pred[0] = 0;
    for(i=1;i<N;i++){
        pred[i] = -1;
    }
    for(loop = 0; loop < K; loop++){
        for(i=0; i<N; i++){
            now[i] = -1;
            for(f=0;f<N;f++){
                if(mat[f][i].pos == 0 || pred[f] ==-1)
                    continue;
                v = loop % mat[f][i].pos;
                v = mat[f][i].tax[v];
                if(v == 0)
                    continue;
                v += pred[f];
                if(now[i]==-1 || v < now[i])
                    now[i] = v;
            }
        }
        tmp = now; now = pred; pred= tmp;
    }
    if(pred[N-1] != -1){
        printf("The best flight costs %d.\n", pred[N-1]);
    } else {
        printf("No flight possible.\n");
    }
}

int main(){
    int tstcase = 0;
    
    scanf("%d%d",&N, &K);
    while(K){
        printf("Scenario #%d\n", ++tstcase);
        readIn();
        fun();
        printf("\n");
        scanf("%d%d",&N, &K);
    }

	return 0;
}
