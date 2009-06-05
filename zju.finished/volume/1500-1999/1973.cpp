#include<iostream>

using namespace std;
struct Point {
    double x,y;
};
int num;

void fun(){
    Point a, pred, cur;
    double t;
    cin>>a.x>>a.y;
    pred = a;
    cout<<num<<" ";
    for(int i=1;i<num;i++){
        cin>>cur.x>>cur.y;
        t = cur.x + pred.x;
        t /= 2;
        cout.setf(ios::fixed);
        cout.precision(6);
        cout<<t<<" ";
        t = cur.y + pred.y;
        t /= 2;
        cout.setf(ios::fixed);
        cout.precision(6);
        cout<<t<<" ";
        pred = cur;
    }
    t = a.x + pred.x;
    t /= 2;
    cout.setf(ios::fixed);
    cout.precision(6);
    cout<<t<<" ";
    t = a.y + pred.y;
    t /= 2;
    cout.setf(ios::fixed);
    cout.precision(6);
    cout<<t<<endl;

}

int main(){
    
    while(cin>>num){
        fun();
    }

	return 0;
}
