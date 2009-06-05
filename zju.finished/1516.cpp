#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 108,
};
int row, col;
char land[SIZ][SIZ];
struct Point {
    int x,y;
};
int move[4][2] = {
    {-1, 0},{1, 0},{0, -1},{0, 1}
};

int flood(Point o){
    int val[2] = {1, 0}, ind;
    Point n;
    land[o.x][o.y] = 1;
    queue<Point > q;
    q.push(o);
    while(!q.empty()){
        o = q.front(); q.pop();
        ind = 2 - land[o.x][o.y];
        for(int i=0; i<4; i++){
            n.x = o.x + move[i][0];
            n.y = o.y + move[i][1];
            if(land[n.x][n.y] == 0){
                land[n.x][n.y] = ind + 1;
                val[ind]++;
                q.push(n);
            }
        }
    }
    return min(val[0], val[1]);
}

void fun(){
    int i,j;
    int num = 0;
    Point o;
    for(i=1; i<=row; i++){
        for(j=1;j<=col;j++){
            if(land[i][j] == 0){
                o.x = i, o.y = j;
                num += flood(o);
            }
        }
    }

    printf("%d\n", num);
}
void readIn(){
    int i,j,num;
    for(i=1; i<=row; i++)
        for(j=1; j<=col; j++)
            land[i][j] = 0;
    for(i=1; i<=row; i++)
        land[i][col+1] = -1;
    for(j=1; j<=col; j++)
        land[row+1][j] = -1;
    scanf("%d", &num);
    while(num--){
        scanf("%d%d",&i,&j);
        land[i][j] = -1;
    }
}
int main(){
    memset(land, -1, sizeof(land));
    scanf("%d%d",&row,&col);
    while(row + col){
        readIn();
        fun();
        scanf("%d%d",&row,&col);
    }

    return 0;
}

