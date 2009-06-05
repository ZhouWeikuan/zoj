#include<iostream>
#include<cmath>

using namespace std;

int fun(int n){
	double d = n;
	d *= log10(d);
	d -= floor(d);
	n = exp10(d);
	return n;
}

int main(){
	int n;

	while(cin>>n){
		cout<<fun(n)<<endl;
	}

	return 0;
}
