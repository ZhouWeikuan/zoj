#include<iostream>
#include<cmath>

using namespace std;
int B,N;

int mypow(int a, int b){
    int ret = 1;
    while(b > 0){
        ret *= a;
        b --;
    }
    return ret;
}

int fun(){
    double t = log((double)B) / N;
    t = exp(t);
    int a = (int) t;
    int val = abs( mypow(a,N) - B);
    t = abs(mypow(a+1,N) - B);
    if(t < val){
        a ++;
    }
    return a;
}

int main(){
    
    cin>>B>>N;
    while(B + N){
        cout<<fun()<<endl;
        cin>>B>>N;
    }

	return 0;
}
