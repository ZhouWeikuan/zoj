#include<iostream>

using namespace std;
double mon[20]={
	0,10,10,10,10,12,14,16,18,20.4,22.8,25.2,27.6,30,32,34,36
};
int num;

void fun(){
	double ret = 0;
	int t;
	if(num>16){
		t = (num-16)/8;
		ret += mon[8] * t;
		num -= t*8;
	}
	if(num >16){
		ret += mon[8];
		num -= 8;
	}
	ret += mon[num];
	if(num>8&& num<13){
		cout.setf(ios::fixed);
		cout.precision(1);
		cout<<ret<<endl;
	} else {
		t = (int)ret;
		cout<<t<<endl;
	}

}

int main(){

	cin>>num;
	while(num){
		fun();
		cin>>num;
	}
	return 0;
}
