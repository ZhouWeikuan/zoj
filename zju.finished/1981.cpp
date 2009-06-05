#include<iostream>
#include<iomanip>

using namespace std;
const double eps = 1e-6;

const double cw = 4.19, ci=2.09, em=335;
double water, ice;

void fun(){
    double dw,di;
    double sum = 0;
    double total = water + ice;
    double temp;
    cin>>dw>>di;

    sum += water * dw * cw;
    sum += ice * di * ci;
    sum -= ice * em;
    if(sum >= 0){
        temp = sum / total;
        temp /= cw;
        water = total;
        ice = 0;
    } else {
        temp = 0;
        sum = - sum;
        ice = sum / em;
        if(ice <= total){
            water = total - ice;
        } else {
            ice = total; water = 0;
            sum -= em * total;
            sum /= total;
            sum /= ci;
            temp = -sum;
        }
    }

    cout<<setiosflags(ios::fixed)<<setprecision(1);
    cout<<ice<<" g of ice and "<<water<<" g of water at "
        << temp<<" C"<<endl;
}


int main(){

    cin>>water>>ice;
    while(water + ice > 0){
        fun();
        cin>>water>>ice;
    }

	return 0;
}
