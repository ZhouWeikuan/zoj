#include<iostream>

using namespace std;

void fun(){
    int ans = 1;
    int t,n;
    cin>>n;
    while(n--){
        cin>>t;
        ans --;
        ans += t;
    }
    cout<<ans<<endl;
}

int main(){
    int tstcase;

    cin>>tstcase;
    while(tstcase --){
        fun();
    }

	return 0;
}
