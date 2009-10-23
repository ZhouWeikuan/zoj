#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
enum {
    ROW = 10,
    COL = 15,
};

int mark[COL][ROW];
char game[COL][ROW];
int ans;
int mv[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int r, int c){
    return (r>=0&&r<ROW)&&(c>=0&&c<COL);
}
int test(int idx, int r, int c){
    char color = game[c][r];
    int ret = 1;
    mark[c][r] = idx;
    queue<int> q;
    q.push((r<<16)|c);
    int nr, nc;
    while(!q.empty()){
        c = q.front(); q.pop();
        r = c>>16; c&=0xffff;
        for (int i=0; i<4; ++i){
            nr = r + mv[i][0];
            nc = c + mv[i][1];
            if (valid(nr,nc) && game[nc][nr]==color && mark[nc][nr]==0){
                mark[nc][nr] = idx;
                q.push((nr<<16)|nc);
                ++ret;
            }
        }
    }
    return ret;
}

bool good(int &row, int &col, int &sidx){
    int r, c, t, idx=1;
    ans = 0;
    memset(mark, 0, sizeof(mark));
    for (c=0;game[c][0]; ++c){
        for (r=0; r<ROW&&game[c][r]; ++r){
            if (mark[c][r]) continue;
            t = test(idx, r, c);
            if (t>=2 && t > ans){
                ans = t;
                row = r;
                col = c;
                sidx = idx;
            }
            ++idx;
        }
    }
    return ans;
}

void fill(int row, int col, int idx){
    int r, c, i, j;
    for (c=col; game[c][0]; ++c){
        j = 0;
        for (i=0; i<ROW; ++i){
            if (mark[c][i] == idx) continue;
            game[c][j++] = game[c][i];
        }
        while (j<ROW){
            game[c][j++] = 0;
        }
    }
    j=col;
    for (i=col; i<COL; ++i){
        if (game[i][0]==0) continue;
        memmove(game[j++], game[i], sizeof(game[0]));
    }
    while(j<COL){
        if (game[j][0]){
            memset(game[j], 0, sizeof(game[0]));
        }
        ++j;
    }
}

void fun(){
    int r, c;
    int score = 0;
    int t = 1;
    int left = ROW * COL;
    int idx;
    while(good(r, c, idx)){
        int pnt = (ans-2)*(ans-2);
        score += pnt;
        printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", 
                t++, r+1, c+1, ans, game[c][r], pnt);
        fill(r, c, idx);
        left -= ans;
    }
    if (left == 0){
        score += 1000;
    }
    printf("Final score: %d, with %d balls remaining.\n", score, left);
}

void readIn(){
    int r, c;
    char ch;
    for (r=ROW-1; r>=0; --r){
        for (c=0; c<COL; ++c){
            scanf(" %c", &ch);
            game[c][r] = ch;
        }
    }
}

int main(){
    int bn, gn, tn;
    scanf("%d", &bn);
    //bn = 1;
    while(bn-->0){
        scanf("%d", &gn);
        tn = 1;
        while(gn-- > 0){
            printf("Game %d:\n\n", tn++);
            readIn();
            fun();
            if(gn) printf("\n");
        }
        if (bn) printf("\n");
    }
    return 0;
}

