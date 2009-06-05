#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 208,
    N = 0x01,
    E = 0x02,
    S = 0x04, 
    W = 0x08,
};
int move[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int next[2][2] = {
    {1, 0},{0, 1}
};
int oppo[2][2] = {
    {0, -1},{-1, 0}
};
int revd[2][2] = {
    {S, N}, {W, E}
};
unsigned char dir[SIZ][SIZ];
unsigned      step[SIZ][SIZ];
struct Point{
    unsigned short x,y;
};
Point one;

void fun(){
    memset(step, -1, sizeof(step));
    step[one.x][one.y] = 0;
    queue<Point> q;
    q.push(one);
    Point nex;
    int i;
    while(!q.empty()){
        one = q.front(); q.pop();
        if(one.x==0&&one.y==0){
            break;
        }
        for(i=0; i<4; i++){
            nex.x = one.x + move[i][0];
            nex.y = one.y + move[i][1];
            if(nex.x > 200 || nex.y > 200 || step[nex.x][nex.y]!=-1)
                continue;
            if(0 == (dir[one.x][one.y]&(1<<i)))
                continue;
            step[nex.x][nex.y] = step[one.x][one.y] + 1;
            q.push(nex);
        }
    }
    printf("%d\n", (int)step[0][0]);
}
int readIn(){
    int w, d;
    scanf("%d%d",&w,&d);
    if(w==-1 && d==-1) return 0;
    memset(dir, -1, sizeof(dir));
    int x,y,v,l;
    while(w --){
        scanf("%d%d%d%d",&x,&y,&v,&l);
        while(l--){
            dir[x][y] &= ~revd[v][0];
            dir[x+oppo[v][0]][y+oppo[v][1]] &= ~revd[v][1];
            x += next[v][0];
            y += next[v][1];
        }
    }
    while(d --){
        scanf("%d%d%d",&x,&y,&v);
        dir[x][y] |= revd[v][0];
        dir[x+oppo[v][0]][y+oppo[v][1]] |= revd[v][1];
    }
    float a, b;
    scanf("%f%f",&a,&b);
    one.x = (unsigned short)a;
    one.y = (unsigned short)b;
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}
