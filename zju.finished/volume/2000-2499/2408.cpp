#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int num,N;
double dest;
const double eps = 1e-6;
double invest[13];

void readIn(){
    memset(invest, 0, sizeof(invest));
    int i,t ;
    for(i=0;i<num;i++){
        cin>>t;
        cin>>invest[t-1];
    }
    cin>>N>>dest;
}
inline double make(double v){
    int i;
    double ret = 0;
    for(i=0;i<N;i++){
        ret += invest[i];
        ret *= (1 + v);
    }
    return ret;
}

void fun(){
    static int tstcase = 1;
    double low = 0.0, high = 1.0;
    double rate = (low + high) / 2;
    double val;
    
    while(low < high){
        val = make(rate);
        if(fabs(val - dest) <= eps){
            break;
        } else if(val < dest){
            low = rate;
        } else {
            high = rate;
        }
        rate = (low + high)/2;
    }
    
    if(tstcase > 1){
        printf("\n");
    }
    printf("Case %d: %.5lf\n", tstcase++, rate);



}

int main(){
    
    while(cin>>num && num >= 0){
        readIn();
        fun();
    }
    
    return 0;
}
