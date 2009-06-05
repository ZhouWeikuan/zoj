#include<iostream>
#include<queue>
using namespace std;
// Wrong Answer
enum {
    SIZ = 10,
    MAS = 1<<SIZ,
    MaxN= 9999999,
};
struct Point{
    int x,y;
};
int stat[SIZ][MAS];
int path[SIZ][SIZ];
int ps[SIZ];
int pd[SIZ];
int score[MAS];
Point jew[10], src, dst;
int wid, hit, lim, num, tot;
char dun[52][52];
int step[52][52];
int move[4][2] = {
    {-1, 0},{1, 0},{0, -1},{0, 1}
};
struct Cmp{
    bool operator()(const Point&a, const Point&b){
        return stat[a.x][a.y] >= stat[b.x][b.y];
    }
};

int getStep(const Point &a, const Point &b){
    memset(step, -1, sizeof(step));
    Point one, nex;
    int i;
    queue<Point> q;
    q.push(a);
    step[a.x][a.y] = 0;
    while(!q.empty()){
        one = q.front(); q.pop();
        for(i=0; i<4; i++){
            nex.x = one.x+move[i][0];
            nex.y = one.y+move[i][1];
            if(dun[nex.x][nex.y] != 0) continue;
            if(step[nex.x][nex.y] != -1) continue;
            step[nex.x][nex.y] = step[one.x][one.y] + 1;
            if(nex.x == b.x && nex.y == b.y){
                return step[b.x][b.y];
            }
            q.push(nex);
        }
    }
    return MaxN;
}
void fun(){
    int t = getStep(src, dst);
    int i,j;
    Point one, nex;
    if(t > lim) {
        printf("Impossible\n");
        return;
    }
    t = 1<<num;
    for(i=0; i<num; i++){
        for(j=0; j<t; j++){
            stat[i][j] = MaxN;
        }
    }
    priority_queue<Point, vector<Point>, Cmp> q;
    for(i=0; i<num; i++){
        ps[i] = getStep(src, jew[i]);
        one.x = i; one.y=1<<i;
        stat[one.x][one.y] = ps[i];
        q.push(one);
        pd[i] = getStep(jew[i], dst);
    }
    for(i=0; i<num; i++){
        path[i][i] = MaxN;
        for(j=i+1;j<num;j++){
            t = getStep(jew[i], jew[j]);
            path[i][j] = path[j][i] = t;
        }
    }
    while(!q.empty()){
        one=q.top(); q.pop();
        if(stat[one.x][one.y] > lim){
            continue;
        }
        for(i=0; i<num; i++){
            if(one.y & (1<<i)){
                continue;
            }
            nex.x = i;
            nex.y = one.y|(1<<i);
            if(stat[nex.x][nex.y] > stat[one.x][one.y] + path[one.x][nex.x]){
                stat[nex.x][nex.y] = stat[one.x][one.y] + path[one.x][nex.x];
                q.push(nex);
            }
        }
    }
    tot = 0;
    t = 1<<num;
    for(i=0; i<num; i++){
        for(j=0;j<t;j++){
            if(stat[i][j] + pd[i] <= lim){
                if(tot < score[j])
                    tot = score[j];
            }
        }
    }
    printf("The best score is %d.\n", tot);
}
void readIn(){
    scanf("%d%d%d%d",&wid,&hit,&lim,&num);
    int t, i, j;
    static int p[SIZ];
    for(i=0; i<num; i++){
        scanf("%d", &p[i]);
    }
    t = 1<<num;
    for(i=0; i<t;i++)
        score[i] = -MaxN;
    queue<int> q;
    q.push(0);
    score[0] = 0;
    while(!q.empty()){
        t = q.front(); q.pop();
        for(i=0; i<num; i++){
            if(!(t & (1<<i))){
                j = t |(1<<i);
                if(score[j] == -MaxN){
                    score[j] = score[t] + p[i];
                    q.push(j);
                }
            }
        }
    }
    for(i=0; i<hit; i++){
        for(j=0; j<wid; j++){
            scanf(" %c ",&dun[i][j]);
            if(dun[i][j] == '*'){
                dun[i][j] = 1;
                continue;
            }
            if(dun[i][j] == '@'){
                src.x = i, src.y = j;
            } else if(dun[i][j] == '<'){
                dst.x = i, dst.y = j;
            } else {
                jew[dun[i][j] - 'A'].x = i;
                jew[dun[i][j] - 'A'].y = j;
            }
            dun[i][j] = 0;
        }
    }
}
int main(){
    int tstcase=0, tstnum;

    scanf("%d", &tstnum);
    while(tstnum--){
        if(tstcase++)
            printf("\n");
        printf("Case %d:\n", tstcase);
        readIn();
        fun();
    }

    return 0;
}

