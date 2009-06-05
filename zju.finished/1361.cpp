#include<iostream>
#include<queue>
#include<ext/hash_set>
using namespace std;
using namespace __gnu_cxx;
enum {
    SX = 24,
    SY = 16,
    SM = 0x1f,
    SL = 0x03fff,
};
hash_set<int> tab;
struct Node {
    unsigned dis;
    unsigned mask;
};
int move[4][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};
int N, M, L;
int lake[8][2];
char lair[24][24];
Node one,nex;

inline int getX(int v){
    return (v>>SX)&SM;
}
inline int getY(int v){
    return (v>>SY)&SM;
}
void unpack(int m){
    lake[0][0] = getX(m);
    lake[0][1] = getY(m);
    int d, i;
    for(i=1; i<L; i++){
        d = (m>>((i-1)<<1))&0x3;
        lake[i][0] = lake[i-1][0] + move[d][0];
        lake[i][1] = lake[i-1][1] + move[d][1];
    }
}
int pack(){
    int m = 0, d;
    for(int i=1; i<L; i++){
        for(d=0; d<4; d++){
            if(lake[i-1][0] + move[d][0]==lake[i][0] 
                && lake[i-1][1] + move[d][1] == lake[i][1]){
                break;
            }
        }
        m |= d<<((i-1)<<1);
    }
    m |= (lake[0][0]<<SX);
    m |= (lake[0][1]<<SY);
    return m;
}
int fun(){
    int d, nx, ny, x, y, nd;
    queue<Node> q;

    tab.clear();
    one.dis  = 0;
    one.mask = pack();
    tab.insert(one.mask);
    q.push(one);
    while(!q.empty()){
        one = q.front(); q.pop();
        x = getX(one.mask);
        y = getY(one.mask);
        if(x==1 && y==1){
            return one.dis;
        }
        unpack(one.mask);
        nex.dis = one.dis+1;
        for(d=0; d<L; d++){
            lair[lake[d][0]][lake[d][1]] = 1;
        }
        for(d=0; d<4; d++){
            nx = x + move[d][0]; 
            ny = y + move[d][1]; 
            if(nx==0||nx>N||ny==0||ny>M||lair[nx][ny]==1){
                continue;
            }
            if(d<2) nd = d+2;
            else nd = d-2;
            nex.mask = ((one.mask&SL)<<2)+nd;
            nex.mask |= (nx<<SX);
            nex.mask |= (ny<<SY);
            if(tab.find(nex.mask)!=tab.end()){
                continue;
            }
            tab.insert(nex.mask);
            q.push(nex);
        }
        for(d=0; d<L; d++){
            lair[lake[d][0]][lake[d][1]] = 0;
        }
    }
    return -1;
}
int readIn(){
    scanf("%d%d%d", &N, &M, &L);
    if(N + M + L ==0) return 0;
    memset(lair, 0, sizeof(lair));
    int k, x, y;
    for(k=0; k<L; k++){
        scanf("%d%d", &lake[k][0], &lake[k][1]);
    }
    scanf("%d", &k);
    while(k--){
        scanf("%d%d",&x,&y);
        lair[x][y] = 1;
    }
    return (N+M+L);
}
int main(){
    int tst=0;
    while(readIn() > 0){
        printf("Case %d: %d\n", ++tst, fun());
    }
    return 0;
}

