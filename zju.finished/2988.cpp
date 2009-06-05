#include<iostream>
#include<iomanip>
#include<string>
#include<map>
using namespace std;

map<string, double> tab;
map<string, string> conv;

void fun(){
    double v;
    string unit;
    cin>>v>>unit;
    v *= tab[unit];
    unit = conv[unit];
    cout<<fixed<<setprecision(4)<<v<<" "<<unit<<endl;
}

int main(){
    tab["kg"] = 2.2046;
    conv["kg"] = "lb";

    tab["lb"] = 0.4536;
    conv["lb"] = "kg";

    tab["l"] = 0.2642;
    conv["l"] = "g";

    tab["g"] = 3.7854;
    conv["g"] = "l";

    int num, tst=0;
    cin>>num;
    while(num--){
        cout<<++tst<<" ";
        fun();
    }

    return 0;
}

