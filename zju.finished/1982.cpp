#include<iostream>

using namespace std;
enum {
    N = 0,
    E = 1,
    S = 2,
    W = 3,
    Step = 10,
};
int Anext[4] = {E,S,W,N};
int Vnext[4] = {W,N,E,S};
int move[4][2] = {
    {0, Step},
    {Step, 0},
    {0, -Step},
    {-Step, 0}
};

int x,y;
int direct;
char buf[240];

void turn(char op){
    if(op == 'A'){
        direct = Anext[direct];
    } else {
        direct = Vnext[direct];
    }
    x += move[direct][0];
    y += move[direct][1];
    cout<<x<<" "<<y<<" lineto"<<endl;
}

void fun(){
    cout<<"300 420 moveto"<<endl
        <<"310 420 lineto"<<endl;
    direct = E;
    x = 310, y = 420;
    for(int i=0;buf[i];i++){
        turn(buf[i]);
    }
    cout<<"stroke"<<endl
        <<"showpage"<<endl;

}

int main(){

    while(cin>>buf){
        fun();
    }

	return 0;
}
