#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
const double eps = 1e-5;
double X1,Y1,r1;
double X2,Y2,r2;
double x,y;
void fun(){
	double dis = (X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2);
	dis = sqrt(dis);
	//等长或被包含 
	if(r1-r2 < eps || dis + r2 <= r1 + eps){
		printf("Impossible.\n");	
		return;
	}
	dis = r2/(r1-r2);
	x = dis*(X2-X1) + X2;
	y = dis*(Y2-Y1) + Y2;
	
	//防止打印出 -0.00 -0.00 
	if(x < eps)
		x = 0;
	if(y < eps)
		y = 0;
	printf("%.2lf %.2lf\n",x,y);
}

int main(){
	int tstcase;
	cin>>tstcase;
	while(tstcase --){
		cin>>X1>>Y1>>r1>>X2>>Y2>>r2;
		if(r1<r2){ // make sure r1>=r2
			x = X1; X1= X2; X2=x;
			y = Y1; Y1= Y2; Y2=y;
			x = r1; r1= r2; r2=x;
		}
		fun();
	}

	return 0;
}
