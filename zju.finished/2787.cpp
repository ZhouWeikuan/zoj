#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
using namespace std;
enum {
    SIZ = 44,
    N = 0, 
    W = 1,
    S = 2,
    E = 3,
    D = 4,
};
struct Left {
    int reset() { return W;}
    int getFirst(int d) {return (d + W)%D;}
    int getNext(int d) {return (d + D - 1)%D; }
};
struct Right {
    int reset() { return E; }
    int getFirst(int d) {return (d + E)%D;}
    int getNext(int d) {return (d + 1)%D; }
};

int move[4][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1},
};

struct Node {
    int r, c;
    bool operator != (const Node&o) const {
        return r!=o.r || c!=o.c;
    }
};

int mark[SIZ][SIZ];
char maze[SIZ][SIZ];
int row, col;
Node start, end;

bool isValid(const Node&o){
    return (o.r>=0&&o.r<row)&&(o.c>=0&&o.c<col);
}
bool isEmpty(const Node&o){
    return maze[o.r][o.c] == '.' || maze[o.r][o.c] == 'S' 
                || maze[o.r][o.c] == 'E';
}

template<typename Direct>
int FindPath(Direct& drt){
    int ret = 0, d = drt.reset();
    Node cur = start, nex;
    while(cur != end){
        d = drt.getFirst(d);
        nex.r = cur.r + move[d][0];
        nex.c = cur.c + move[d][1];
        while(!isValid(nex)||!isEmpty(nex)){
            d = drt.getNext(d);
            nex.r = cur.r + move[d][0];
            nex.c = cur.c + move[d][1];
        }
        cur = nex;
        ++ret;
    }
    return ret;
}

int shortPath(){
    memset(mark, -1, sizeof(mark));
    mark[start.r][start.c] = 0;
    queue<Node> q;
    q.push(start);
    Node cur, nex;
    while(mark[end.r][end.c] == -1){
        cur = q.front(); q.pop();
        for (int i=0; i<D; i++){
            nex.r = cur.r + move[i][0];
            nex.c = cur.c + move[i][1];
            if (isValid(nex) && isEmpty(nex) && mark[nex.r][nex.c] == -1){
                mark[nex.r][nex.c] = mark[cur.r][cur.c] + 1;
                q.push(nex);
            }
        }
    }
    return mark[end.r][end.c];
}

void fun(){
    Left l; Right r;
    int lv = FindPath(l) + 1;
    int rv = FindPath(r) + 1;
    int sv = shortPath() + 1;
    printf("%d %d %d\n", lv, rv, sv);
}

int readIn(){
    scanf("%d%d ", &col, &row);
    for(int i=0; i<row; ++i){
        scanf("%s ", maze[i]);
        for (int j=0; j<col; j++){
            if (maze[i][j] == 'S'){
                start.r = i, start.c = j;
            } else if (maze[i][j] == 'E'){
                end.r = i, end.c = j;
            }
        }
    }
    return 0;
}

int main(){
    int tst;

    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

