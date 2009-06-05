#include<iostream>

using namespace std;

const int period = 21252;

int gcd(int x,int y){
	int t;
	if(x < y){
		t = x, x=y,y=t;
	}
	while(y){
		t = x%y;
		x = y;
		y = t;
	}
	return x;
}

int lcm(int a, int b, int c){
	int t = gcd(a,b);
	a *= b/t;
	t = gcd(a,c);
	a *= c/t;
	return a;
}

int getremind(int a, int d){
	 a%=d;
	 if(a < 0)
		 a +=d;
	 return a;
}

int main(){
	int ans;
	int a,b,c,d;
	int x,y,z,t;
	int left;
	int blocknum, tstcase;

	cin>>blocknum;
	while(blocknum --){
		tstcase = 0;
		
		cin>>a>>b>>c>>d;
		while(a!=-1){
			ans = d;
		
			x = getremind(ans-a ,23);
			y = getremind(ans-b,28);
			z = getremind(ans-c,33);
			while(x || y || z){
				left = 23 -x;
				y = 28 -y;
				if(left < y) left = y;
				z = 33 -z;
				if(left < z) left = z;
				ans += left;
				x = getremind(ans -a ,23);
				y = getremind(ans-b,28);
				z = getremind(ans-c,33);
			}
			if(ans <= d)
				ans += period;
			ans -= d;
		
			cout<<"Case "<<++tstcase<<": the next triple peak occurs in "
				<< ans <<" days."<<endl;
			cin>>a>>b>>c>>d;
		}
		if(blocknum)
			cout<<endl;
	}
	
	return 0;
}
