#include<iostream>
#include<cmath>

using namespace std;
int num;

int fun(){
	int p,s = 0;
	int v = 0;
	double t;
	while(num--){
		cin>>p>>s;
		if(s < 0){
			continue;
		}
		t = 4.5 / p;
		t *= 3600;
		t += s;
		if(v ==0){
			v = ceil(t);
		} else {
			s = ceil(t);
			if(v > s){
				v = s;
			}
		}
	}
	return v;
}

int main(){
	
	cin>>num;
	while(num){
		cout<<fun()<<endl;

		cin>>num;
	}

	return 0;
}
