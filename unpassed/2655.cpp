#include<iostream>
#include<cstring>
#include<set>
using namespace std;
enum {
    SIZ = 104,
    UP = 0,
    RT = 1,
    DN = 2,
    LT = 3,
};

int mv[4][2] = {
    {-1, 0}, {0,1}, {1, 0}, {0,-1}
};
int W, H, S, B;

char tab[SIZ][SIZ];
unsigned cost[4][SIZ][SIZ];
struct Node {
    unsigned char d, r, c;
    bool operator <(const Node &o)const{
        if (cost[d][r][c]!=cost[d][o.r][o.c])
            return cost[r][c] < cost[o.r][o.c];
        if (d!=o.d) return d < o.d;
        if (r!=o.r) return r < o.r;
        return c < o.c;
    }
};

inline bool valid(Node&o){
    return o.r<H&&o.c<=W&&tab[o.r][o.c]!='b';
}

void fun(){
    Node dst = {LT, H-1, 0};
    Node src = {LT, 0, W}, nex;
    memset(cost, -1, sizeof(cost));
    cost[src.d][src.r][src.c] = 0;
    set<Node> has;
    has.insert(src);
    unsigned c;
    if (tab[src.r][src.c] == 'b')
        goto NoAns;
    while(!has.empty()){
        src = *has.begin(); has.erase(has.begin());
        if (src.d == dst.d && src.r == dst.r && src.c == dst.c)
            break;
        for (int i=0; i<4; ++i){
            nex.d = i;
            nex.r = src.r + mv[i][0];
            nex.c = src.c + mv[i][1];
            c = cost[src.d][src.r][src.c] + (nex.d!=src.d?B:S);
            if (valid(nex) && cost[nex.d][nex.r][nex.c] > c){
                if (cost[nex.d][nex.r][nex.c] != -1)
                    has.erase(nex);
                cost[nex.d][nex.r][nex.c] = c;
                has.insert(nex);
            }
        }
    }
    if (cost[dst.d][dst.r][dst.c] == -1){
NoAns:
        printf("impossible\n");
    } else {
        printf("%u\n", cost[dst.d][dst.r][dst.c]);
    }
}

int readIn(){
    if (scanf("%d%d%d%d", &W, &H, &S, &B) < 0)
        return 0;
    memset(tab, 'b', sizeof(tab));
    for (int i=0; i<H; ++i){
        for (int j=1; j<=W; ++j){
            scanf(" %c", &tab[i][j]);
        }
    }
    tab[H-1][0] = '*';
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

