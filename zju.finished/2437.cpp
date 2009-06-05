#include<iostream>
using namespace std;
enum {
    SIZ = 204,
};
struct Zero {
    int x,y;
};
Zero tree[SIZ*SIZ];
int top;
struct Node {
    int d; // the distance, default -1;
    int v;
};
Node o[SIZ][SIZ];
int m[SIZ][SIZ];
int N;

void readIn(){
    top = 0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            o[i][j].d = -1;
            scanf("%d",&o[i][j].v);
            m[i][j] = o[i][j].v;
            if(o[i][j].v == 0){
                tree[top].x = i;
                tree[top].y = j;
                top ++;
            }
        }
    }
}
void calc(int x, int y){
    int d;
    for(int i=0;i<top;i++){
        Zero &p = tree[i];
        d = abs(x - p.x) + abs(y - p.y);
        if(o[p.x][p.y].d == -1 || o[p.x][p.y].d > d){
            o[p.x][p.y].d = d;
            m[p.x][p.y] = o[x][y].v;
        } else if(o[p.x][p.y].d == d){
            m[p.x][p.y] = 0;
        }
    }
}
void fun(){
    int t;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(o[i][j].v != 0){
                calc(i,j);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j==0){
                printf("%d", m[i][j]);
            } else {
                printf(" %d", m[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int tstcase;

    scanf("%d",&tstcase);
    while(tstcase --){
        readIn();
        fun();
        if(tstcase)
            printf("\n");
    }

    return 0;
}

