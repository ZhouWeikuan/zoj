#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
// Wrong Answer
enum {
    SIZ = 10,
    UP = 0,
    RT = 1,
    DN = 2,
    LT = 3,
};
// /->0, \->1
struct Node{
    unsigned s :16;
    unsigned x :8;
    unsigned y :8;
};
unsigned N, M, mCnt, bCnt;
Node mir[SIZ];
Node bat[SIZ*SIZ];
Node start, end;
unsigned step[1<<SIZ][SIZ][SIZ];
char lab[1<<SIZ][SIZ][SIZ]; // 0 for available
char mat[SIZ][SIZ];
char dir[] = "^>v<";
int move[4][2] = {
    /*UP*/{-1,0}, /*RT*/{0,1}, /*DN*/{1,0}, /*LT*/{0,-1}
};
inline bool valid(unsigned x, unsigned y){
    return (x<N)&&(y<M);
}

void fun(){
    memset(step, -1, sizeof(step));
    step[start.s][start.x][start.y] = 0;
    queue<Node> q;
    q.push(start);
    Node nex;
    unsigned mask, i;
    while(!q.empty()){
        start = q.front(); q.pop();
        if(start.x == end.x && start.y == end.y){
            mask = step[start.s][start.x][start.y];
            printf("%u\n", mask);
            return;
        }
        // for bit
        nex = start;
        for(i=0, mask=1; i<mCnt; i++, (mask<<=1)){
            if(start.s & mask){
                nex.s = start.s & ~mask;
            } else {
                nex.s = start.s | mask;
            }
            if(lab[nex.s][nex.x][nex.y]!=0)
                continue;
            if(step[nex.s][nex.x][nex.y] > step[start.s][start.x][start.y] + 1){
                if (step[nex.s][nex.x][nex.y] == -1)
                    q.push(nex);
                step[nex.s][nex.x][nex.y] = step[start.s][start.x][start.y] + 1;
            }
        }
        // directory
        nex = start;
        for(i=0; i< 4; i++){
            nex.x = start.x + move[i][0];
            nex.y = start.y + move[i][1];
            if(!valid(nex.x, nex.y) || lab[nex.s][nex.x][nex.y]!=0)
                continue;
            if(step[nex.s][nex.x][nex.y] > step[start.s][start.x][start.y] + 1){
                if (step[nex.s][nex.x][nex.y] == -1)
                    q.push(nex);
                step[nex.s][nex.x][nex.y] = step[start.s][start.x][start.y] + 1;
            }

        }
    }
    printf("poor\n");
}
void trace(Node b, char (*p)[SIZ]){
    int d;
    for(d=0; dir[d]!=mat[b.x][b.y]; d++);
    p[b.x][b.y] = 2;
    b.x += move[d][0];
    b.y += move[d][1];
    while(valid(b.x, b.y)){
        if(mat[b.x][b.y] == '.'){
            p[b.x][b.y] = 2;
        } else if(mat[b.x][b.y] == '/'){
            switch(d){
            case UP: d = RT; break;
            case DN: d = LT; break;
            case LT: d = DN; break;
            case RT: d = UP; break;
            }
        } else if(mat[b.x][b.y]=='\\'){
            switch(d){
            case UP: d = LT; break;
            case DN: d = RT; break;
            case LT: d = UP; break;
            case RT: d = DN; break;
            }
        } else { // bat or block
            return;
        }
        b.x += move[d][0];
        b.y += move[d][1];
    }
}
void setup(unsigned state){
    unsigned i,j;
    j = state;
    for(i=0; i<mCnt; i++){
        if(state & 0x01){
            mat[mir[i].x][mir[i].y] = '\\';
        } else {
            mat[mir[i].x][mir[i].y] = '/';
        }
        state >>= 1;
    }
    state = j;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(mat[i][j] == '.')
                lab[state][i][j] = 0;
            else
                lab[state][i][j] = 1;
        }
    }
    for(i=0; i<bCnt; i++){
        trace(bat[i], lab[state]);
    }
    for(i=0; i<mCnt; i++){
        lab[state][mir[i].x][mir[i].y] = 2;
    }
}
int readIn(){
    if(scanf("%d%d",&N,&M)<0)
        return 0;
    unsigned i,j;
    bCnt = mCnt = 0;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            scanf(" %c", &mat[i][j]);
            if(mat[i][j] == 'S'){
                start.x = i; start.y = j;
            } else if(mat[i][j] == 'v'||mat[i][j]=='^'
                    ||mat[i][j] == '<'||mat[i][j]=='>'){
                bat[bCnt].x = i;
                bat[bCnt].y = j;
                bCnt ++;
            } else if(mat[i][j] == '/'||mat[i][j] == '\\'){
                mir[mCnt].x = i; mir[mCnt].y = j;
                mCnt++;
            } else if(mat[i][j] == 'E'){
                end.x = i; end.y = j;
            }
        }
    }
    mat[start.x][start.y] = '.';
    mat[end.x][end.y] = '.';
    j = 0;
    for(i=mCnt-1; i<mCnt; --i){
        j *= 2;
        j += (mat[mir[i].x][mir[i].y] == '\\');
    }
    start.s = j;
    j = 1<<mCnt;  
    for(i=0; i<j; i++){
        setup(i);
    }
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

