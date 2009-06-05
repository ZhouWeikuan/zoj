#include<iostream>
#include<string>
#include<cmath>
#include<set>
using namespace std;

const double g = 9.8;
double L,W,H;
double wei, speed;
int num;

bool test(){
    if(L < H) return false;
    speed = speed * speed - 2 * g * H;
    if(speed < 0) return false;
    speed = sqrt(speed);
    double s = L * L - (L-H)*(L-H);
    s = sqrt(s);
    if(s > W) return false;
    double v = speed * s / L;
    speed *= (L-H)/L;
    double t = 2 * v / g;
    s += speed * t;
    if(s < W) return false;
    return true;
}

void fun(){
    string name;
    set<string> tab;
    while(num--){
        cin>>name>>wei>>speed;
        if( test() ){
            tab.insert(name);
        }
    }
    cout<<tab.size()<<endl;
    for(set<string>::iterator it=tab.begin();
            it!=tab.end(); ++it){
        cout<<*it<<endl;
    }
}
int main(){

    while( cin>>num){
        cin>>L>>W>>H;
        fun();
    }

    return 0;
}

