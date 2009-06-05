#include<iostream>
using namespace std;
// 主要是走路和吸取这两个动作
//  走时，可以到下一个矿的上下左右四个方向，因此使用DP
enum {
    SIZ = 1000,
    Max = 99999999,
};
struct Point{
    int x,y;
    int dis(const Point &r){
        int ret = 2;
        ret -= (x == r.x);
        ret -= (y == r.y);
        return ret;
    }
};
struct Rec {
    Point p;
    int cnt;
};
int num;
Point mine[SIZ];
int move[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
Rec tab[2][4];

void fun(){
    Rec *pre=tab[0], *cur=tab[1], *tmp;
    memset(pre, 0, sizeof(tab[0]));
    int d, t, v;
    for(int i=0; i<num; i++){
        for(d=0; d<4; d++){
            cur[d].p.x = mine[i].x + move[d][0];
            cur[d].p.y = mine[i].y + move[d][1];
            cur[d].cnt = Max;
            for(t=0; t<4; t++){
                v = 1 + cur[d].p.dis(pre[t].p) + pre[t].cnt;
                if(v < cur[d].cnt){
                    cur[d].cnt = v;
                }
            }
        }
        tmp=pre, pre=cur, cur=tmp;
    }
    v = Max;
    for(d=0; d<4; d++){
        if(v > pre[d].cnt){
            v = pre[d].cnt;
        }
    }
    printf("%d\n", v);
}

void readIn(){
    int op, d;
    static char str[20];
    Point cur;
    cur.x = cur.y = 0;
    num = d = 0;
    scanf("%d", &op);
    while(op--){
        scanf("%s", str);
        if(str[0] == 'F'){
            cur.x += move[d][0];
            cur.y += move[d][1];
        } else if(str[0] == 'S'){
            mine[num].x = cur.x + move[d][0];
            mine[num].y = cur.y + move[d][1];
            num++;
        } else {
            scanf("%s", str);
            if(str[0] == 'L'){ // left
                d = (d+3)%4;
            } else { // right
                d = (d+1)%4;
            }
        }
    }
}
int main(){
    int tst, t=0;
    scanf("%d", &tst);
    while(tst --){
        printf("Case %d:\n", ++t);
        readIn();
        fun();
        if(tst) printf("\n");
    }
    return 0;
}
