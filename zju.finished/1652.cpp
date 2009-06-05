#include<iostream>

//Concrete mathematics has a similar example, buf for zig lines
// ZigZag(n) = Line(3*n) - 5*n;
// Line(n) = (n+1)*n/2 + 1;
// ZigZag(n) = n*(9*n-7)/2 + 1;
using namespace std;
int n;

void fun(){
    int ans = 9*n - 7;
    ans *=n;
    ans /= 2;
    ans += 1;
    cout<<ans<<endl;
}

int main(){
    
    while(cin>>n){
        fun();
    }

	return 0;
}
