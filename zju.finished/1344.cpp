#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 54,
};
struct Pnt{
    unsigned x,y;
    int m;
};
int move[5][2] = {
    {-1,0},{0,1},{1,0},{0,-1},{0,0}
};
int M, N, D;
int stat[SIZ][SIZ][SIZ];
int mat[SIZ][SIZ];
Pnt st, ex, dog;

int fun(){
    Pnt one, nex;
    queue<Pnt> q;
    st.m = 0;
    stat[0][st.x][st.y] = 1;
    q.push(st);
    while(!q.empty()){
        one = q.front(); q.pop();
        if(one.x == ex.x && one.y == ex.y){
            return stat[one.m][one.x][one.y]-1;
        }
        nex.m = (one.m + 1)%D ;
        for(int i=0; i<5; i++){
            nex.x = one.x + move[i][0];
            nex.y = one.y + move[i][1];
            if(nex.x>=M||nex.y>=N
                ||mat[nex.x][nex.y]
                ||stat[nex.m][nex.x][nex.y] != 0) 
                continue;
            stat[nex.m][nex.x][nex.y] = stat[one.m][one.x][one.y] + 1;
            q.push(nex);
        }
    }
    return -1;
}

void forbid(int s, const Pnt &p){
    unsigned x, y, d;
    x = p.x; y = p.y; d = p.m;
    while(x<M && y<N && mat[x][y] ==0){
        stat[s][x][y] = -1;
        x += move[d][0];
        y += move[d][1];
    }
}
int readIn(){
    static char buf[SIZ];
    scanf("%d%d",&M,&N);
    if(M + N ==0) return 0;
    memset(stat, 0, sizeof(stat));
    int x, y;
    scanf("%d%d",&x,&y);
    st.x = x-1, st.y = y-1;
    scanf("%d%d",&x,&y);
    ex.x = x-1, ex.y = y-1;
    scanf("%d%d",&x,&y);
    dog.x = x-1, dog.y = y-1; dog.m = 0;
    scanf("%d %s ", &D, buf);
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf(" %c ", &mat[i][j]);
            mat[i][j] = (mat[i][j]=='*');
        }
    }
    x = dog.x, y = dog.y;
    forbid(0, dog);
    for(int i=0; i<D; i++){
        switch(buf[i]){
        case 'G':
            dog.x += move[dog.m][0];
            dog.y += move[dog.m][1];
            break;
        case 'L':
            dog.m = (dog.m + 3) % 4;
            break;
        case 'R':
            dog.m = (dog.m + 1) % 4;
            break;
        }
        forbid(i+1, dog);
    }
    if(x == dog.x && y==dog.y && dog.m == 0){
        ;
    } else {
        D++;
    }
    return 1;
}
int main(){
    int tst = 0, t;

    while(readIn() > 0){
        if(tst++) printf("\n");
        printf("Case %d:\n", tst);
        t = fun();
        if(t < 0){
            printf("No way out\n");
        } else {
            printf("Minimal time is: %d\n", t);
        }
    }
    return 0;
}
