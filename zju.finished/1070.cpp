#include<iostream>
#include<cstdio>
#include<cmath>
/* 从网上抄到答案，原理未知 */
using namespace std;

double VS,R,C,w;
int num;

int main(){
	double t;
	cin>>VS>>R>>C>>num;
	C *= R;
	while(num--){
		cin>>w;
		t = sqrt(R*R + 1 /(w*C*w*C));
		t = VS * R / t;
		printf("%.3lf\n",t);
	}

	return 0;
}
