#include<iostream>
#include<cmath>
// 注意负数的情况
using namespace std;
double p;
int init, step;

int fun(){
    double a,b;
    int i;
    for(i=32-init;i>1;i-=step){
        a = log10(p) / i;
        a = pow(10, a);
        int t = int(a);
        a = double(t);
        b = a + 1;
        if(pow(a,i) == p || pow(b,i) == p){
            break;
        }
    }
    cout<<i<<endl;
}

int main(){
    
    cin>>p;
    while(p){
        if(p < 0){
            init = 1; step = 2;
            p = -p;
        } else {
            init = 0, step = 1;
        }
        fun();
        cin>>p;
    }

	return 0;
}
