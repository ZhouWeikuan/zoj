#include<iostream>
#include<queue>
using namespace std;
enum {   
    SIZ = 13,
    NONE = 0,
    MINE = 1,
    BLOC = 2,
};
const double eps = 1e-7;
struct Node {
    unsigned total : 16;
    unsigned mine  : 16;
    unsigned step  : 16;
    unsigned type  : 16;
};
struct Point {
    unsigned x :16;
    unsigned y :16;
};
unsigned row, col;
unsigned sx, sy, tx, ty;
Node m[SIZ][SIZ];
char buf[2*SIZ];
int move[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
 
void readIn(){
    memset(m, -1, sizeof(m));
    scanf("%d%d ", &row, &col);
    for(unsigned i=0; i<row; i++){
        fgets(buf, SIZ*2, stdin);
        for(int j=0;buf[j]!='\n';j++){
            m[i][j].type = NONE;
            switch(buf[j]){
            case '#':
                m[i][j].type = BLOC;
                break;
            case 'S':
                sx = i, sy = j;
                break;
            case 'T':
                tx = i, ty = j;
                m[i][j].step = 0;
                m[i][j].total = 1;
                m[i][j].mine = 0;
                break;
            case 'M':
                m[i][j].type = MINE;
                break;
            }
        }
    }   
}
void fun(){
    queue<Point> q;
    unsigned s;
    Point cur, nex;
    cur.x = tx; cur.y = ty;
    q.push(cur);
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(m[cur.x][cur.y].type == MINE){
            m[cur.x][cur.y].mine = m[cur.x][cur.y].total;
        }
        s = m[cur.x][cur.y].step + 1;
        for(int i=0; i<4; i++){
            nex.x = cur.x + move[i][0];
            nex.y = cur.y + move[i][1];
            if(nex.x>=row||nex.y>=col||m[nex.x][nex.y].type==BLOC||m[nex.x][nex.y].step < s)
                continue;           
            if(m[nex.x][nex.y].step > s){
                q.push(nex);
                m[nex.x][nex.y].step    = s;
                m[nex.x][nex.y].total   = m[cur.x][cur.y].total;
                m[nex.x][nex.y].mine    = m[cur.x][cur.y].mine;
            } else {
                m[nex.x][nex.y].total   += m[cur.x][cur.y].total;
                m[nex.x][nex.y].mine    += m[cur.x][cur.y].mine;
            }
        }
    }
    double v = m[sx][sy].mine;
    v /= m[sx][sy].total;
    v = 1 - v;
    v *= 100;
    if(v < eps){
        printf("Mission Impossible.\n");
    } else {
        printf("The probability for the spy to get to the telegraph transmitter is %.2lf%%.\n", v);
    }
}
 
int main(){
    int n, c = 0;
   
    scanf("%d", &n);
    while(c++ < n){
        readIn();
        printf("Mission #%d:\n", c);
        fun();
        printf("\n");
    }
   
    return 0;
}

