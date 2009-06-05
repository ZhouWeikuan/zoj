#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
};
int mark[SIZ][SIZ];
int S,x,y,dx,dy;

int readIn(){
    cin>>S>>x>>y>>dx>>dy;
    if(S == 0)
        return 0;
    memset(mark, 0, sizeof(mark));
    return 1;
}

void fun(){
    int mx = 0, my=   0;
    int loop    =   0;
    int tx,ty;
    for(;;){
        tx = x / S;
        ty = y / S;
        mx += tx;
        my += ty;
        x %= S;
        y %= S;
        if( (mx + my) % 2 != 0 && x && y){
            x += mx * S;
            y += my * S;
            cout<< "After " <<loop
                << " jumps the flea lands at ("
                <<x << ", " << y << ")."<<endl;
            return;
        }
        if(mark[x][y] != 0){
            break;
        }
        mark[x][y] = 1;
        x += dx;
        y += dy;
        loop++;
    }
    cout<<"The flea cannot escape from black squares."<<endl;
}

int main(){
    
    while( readIn() > 0 ){
        fun();
    }

    return 0;
}

