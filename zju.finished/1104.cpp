#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
enum {
    SIZ = 104,
};
float tree[SIZ][2];
const float g = 9.8/2;
float pi ;
float S;
int num;

void readIn(){
    int i;
    float py =0, px = 0;
    float y,x;
    cin>>py>>px;
    num--;
    for(i=0;i<num;i++){
        cin>>y>>x;
        if(y > py){
            py = y;
        }
        tree[i][0] = px;
        tree[i][1] = py;
        py = y;
        px += x;
    }
    S = px;
}

void fun(){
    float up = 0,left, t;
    for(int i=0;i<num;i++){
        t = tree[i][1] * g * S * S;
        t /= tree[i][0];
        t /= (S - tree[i][0]);
        t = sqrt(t);
        if(t > up)
            up = t;
    }
    left = g * S;
    left /= up;
    up = up * up + left * left;
    up = sqrt(up);
    t = acos(left/up);
    t *= 180;
    t /= pi;

    cout<<setiosflags(ios::fixed)<<setprecision(2)
        <<t<<" "<<up<<endl;

}

int main(){
    pi = asin(1.0) * 2;
    
    while(cin>>num){
        readIn();
        fun();
    }

	return 0;
}
