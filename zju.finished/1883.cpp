#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
enum {
    SIZ = 104,
};
double d[SIZ][10];
int k,n;

double fun(){
    int i,j;
    if(k==0)
        return 100.0;
    for(i=1;i<n;i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        for(j=1;j<k;j++){
            d[i][j] = d[i-1][j-1] + d[i-1][j] + d[i-1][j+1];
        }
        if(k)
            d[i][k] = d[i-1][k] + d[i-1][k-1];
    }
    double s = 0;
    for(i=0;i<=k;i++){
        s += d[n-1][i];
    }
    s *= 100;
    s /= pow(double(k+1), (double)n);
    return s;
}


int main(){
    for(int i=0;i<10;i++){
        d[0][i] = 1;
    }
    
    while(cin>>k>>n){
        cout<<setiosflags(ios::fixed)<<setprecision(5)<<fun()<<endl;
    }

	return 0;
}
