#include<iostream>

using namespace std;

int num;
int pred;

void fun(){
	int ret = 0;
	int next;

	while(num --){
		cin>>next;
		if(next > pred){
			ret += (next - pred) *(6 );
		} else if(next < pred){
			ret += (pred - next) *(4);
		}
		pred = next;

		ret += 5;
	}
	
	cout<<ret<<endl;

}

int main(){
	
	cin>>num;
	while(num ){
		pred = 0;
		fun();
		cin>>num;
	}
	return 0;
}
