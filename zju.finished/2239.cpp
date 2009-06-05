#include<iostream>

using namespace std;

int fun(int n){
	if(n<=2)
		return 1;
	int sub = 1;
	while(n > sub){
		n -= sub;
		sub <<=1;
	}
	n *= 2;
	n--;
	return n;
}
int readIn(){
	static char buf[10];
	cin>>buf;
	int ret = 0;
	ret = buf[0]-'0';
	ret *= 10 ;
	ret += buf[1] - '0';
	int left=buf[3] -'0';
	while(left--){
		ret *= 10;
	}
	return ret;
}

int main(){
	int n;
	while(n = readIn()){
		cout<<fun(n)<<endl;
	}
	return 0;
}
