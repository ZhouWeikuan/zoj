#include<iostream>
#include<map>
#include<vector>
using namespace std;
// TLE
enum {
    SIZ = 504,
};
struct Node{
    unsigned short r, c;
};
int move[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
int row, col, num, day;
int mat[SIZ][SIZ];
bool mark[SIZ][SIZ];
vector<Node> bnd;
map<int, int> tab;

inline bool valid(Node &o){
    return o.r<row&&o.c<col;
}

void operate(){
    int i, j;
    Node o;
    for (i=0; i<v.size(); ++i){
        for (j=0; j<4; ++j){
            o.r = v[i].r + move[j][0];
            o.c = v[i].c + move[j][1];
            if (!valid(o) || mat[o.r][o.c] > 0 || mat[o.r][o.c] < day){
                continue;
            }
            --num;
            mat[o.r][o.c] = type;
            v.push_back(o);
        }
    }
}

void trans(){
    day = -1;
    while(num > 0){
        for (it=tab.begin(); it!=tab.end(); ++it){
            operate(it->second, it->first);
        }

        --day;
    }
}

void fun(){
    trans();
    int n, t;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &t);
        printf("%d\n", tab[t].size());
    }
}

int readIn(){
    if(scanf("%d%d", &row, &col)<0)
        return 0;
    tab.clear();
    num = row * col;
    Node o;
    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            scanf("%d", &mat[i][j]);
            if (mat[i][j] > 0){
                --num;
                o.r = i, o.c = j;
                tab[mat[i][j]].push_back(o);
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

