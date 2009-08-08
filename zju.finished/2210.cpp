#include<iostream>
#include<cstring>
#include<set>
using namespace std;
enum {
    SIZ = 200,
    U = 0, L = 1, R = 2, D = 3,
};
int move[4][2] = {
    {0, 1}, {-1, 0}, {1, 0}, {0, -1}
};
unsigned conn[4][SIZ][SIZ];
unsigned cost[SIZ][SIZ];
struct Point{
    unsigned short x,y;
    bool operator <(const Point&o)const{
        if (x!=o.x) return x<o.x;
        return y<o.y;
    }
};
Point dst;
set<Point> lad[SIZ*SIZ];

int fun(){
    if (dst.y>=SIZ || dst.x>=SIZ) return 0;
    int s = 0, e = 0;
    int v;
    Point cur ={0}, nex;
    cost[0][0] = 0;
    lad[s].insert(cur);
    for (; s<=e; ++s){
        while(!lad[s].empty()){
            cur = *lad[s].begin(); lad[s].erase(lad[s].begin());
            if (cur.x==dst.x && cur.y==dst.y){
                return cost[dst.y][dst.x];
            }
            for(int i=0; i<4; i++){
                if (conn[i][cur.y][cur.x] == -1)
                    continue;
                nex.x = cur.x + move[i][0];
                nex.y = cur.y + move[i][1];
                if(nex.x >= SIZ || nex.y >= SIZ)
                    continue;
                v = cost[cur.y][cur.x] + conn[i][cur.y][cur.x];
                if (v < cost[nex.y][nex.x]){
                    if (cost[nex.y][nex.x]!=-1){
                        lad[cost[nex.y][nex.x]].erase(nex);
                    }
                    cost[nex.y][nex.x] = v;
                    lad[v].insert(nex);
                    if (e < v) e = v;
                }
            }
        }
    }
    return -1;
}
int readIn(){
    int w, d;
    scanf("%d%d",&w,&d);
    if(w==-1 && d==-1) return 0;
    memset(conn, 0, sizeof(conn));
    memset(cost, -1, sizeof(cost));
    int i;
    for (i=0; i<SIZ*SIZ; ++i)
        lad[i].clear();
    int x,y,v,l;
    while(w --){
        scanf("%d%d%d%d",&x,&y,&v,&l);
        while(l--){
            if (v == 0){
                conn[D][y][x] = -1;
                conn[U][y-1][x] = -1;
                ++x;
            } else {
                conn[L][y][x] = -1;
                conn[R][y][x-1] = -1;
                ++y;
            }
        }
    }
    while(d --){
        scanf("%d%d%d",&x,&y,&v);
        if (v == 0){
            conn[D][y][x] = 1;
            conn[U][y-1][x] = 1;
        } else {
            conn[L][y][x] = 1;
            conn[R][y][x-1] = 1;
        }
    }
    float a, b;
    scanf("%f%f",&a,&b);
    dst.x = (unsigned short)a;
    dst.y = (unsigned short)b;
    return 1;
}
int main(){
    while(readIn() > 0){
        int v = fun();
        printf("%d\n", v);
    }
    return 0;
}
