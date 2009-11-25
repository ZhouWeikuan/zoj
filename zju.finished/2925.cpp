#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
enum {
    SIZ = 504,
};
struct Node {
    unsigned r, c;
    char d;
};
int Row, Col;
const char *dir="NYEQSJWV";
int mv[8][2] = {
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1}
};
char mat[SIZ][SIZ];

int getDir(char c){
    for (int i=0; dir[i]; ++i){
        if (c==dir[i]) return i;
    }
    return -1;
}
bool valid(Node &o){
    return (o.r<Row&&o.c<Col);
}

void output(){
    for (int i=0; i<Row; ++i){
        printf("%s\n", mat[i]);
    }
}

void fun(){
    char d = 0;
    Node o, x;
    scanf("%u%u %c ", &o.r, &o.c, &d);
    --o.r, --o.c;
    o.d = getDir(d);
    mat[o.r][o.c] = d;
    queue<Node> q;
    q.push(o);
    while(!q.empty()){
        o = q.front(); q.pop();
        for (d=-1; d<=1; ++d){
            x.d = (o.d + d + 8) % 8;
            x.r = o.r + mv[x.d][0];
            x.c = o.c + mv[x.d][1];
            if (valid(x) && mat[x.r][x.c]=='X'){
                mat[x.r][x.c] = dir[x.d];
                q.push(x);
            }
        }
    }
    output();
}

int readIn(){
    if (scanf("%d%d ", &Row, &Col) < 0)
        return 0;
    for (int i=0; i<Row; ++i){
        scanf("%s ", mat[i]);
    }
    return 1;
}

int main(){
    int tn = 0;
    while(readIn() > 0){
        if (tn++) printf("\n");
        fun();
    }

    return 0;
}

