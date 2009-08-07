#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
// TLE
enum {
    SIZ = 504,
    LVL = 1004,
};
struct Node{
    unsigned short r, c;
};
int move[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
int row, col, day, mlvl;
int mat[SIZ][SIZ];
int mark[SIZ][SIZ];
vector<Node> lvl[LVL];
map<int, int> tab;

struct cmp {
    bool operator()(const Node&a, const Node&b) const {
        return mark[a.r][a.c] < mark[b.r][b.c];
    }
};

inline bool valid(Node &o){
    return o.r<row&&o.c<col;
}

void expand(Node o){
    queue<Node> q;
    q.push(o);
    Node x;
    while(!q.empty()){
        o = q.front(); q.pop();
        for (int i=0; i<4; ++i){
            x.r = o.r + move[i][0];
            x.c = o.c + move[i][1];
            if ((!valid(x)) || mat[x.r][x.c] >= 0) continue;
            if (mat[x.r][x.c] >= -day){
                mat[x.r][x.c] = mark[x.r][x.c] = mat[o.r][o.c];
                ++tab[mat[o.r][o.c]];
                q.push(x);
            } else if (mark[x.r][x.c] == 0) {
                mark[x.r][x.c] = mat[o.r][o.c];
                lvl[-mat[x.r][x.c]].push_back(x);
            } else if (mark[x.r][x.c] > mat[o.r][o.c]){
                mark[x.r][x.c] = mat[o.r][o.c];
            }
        }
    }
}

void trans(vector<Node>& cur){
    int i;
    for (i=0; i<cur.size(); ++i){
        Node o = cur[i];
        if (mat[o.r][o.c] > 0 || mat[o.r][o.c] < -day) 
            continue; // already infected
        mat[o.r][o.c] = mark[o.r][o.c];
        ++tab[mat[o.r][o.c]];
        expand(o);
    }
}

void fun(){
    cmp c;
    day = 1;
    for(day=0; day<mlvl; ++day){
        sort(lvl[day].begin(), lvl[day].end(), c);
        trans(lvl[day]);
    }
    int q, n;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        map<int, int>::iterator it=tab.find(n);
        if(it==tab.end()){
            printf("%d\n", 0);
        } else {
            printf("%d\n", it->second);
        }
    }
}

int readIn(){
    if(scanf("%d%d", &row, &col)<0)
        return 0;
    mlvl = 0;
    tab.clear();
    memset(mark, 0, sizeof(mark));
    Node o;
    int i,j;
    for (i=0; i<row; ++i){
        for (j=0; j<col; ++j){
            scanf("%d", &mat[i][j]);
            if (mat[i][j] < 0){
                mlvl = max(mlvl, -mat[i][j]);
            }
        }
    }
    ++mlvl;
    for (i=0; i<=mlvl; ++i){
        lvl[i].clear();
    }
    for (i=0; i<row; ++i){
        for (j=0; j<col; ++j){
            if (mat[i][j] > 0){
                o.r = i, o.c = j;
                lvl[0].push_back(o);
                mark[i][j] = mat[i][j];
                mat[i][j] = 0;
            }
        }
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

