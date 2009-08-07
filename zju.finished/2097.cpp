#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
enum {
    SIZ = 8,
};

unsigned val[SIZ][SIZ];
unsigned cost[4][SIZ][SIZ];
struct Node {
    unsigned char r, c, s;
    bool operator<(const Node&o)const{
        return cost[s][r][c] < cost[o.s][o.r][o.c];
    }
};

Node fr, to;
int mv[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

inline bool valid(const Node&o){
    return o.r<SIZ&&o.c<SIZ;
}

void pop(vector<Node> &v){
    int p = 0, n = v.size();
    for (int i=0; i<n; ++i){
        if (v[i] < v[p]){
            p = i;
        }
    }
    --n;
    if (p!=n){
        swap(v[p], v[n]);
    }
}

void explore(const Node&cur, vector<Node>&vec){
    Node nex;
    unsigned v;
    for (int i=0; i<4; ++i){
        nex.r = cur.r + mv[i][0];
        nex.c = cur.c + mv[i][1];
        if (!valid(nex)) continue;
        v = val[nex.r][nex.c] * (cur.s+1);
        nex.s = v % 4;
        v += cost[cur.s][cur.r][cur.c];
        if (cost[nex.s][nex.r][nex.c] == -1){
            cost[nex.s][nex.r][nex.c] = v;
            vec.push_back(nex);
        }else if(cost[nex.s][nex.r][nex.c] > v){
            cost[nex.s][nex.r][nex.c] = v;
        }
    }
}

unsigned fun(){
    memset(cost, -1, sizeof(cost));
    cost[fr.s][fr.r][fr.c] = 0;
    vector<Node> vec;
    vec.push_back(fr);
    while(!vec.empty()){
        pop(vec);
        fr = vec.back();
        vec.pop_back();
        if (fr.r == to.r && fr.c == to.c){
            return cost[fr.s][fr.r][fr.c];
        }
        explore(fr, vec);
    }
    return -1;
}

int readIn(){
    unsigned r, c, a, b;
    scanf("%u%u%u%u", &r, &c, &a, &b);
    if (r+c+a+b == 0) return 0;
    fr.r = r - 1, fr.c = c - 1;
    to.r = a - 1, to.c = b - 1;
    fr.s = 0; to.s = 0;
    for (r=0; r<SIZ; ++r){
        for (c=0; c<SIZ; ++c){
            scanf("%u", &a);
            val[r][c] = a;
        }
    }
    return 1;
}

int main(){
    unsigned v;
    while(readIn() > 0){
        v = fun();
        printf("%u\n", v);
    }

    return 0;
}

