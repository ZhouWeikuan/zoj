#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
enum {
    SIZ = 24,
};
int  wet[SIZ][SIZ];
struct Point {
    int x,y,w;
    bool operator < (const Point &rhs) const {
        return w > rhs.w;
    }
};
char room[SIZ][SIZ]; // 0-free, 1-beamed, *-obstacles.
int row, col;
Point src, dst;
const char *dir="dulr";
int move[4][2] = {
    {1,0},{-1,0},{0,-1},{0,1}
};
int direct[8][2] = {
    {-1,-1}, {-1,0}, {-1,1}, 
    {0,-1},     {0, 1},
    {1,-1}, {1,0}, {1,-1},
};
int get_dir(char d){
    for(int i=0; dir[i]; i++){
        if(dir[i] == d) return i;
    }
    return 4;
}
bool valid(int x, int y){
    return x>=0&&y>=0&&x<row&&y<col;
}
void expand(int x, int y){
    int d = get_dir(room[x][y]);
    x += move[d][0];
    y += move[d][1];
    while( valid(x,y)){
        if(room[x][y] > 2){
            break;
        }
        room[x][y] = 1;
        x += move[d][0];
        y += move[d][1];
    }
}
int readIn(){
    if( scanf("%d%d",&row,&col) <= 0) return 0;
    scanf("%d%d%d%d",&src.x,&src.y,&dst.x,&dst.y);
    src.x--, src.y--, dst.x--, dst.y--;
    memset(wet, -1, sizeof(wet));
    memset(room, 0, sizeof(room));
    int n;
    Point p; char t;
    scanf("%d",&n);
    for( ; n>0; n--){
        scanf("%d%d %c ", &p.x, &p.y, &t);
        p.x --, p.y --;
        room[p.x][p.y] = t;
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(room[i][j] < 2) continue;
            if(room[i][j] != 'B'){
                expand(i,j);
            }
            room[i][j] = 'B';
        }
    }

    return 1;
}

int fun(){
    // if (room[src.x][src.y] == 1) return -1;
    priority_queue<Point> q;
    wet[src.x][src.y] = 0;
    q.push(src);
    Point cur, nex;
    int v, t;
    while( !q.empty() ){
        cur = q.top(); q.pop();
        if(cur.x == dst.x && cur.y==dst.y){
            return wet[dst.x][dst.y];
        }
        if (cur.w > wet[cur.x][cur.y])
            continue;
        v = cur.w;
        for(int i=0; i<8; i++){
            nex.x = cur.x + direct[i][0];
            nex.y = cur.y + direct[i][1];
            if(!valid(nex.x, nex.y) 
                    || room[nex.x][nex.y] > 2
                    || (room[cur.x][cur.y] == 1 && room[nex.x][nex.y]==1)){
                continue;
            }
            t = v + (room[nex.x][nex.y]==1);
            if(wet[nex.x][nex.y]==-1 || wet[nex.x][nex.y]>t){
                wet[nex.x][nex.y] = t;
                nex.w = t;
                q.push(nex);
            }
        }
    }
    return -1;
}

int main(){
    int t;

    while(readIn() > 0){
        t = fun();
        printf("%d\n", t);
    }
    return 0;
}

