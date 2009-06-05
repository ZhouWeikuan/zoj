#include<iostream>
using namespace std;

struct Point {
    int x,y;
    bool operator ==(const Point &p) const {
        return x == p.x && y ==p.y;
    }
};
struct Window {
    int lx,ly;
    int gx,gy;
    int click;
    int mark; // bigger, fronter;
    bool full;
};
int N,H, X, Y;
int num, cnt;
Window win[6];
Point clk[32];

int readIn(){
    if(cin>>N>>H>>X>>Y){
        ;
    } else {
        return 0;
    }
    cnt = 0;
    for(int i=0;i<N;i++){
        cin>>win[i].lx>>win[i].gy
            >>win[i].gx>>win[i].ly;
        win[i].click = -100;
        win[i].mark = cnt++;
        win[i].full = false;
    }
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>clk[i].x>>clk[i].y;
    }
    return 1;
}

bool title(Window &w, Point &p){
    if(w.full){
        return p.y >= Y-H;
    }
    if(p.x < w.lx || p.x > w.gx)
        return false;
    return (p.y>=w.gy-H && p.y <=w.gy);
}
bool clicked(Window &w, Point &p){
    if(w.full)
        return true;
    if(p.x < w.lx || p.x > w.gx)
        return false;
    return (p.y>=w.ly && p.y<=w.gy);
}
bool check(Point &p, int &ret){
    ret = -1;
    bool tit = false;
    int m = -1;
    for(int i=0; i<N; i++){
        if(win[i].mark <= m){
            continue;
        }
        if(title(win[i], p) ){
            m = win[i].mark;
            ret = i;
            tit = true;
        } else if( clicked(win[i], p)){
            m = win[i].mark;
            ret = i;
            tit = false;
        }
    }
    return tit;
}

void fun(){
    bool tit; 
    int  no;
    bool first = true;
    for(int i=0;i<num;i++){
        tit = check(clk[i], no);
        if(first){
            cout<<no;
            first = false;
        } else {
            cout<<" "<<no;
        }
        if(tit){
            if(i-win[no].click == 1 && clk[i] == clk[i-1]){
                win[no].full = !win[no].full;
            } else {
                win[no].click = i;
            }
        }
        if(no >= 0){
            win[no].mark = cnt++;
        }
    }
}
int main(){

    while(readIn() > 0){
        fun();
        cout<<endl;
    }

    return 0;
}
