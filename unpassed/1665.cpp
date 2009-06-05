#include<iostream>
#include<cmath>

int p, n;
struct Fact {
	int up;
	int down;
public:
	int operator<(Fact &rhs){
		return up * rhs.down < down *rhs.up;
	}
	int operator>(Fact &rhs){
		return up *rhs.down > down * rhs.up;
	}
};

using namespace std;
Fact low,high;

int gcd(int a , int b){
	int t;
	while(b != 0){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void fun(){
	double root = sqrt(p);
	bool sq;
	int t = (int)root;
	Fact f;
	low.down = high.down = 1;
	high.up = t + 1;
	if(t*t == p){
		low.up = t-1;
		sq = true;
	} else {
		low.up = t;
		sq = false;
	}
	for(f.down = 2; ;f.down++){
		t = f.up = (int)(f.down * root) - sq;
		if(f.up > n)
			break;
		while(gcd(f.up,f.down)!=1 && f.up > 0 && low<f){
			f.up --;
		}
		if(f.up >0 && low < f && gcd(f.up,f.down)==1){
			low.up = f.up ; low.down = f.down;
		}
		f.up = t + sq + 1;
		while(f.up <= n && high > f && gcd(f.up, f.down)!=1){
			f.up ++;
		}
		if(f.up <= n && gcd(f.up,f.down)==1 && high>f){
			high.up = f.up; high.down = f.down;
		}
	}
	cout<<high.up<<"/"<<high.down<<" "
		<<low.up<<"/"<<low.down<<endl;
}

int main(){
	
	cin>>p>>n;
	while(p && n){
		fun();
		cin>>p>>n;
	}

	return 0;
}
