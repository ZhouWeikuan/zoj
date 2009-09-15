#include<iostream>
#include<set>
#include<cstring>
using namespace std;
enum {
    SIZ = 54,
    N = 0, E = 1, S = 2, W = 3,
};

int mv[4][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

int getDir(char ch){
    ch = tolower(ch);
    return ch=='n'?N:(ch=='s'?S:(ch=='w'?W:E));
}

int Row, Col;
int mat[SIZ][SIZ];
unsigned step[4][SIZ][SIZ];
struct Node {
    unsigned char d, r, c;
    bool empty(){
        return mat[r-1][c-1]==0&&mat[r-1][c]==0&&mat[r][c-1]==0&&mat[r][c]==0;
    }
    bool valid(){
        return (r>=1&&c>=1)&&(r<Row&&c<Col);
    }
    bool operator < (const Node&o) const {
        if (step[d][r][c] != step[o.d][o.r][o.c])
            return step[d][r][c] < step[o.d][o.r][o.c];
        if (r!=o.r) return r < o.r;
        if (c!=o.c) return c < o.c;
        if (d!=o.d) return d < o.d;
    }
};

Node src, dst, nex;

void fun(){
    memset(step, -1, sizeof(step));
    step[src.d][src.r][src.c] = 0;
    set<Node> tab;
    tab.insert(src);
    while (!tab.empty()){
        src = *tab.begin(); tab.erase(tab.begin());
        if (src.r == dst.r && src.c == dst.c){
            printf("%u\n", step[src.d][src.r][src.c]);
            return;
        }
        // move forward
        int t;
        for (int i=1; i<=3; ++i){
            nex.d = src.d;
            nex.r = src.r + i*mv[src.d][0];
            nex.c = src.c + i*mv[src.d][1];
            if (!nex.valid() || !nex.empty())
                break;
            t = step[src.d][src.r][src.c] + 1;
            if (step[nex.d][nex.r][nex.c] > t){
                tab.erase(nex);
                step[nex.d][nex.r][nex.c] = t;
                tab.insert(nex);
            }
        }
        nex = src;
        // turn left
        for (int i=1; i<=3; ++i){
            nex.d = (src.d + 3*i)%4;
            t = step[src.d][src.r][src.c] + i;
            if (step[nex.d][nex.r][nex.c] > t){
                tab.erase(nex);
                step[nex.d][nex.r][nex.c] = t;
                tab.insert(nex);
            }
        }
        // turn right;
        for (int i=1; i<=3; ++i){
            nex.d = (src.d + i)%4;
            t = step[src.d][src.r][src.c] + i;
            if (step[nex.d][nex.r][nex.c] > t){
                tab.erase(nex);
                step[nex.d][nex.r][nex.c] = t;
                tab.insert(nex);
            }
        }
    }
    printf("-1\n");
}

int readIn(){
    if (scanf("%d%d", &Row, &Col) < 0)
        return 0;
    if (Row + Col == 0) return 1;
    for (int i=0; i<Row; ++i){
        for (int j=0; j<Col; ++j){
            scanf("%d", &mat[i][j]);
        }
    }
    int a, b;
    scanf("%d%d", &a, &b);
    src.r = a, src.c = b;
    scanf("%d%d", &a, &b);
    dst.r = a, dst.c = b;
    char ch[10];
    scanf("%s", ch); 
    src.d = getDir(ch[0]);
    return 1;
}

int main(){

    while(readIn() > 0){
        if (Row + Col)
            fun();
    }

    return 0;
}

