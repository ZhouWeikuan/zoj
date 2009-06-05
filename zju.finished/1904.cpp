#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int D,V;

double fun(){
	double ret;
	ret = D * D *D * M_PI;
	ret -= 6 * V;
	ret /= M_PI;
	ret = cbrt(ret);
	return ret;
}

int main(){
	double t;
	cin>>D>>V;
	while(D){
		t = fun();
		printf("%.3lf\n",t);
		cin>>D>>V;
	}

	return 0;
}
