#include<iostream>

using namespace std;
enum {
    BS = 34,
    SIZ = 32,
};
char B_[BS][BS];
char B1[BS][BS];
char bitmap[SIZ][SIZ];
char buf[1024];
int move[4][2] = {
    /* 0,North */  {0, 1},
    /* 1,East  */  {1, 0},
    /* 2,South */  {0, -1},
    /* 3,West  */  {-1, 0}
};
int * getPos(char ch){
    switch(ch){
    case 'N':
        return move[0];
    case 'E':
        return move[1];
    case 'S':
        return move[2];
    }
    return move[3];
}

void sim(int x, int y){
    int *pos;
    memset(B_, 0 , sizeof(B_));
    memset(B1, 0 , sizeof(B1));
    cin>>buf;
    for(int i=0;buf[i]!='.';i++){
        pos = getPos(buf[i]);
        switch(buf[i]){
        case 'N':
            B1[x][y]   = 1;
            break;
        case 'S':
            B1[x][y-1] = 1;
            break;
        case 'E':
            B_[x][y]   = 1;
            break;
        default :
            B_[x-1][y] = 1;
            break;
        }
        x += pos[0];
        y += pos[1];
    }
}

inline int calc(int x, int y){
    int ret = 0;
    ret += B1[x][y];
    ret += B1[x+1][y];
    ret += B_[x][y];
    ret += B_[x][y+1];
    return ret;
}
// 1 , bound, 0 none
int leftBound(int x, int y){
    return B1[x][y] == 1;
}
int rightBound(int x, int y){
    return B1[x+1][y] == 1;
}
int lowBound(int x, int y){
    return B_[x][y] == 1;
}
int upBound(int x, int y){
    return B_[x][y+1] == 1;
}

void color(int x, int y){
    if(bitmap[x][y] != 0)
        return ;
    int t = calc(x,y);
    if(t < 1)
        bitmap[x][y] = '.';
    else {
        bitmap[x][y] = 'X';
    }
    
    if(x > 0 && leftBound(x,y)==0){
        color(x-1,y);
    }
    if(y > 0 && lowBound(x,y)==0){
        color(x,y-1);
    }
    if(x < SIZ-1 && rightBound(x,y)==0){
        color(x+1,y);
    }
    if(y < SIZ-1 && upBound(x,y)==0){
        color(x, y+1);
    }
}

void fun(){
    memset(bitmap, 0 , sizeof(bitmap));
    color(0,0); color(SIZ-1,0);
    color(0,SIZ-1); color(SIZ-1,SIZ-1);
    for(int j=SIZ-1;j>=0;j--){
        for(int i=0;i<SIZ;i++){
            if(bitmap[i][j] ==0)
                bitmap[i][j] = '.';
            cout<<bitmap[i][j];
        }
        cout<<endl;
    }
}

int main(){
    int tstcase=0, tstnum;
    int x,y;

    cin>>tstnum;
    while(tstcase++ < tstnum ){
        cout<<"Bitmap #"<<tstcase<<endl;
        cin>>x>>y;
        sim(x,y);
        fun();
        cout<<endl;
    }

	return 0;
}
