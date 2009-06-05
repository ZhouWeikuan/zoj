#include<iostream>
#include<string>

using namespace std;
const double PI = 3.14159;

void fun(){
    double r,oil,ang;
    double need;
    cin>>r>>oil>>ang;
    if(ang > 180)
        ang = 360 - ang;
    ang *= PI;
    ang /= 180;
    r = 2 * ang * r;
    need = r / 5;
    if(need > oil){
        int t = int(oil * 5);
        cout<<"NO "<<t<<endl;
    } else {
        int t = int(oil - need);
        cout<<"YES "<<t<<endl;
    }
}

int main(){
    string s;

    cin>>s;
    while(s!="ENDOFINPUT"){
        fun();
        cin>>s;
        cin>>s;
    }

	return 0;
}
