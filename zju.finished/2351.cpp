#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
double Ka, old;
string sk,sold;
int m,n;

double conv(string &s){
    double ret;
    int i;
    char temp[40];
    strcpy(temp, s.c_str());
    for(i=0;temp[i]!='e';i++){
        ;
    }
    temp[i++] = 0;
    ret = atof(temp);
    double t = atof(temp+i);
    t = pow(10,t);
    ret *= t;
    return ret;
}
void fun(){
    Ka = conv(sk);
    old = conv(sold);
    double t = Ka + 4 * m * n * old;
    t *= Ka;
    t = sqrt(t);
    t -= Ka;
    t /= 2; t/= n;
    t = -log10(t);
    printf("%.3lf\n",t);
}

int main(){
    int tstblock;
    cin>>tstblock;
    while(tstblock --){
        cin>>sk>>sold>>m>>n;
        while(m+n){
            fun();
            cin>>sk>>sold>>m>>n;
        }
        if(tstblock !=0)
            cout<<endl;
    }

    return 0;
}
