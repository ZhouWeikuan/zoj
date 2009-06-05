#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 108,
    MSK = 0xff,
};
int move[5][2] = {
    {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
struct Point {
    int x,y;
    int cnt;
};
unsigned W, H, D;
bool mat[SIZ][SIZ][SIZ]; // true? valid step;
bool vis[SIZ][SIZ][SIZ];
Point pnt[SIZ];

void traceback(queue<unsigned> *cur){
    queue<unsigned> q;
    queue<unsigned> *nex = &q, *tmp;
    int t = D, x, y, nx, ny;
    while(t-- > 0){
        while(!cur->empty()){
            x = cur->front(); cur->pop();
            y = x & 0xff; x >>= 8;
            if(pnt[t].cnt == 0){
                pnt[t].cnt = 1;
                pnt[t].x = x;
                pnt[t].y = y;
            }else if(pnt[t].cnt == 1 && (pnt[t].x!=x || pnt[t].y!=y)){
                pnt[t].cnt = 2;
            }
            if(t <=0) continue;
            for(int i=0; i<5; i++){
                nx = x + move[i][0];
                ny = y + move[i][1];
                if(nx >= W || ny >= H 
                    || !mat[t-1][nx][ny]|| !vis[t-1][nx][ny]) continue;
                nex->push((nx<<8)|ny);
            }
        }
        tmp = nex, nex = cur, cur = tmp;
    }
}
void fun(){
    int t, i, j, ni, nj;
    unsigned v;
    queue<unsigned > q;
    for(i=0; i<W; i++){
        for(j=0; j<H; j++){
            if(!mat[0][i][j]) continue;
            vis[0][i][j] = true;
            q.push((i<<8)|j);
        }
    }
    while(!q.empty()){
        v = q.front(); q.pop();
        i = (v>>8)&0xff; j = v&0xff;
        t = (v>>16)&0xff;
        if(t == D-1) continue;
        for(int x=0; x<5; x++){
            ni = i + move[x][0];
            nj = j + move[x][1];
            if(ni >= W || nj >=H || !mat[t+1][ni][nj]) continue;
            if(vis[t+1][ni][nj] == false){
                vis[t+1][ni][nj] = true;
                q.push(((t+1)<<16)|(ni<<8)|nj);
            }
        }
    }
    t = D - 1;
    for(i=0; i<W; i++){
        for(j=0; j<H; j++){
            if(vis[t][i][j]){
                q.push((i<<8)|j);
            }
        }
    }
    if(q.empty()){
        printf("The robber has escaped.\n");
        return;
    }
    traceback(&q);
    t = 0;
    for(i=0; i<D; i++){
        if(pnt[i].cnt == 1){ // only print the doomed position
            t++;
            printf("Time step %d: The robber has been at %d,%d.\n", 
                    i+1, pnt[i].x+1, pnt[i].y+1);
        }
    }
    if(t == 0){
        printf("Nothing known.\n");
    }
}
int readIn(){
    scanf("%d%d%d", &W, &H, &D);
    if(W + H + D ==0) return 0;
    memset(mat, true, sizeof(mat));
    memset(vis, false, sizeof(vis));
    memset(pnt, 0, sizeof(pnt));
    int x0,y0,x1,y1,t, n, i, j;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d%d%d", &t, &x0, &y0, &x1, &y1);
        t--, x0--, y0--;
        for(i=x0; i<x1; i++){
            for(j=y0; j<y1; j++){
                mat[t][i][j] = false;
            }
        }
    }
    return 1;
}
int main(){
    int tst = 0;
    while(readIn() > 0){
        printf("Robbery #%d:\n", ++tst);
        fun();
        printf("\n");
    }
    return 0;
}

/****
第一　：罪犯可以呆在原地不动
第二  ：只要是可以确定的信息都要打印出来，比如我确定他1时间在（3，4），
但是不确定以后他在那里，那么还是要打印1时间在3、4。
第三 ： 不确定的信息统统不打印
第四 ： 没有一条确定信息才达“Nothing known.”。。。

 */
