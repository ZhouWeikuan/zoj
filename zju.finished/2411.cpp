
#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 104,
    Lim = 3,
};
struct Node {
    int val;
    int dir;
};
int mat[SIZ][SIZ] = {0};
struct Point {
    int x,y;
};
int row,col;

int readin(){
    scanf("%d%d",&row, &col);
    if(row==0)
        return row;
    memset(mat, 0, sizeof(mat));
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    return row;
}
bool oneRow(int r, int s, int e){
    for(s++; s<e; s++){
        if(mat[r][s] != 0)
            return false;
    }
    return true;
}
bool oneCol(int c, int s, int e){
    for(s++; s<e; s++){
        if(mat[s][c] !=0)
            return false;
    }
    return true;
}
bool twoTry(int x, int y, int a, int b){
    if(x==a || y == b)
        return false;
    if(mat[x][b]== 0 
        && oneRow(x, min(y,b), max(y,b)) 
        && oneCol(b, min(x,a), max(x,a))){
        return true;
    }
    if(mat[a][y]==0 
        &&oneCol(y, min(x,a), max(x,a)) 
        && oneRow(a, min(y,b), max(y,b))){
        return true;
    }
    return false;
}
bool threeTry(int x, int y, int a, int b){
    int v;
    for(v=x-1; v>=0 && mat[v][y]==0; v--){
        if(twoTry(v,y,a,b)) return true;
    }
    for(v=x+1; v<=row+1 && mat[v][y]==0; v++){
        if(twoTry(v,y,a,b)) return true;
    }
    for(v=y-1; v>=0 && mat[x][v] ==0; v--){
        if(twoTry(x,v,a,b)) return true;
    }
    for(v=y+1; v<=col+1 && mat[x][v] ==0; v++){
        if(twoTry(x,v,a,b)) return true;
    }
    return false;
}

int trace(int x, int y, int a, int b){
    if(x==a && y == b)
        return Lim;
    if(mat[x][y] ==0 || mat[x][y] != mat[a][b]){
        return Lim;
    }
    int save = mat[x][y];
    mat[x][y] = mat[a][b] = 0;
    if(x == a && oneRow(x, min(y,b), max(y,b))){
        return 0;
    }
    if(y == b && oneCol(y, min(x,a), max(x,a))){
        return 0;
    }
    if(twoTry(x,y,a,b))
        return 1;
    if(threeTry(x,y,a,b))
        return 2;
    mat[x][y] = mat[a][b] = save;
    return Lim;
}

int fun(){
    int ret = 0;
    int x0,y0,x1,y1, n;
    int t;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
        t = trace(x0, y0, x1, y1);
        if( t <= 2){
            ret += 2;
        }
    }
    return ret;
}

int main(){

    while(readin() > 0){
        int t = fun();
        printf("%d\n", t);
    }

    return 0;
}

