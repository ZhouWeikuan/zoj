#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
enum {
    SIZ = 9,
};
int dir[4][2] = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1}
};
int nei[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
int mat[SIZ][SIZ];
bool vis[SIZ][SIZ];

inline bool valid(int r, int c){
    return (r>=0&&r<SIZ) && (c>=0&&c<SIZ);
}

// return color*10 + num;
int cnt(int r, int c, int dr, int dc){
    int ret = 0;
    int color = 0;
    r += dr, c += dc;
    while(valid(r,c) && mat[r][c]){
        if (color == 0){
            color = mat[r][c];
        } else if (color != mat[r][c]){
            break;
        }
        ++ret;
        r += dr, c += dc;
    }
    ret += color*10;
    return ret;
}

void mark(int r, int c, int color, int dr, int dc){
    r += dr, c += dc;
    while(valid(r,c)&&mat[r][c]==color){
        vis[r][c] = true;
        r += dr, c += dc;
    }
}

bool bfs(int r, int c, int color){
    vis[r][c] = true;
    queue<int> q;
    q.push(r*10+c);
    while(!q.empty()){
        c = q.front(); q.pop();
        r = c/10; c%=10;
        for (int i=0; i<4; ++i){
            int nr = r + nei[i][0];
            int nc = c + nei[i][1];
            if (!valid(nr,nc)||vis[nr][nc]) continue;
            if (mat[nr][nc] == color)
                return true;
            vis[nr][nc] = true;
            if (mat[nr][nc] == 0){
                q.push(nr*10 + nc);
            }
        }
    }
    return false;
}

bool check(int r, int c){
    for (int d=0; d<4; ++d){
        int a = cnt(r, c, dir[d][0], dir[d][1]);
        int b = cnt(r, c, -dir[d][0], -dir[d][1]);
        memset(vis, false, sizeof(vis));
        mark(r, c, a/10, dir[d][0], dir[d][1]);
        mark(r, c, b/10, -dir[d][0], -dir[d][1]);
        if (a/10 == b/10){
            if ((a%10 + b%10)>=4 && bfs(r, c, a/10))
                return true;
        } else {
            if (a%10 >= 4 && bfs(r,c,a/10)){
                    return true;
            } 
            if (b%10 >= 4 && bfs(r,c,b/10)){
                    return true;
            }
        }
    }
    return false;
}

bool fun(){
    for (int i=0; i<SIZ; ++i){
        for (int j=0; j<SIZ; ++j){
            if (mat[i][j]!=0) continue;
            if (check(i, j)){
                return true;
            }
        }
    }
    return false;
}

void readIn(){
    for (int i=0; i<SIZ; ++i){
        for (int j=0; j<SIZ; ++j){
            scanf("%d", &mat[i][j]);
        }
    }
}

int main(){
    const char *ans[2] = {"No", "Yes"};
    int gn;
    scanf("%d ", &gn);
    while(gn-- > 0){
        readIn();
        printf("%s\n", ans[fun()]);
    }

    return 0;
}

