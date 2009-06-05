#include<iostream>
#include<queue>
#include<set>
using namespace std;
enum {
    SIZ = 20,
};
struct Node{
    unsigned step;
    Node * link;
    char dir;
};
char move[4][2] = {
    {-1,0}, {1,0}, {0,-1}, {0,1}
};
char dir[5]="nswe";
int Row, Col;
char mat[SIZ][SIZ];
Node tree[SIZ][SIZ][SIZ][SIZ];
char ans[SIZ*SIZ*SIZ];
unsigned char sx, sy, bx, by;
unsigned char dx, dy;
void init(){
    int a, b, c, d;
    for(a=0; a<Row; a++){
        for(b=0; b<Col; b++){
            for(c=0; c<Row; c++){
                for(d=0; d<Col; d++){
                    tree[a][b][c][d].step = -1;
                    tree[a][b][c][d].link= NULL;
                }
            }
        }
    }
}
inline unsigned make(unsigned char a, unsigned char b, 
        unsigned char c, unsigned char d){
    return (a<<24)|(b<<16)|(c<<8)|d;
}
void unmake(unsigned s){
    sx = (s>>24)&0xff;
    sy = (s>>16)&0xff;
    bx = (s>> 8)&0xff;
    by = s      &0xff;
}
int traceback(Node *cur){
    int p=0;
    while(cur!=NULL){
        ans[p++] = cur->dir;
        cur = cur->link;
    }
    p--;
    return p;
}
void fun(){
    init();
    unsigned cur, nex;
    unsigned char nsx, nsy, nbx, nby, rsx, rsy;
    queue<unsigned> q;
    set<unsigned> s;
    unsigned step = -1;
    bool flag = false;
    int i;
    tree[sx][sy][bx][by].step = 0;
    tree[sx][sy][bx][by].link = 0;
    tree[sx][sy][bx][by].dir  = 0;
    cur = make(sx, sy, bx, by);
    q.push(cur);
    s.insert(cur);
    while(!q.empty()){
        cur = q.front(); q.pop();
        unmake(cur);
        if(bx == dx && by == dy){
            if(tree[sx][sy][bx][by].step < step){
                step = tree[sx][sy][bx][by].step;
                rsx = sx, rsy = sy;
            }
            flag = true;
        }
        s.erase(cur);
        for(i=0; i<4; i++){
            nsx = sx + move[i][0];
            nsy = sy + move[i][1];
            if(nsx>=Row||nsy>=Col||mat[nsx][nsy]!=0)
                continue;
            if(nsx == bx && nsy == by){ // push
                nbx = bx + move[i][0];
                nby = by + move[i][1];
                if(nbx>=Row||nby>=Col||mat[nbx][nby]!=0)
                    continue;
                if(tree[nsx][nsy][nbx][nby].step <= tree[sx][sy][bx][by].step)
                    continue;
                nex = make(nsx, nsy, nbx, nby);
                tree[nsx][nsy][nbx][nby].step = tree[sx][sy][bx][by].step + 1;
                tree[nsx][nsy][nbx][nby].link = &tree[sx][sy][bx][by];
                tree[nsx][nsy][nbx][nby].dir = toupper(dir[i]);
                if(s.find(nex) == s.end()){
                    s.insert(nex);
                    q.push(nex);
                }
            } else {// walk;
                if(tree[nsx][nsy][bx][by].step <= tree[sx][sy][bx][by].step)
                    continue;
                nex = make(nsx, nsy, bx, by);
                tree[nsx][nsy][bx][by].step = tree[sx][sy][bx][by].step;
                tree[nsx][nsy][bx][by].link = &tree[sx][sy][bx][by];
                tree[nsx][nsy][bx][by].dir = dir[i];
                if(s.find(nex) == s.end()){
                    s.insert(nex);
                    q.push(nex);
                }
            }
        }
    }
    if(flag == false){
        printf("Impossible.\n");
        return;
    }
    int p = traceback(&tree[rsx][rsy][dx][dy]);
    reverse(ans, ans+p);
    printf("%s\n", ans);
}
int readIn(){
    scanf("%d%d ", &Row, &Col);
    if(Row + Col ==0) return 0;
    int i, j;
    char ch;
    for(i=0; i<Row; i++){
        for(j=0; j<Col; j++){
            scanf("%c ", &ch);
            if(ch == '#'){
                mat[i][j] = -1;
            }else{
                mat[i][j] = 0;
                if(ch == 'S'){
                    sx = i, sy = j;
                } else if(ch == 'B'){
                    bx = i, by = j;
                } else if(ch == 'T'){
                    dx = i, dy = j;
                }
            }
        }
    }
    return 1;
}
int main(){
    int tst=0;
    while(readIn() > 0){
        printf("Maze #%d\n", ++tst);
        fun();
        printf("\n");
    }
    return 0;
}

