#include<iostream>

using namespace std;
const double g = 9.81;
double k,l,s,w;

int fun(){
    double a,b;
    if(s < l){
        a = 2 * g * s;
    } else {
        a = 2 * g * s - k *(s-l)*(s-l)/w;
    }
    // compute the length when v is zero, if too high, then die
    if(a < 0)
        return 0;
    if(a >= 100)
        return 1;

    // compute the v when he reach the ground, when too high, then die

    return 2;
}

int main(){
    int t;
    const char *ans[3] ={
        "Stuck in the air.",
        "Killed by the impact.",
        "James Bond survives."
    };
    cin>>k>>l>>s>>w;
    while(k+w+l+s){
        t = fun();
        cout<<ans[t]<<endl;
        cin>>k>>l>>s>>w;
    }

	return 0;
}
