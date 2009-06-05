#include<iostream>

// 递归
using namespace std;
enum {
    SIZ = 800,
};
char buf[SIZ][SIZ];
int h[8];
int num;
void init(){
    h[1] = 1;
    for(int i=2;i<8;i++){
        h[i] = 3 * h[i-1];
    }
}
void write(int d, int x, int y){
    if(d == 1){
        buf[x][y] = 'X';
        return;
    }
    write(d-1, x, y); // left up
    write(d-1, x, y + 2 * h[d-1]); // right up
    write(d-1, x + h[d-1], y + h[d-1]); // center
    write(d-1, x + 2*h[d-1], y); // center
    write(d-1, x + 2*h[d-1], y + 2* h[d-1]); // center
}

void fun(){
    memset(buf, 0, sizeof(buf));
    write(num, 0, 0);
    int i,j;
    for(i=0;i<h[num]; i++){
        for(j=SIZ-1; buf[i][j]==0; j--){
            ;
        }
        for( ; j>=0 ;j --){
            if(buf[i][j] == 0)
                buf[i][j] = ' ';
        }
        cout<<buf[i]<<endl;
    }
    cout<<"-"<<endl;
}

int main(){
    init();
    cin>>num;
    
    while(num > 0){
        fun();
        cin>>num;
    }

	return 0;
}
