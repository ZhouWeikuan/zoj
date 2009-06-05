#include<iostream>
#include<cmath>
using namespace std;
double PI;
double oxlen, oylen;
double x,y;
double xl,yl;
double ox,oy;
int level;
void init(){
    PI = 4 * atan(1.0);
    oylen = 85 * PI / 180;
    oylen /= 2;
    oylen += PI/4;
    oylen = tan(oylen);
    oylen = log(oylen);
    oylen /= 2;
    oxlen = PI;
    oxlen /= 2;
}
void fun(){
    cout<<"t";
    xl = oxlen; yl= oylen;
    ox = oy = 0;
    while(level--){
        if(x > ox){ // Left
            if(y > oy){ // up -- r
                cout<<"r";
                oy += yl;
            } else { // bot -- s
                cout<<"s";
                oy -= yl;
            }
            ox += xl;
        } else { // right
            if(y > oy){ // q
                cout<<"q";
                oy += yl;
            } else { // t
                cout<<"t";
                oy -= yl;
            }
            ox -= xl;
        }
        xl /= 2;
        yl /= 2;
    }
    cout<<endl;
}

void trans(){
    x *= PI;
    x /= 180;
    y *= PI;
    y /= 360;
    y += PI/4;
    y = tan(y);
    y = log(y);
}

int main(){
    init();

    while(cin>>x>>y>>level){
        trans();
        fun();
    }

    return 0;
}
