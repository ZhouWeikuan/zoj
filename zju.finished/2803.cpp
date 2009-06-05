#include<iostream>
using namespace std;
enum {
    SIZ = 108,
    N = 0,
    E = 1,
    S = 2,
    W = 3,
};
int move[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
int mat[SIZ][SIZ];
int Height, Width;
int num, op;

struct Robot {
    int x;
    int y;
    int d;
    bool check(){
        if(x < 1 || y < 1 || x > Width || y > Height)
            return true;
        return false;
    }
    void inline adjust(){
        if(d < 0){
            d += 4;
        } else if(d > W){
            d -= 4;
        }
    }
    int turnLeft(){
        --d;
        adjust();
        return 0;
    }
    int turnRight(){
        ++d;
        adjust();
        return 0;
    }
    int forward(){ // -1, wall 0, nothing,  other, robot id
        int t = mat[x][y];
        mat[x][y] = -1;
        x += move[d][0];
        y += move[d][1];
        if(check())
            return -1;
        if(mat[x][y] != -1){
            return mat[x][y];
        }
        mat[x][y] =  t;
        return 0;
    }
};

Robot tree[SIZ];

void readIn(){
    memset(mat, -1, sizeof(mat));
    cin >>Width >>Height;
    cin >>num   >>op;
    char ch;
    int t;
    for(int i=1; i<=num; i++){
        cin>>tree[i].x>>tree[i].y>>ch;
        switch(ch){
        case 'N':
            t = N; break;
        case 'E':
            t = E; break;
        case 'S':
            t = S; break;
        case 'W':
            t = W; break;
        }
        tree[i].d = t;
        mat[tree[i].x][tree[i].y] = i;
    }
}

void fun(){
    int cur, dest, loop;
    char ch;
    int i;
    for(i=0; i<op; i++){
        cin>>cur>>ch>>loop;
        while(loop --){
            if(ch == 'L'){
                tree[cur].turnLeft();
            } else if(ch == 'R'){
                tree[cur].turnRight(); 
            } else { // F
                dest = tree[cur].forward();
                if(dest == -1){
                    goto wall;
                } else if(dest > 0){
                    goto crash;
                }
            }
        }
    }
ok:
    cout<<"OK"<<endl;
    return;
wall:
    cout<<"Robot "<< cur << " crashes into the wall"<<endl;
    goto end;
crash:
    cout<<"Robot "<< cur << " crashes into robot "
        <<dest<<endl;
end :
    for( i++ ; i<op; i++){
        cin>>cur>>ch>>loop;
    }
}

int main(){
    int tstcase;

    cin>>tstcase;
    while(tstcase --){
        readIn();
        fun();
    }

    return 0;
}
