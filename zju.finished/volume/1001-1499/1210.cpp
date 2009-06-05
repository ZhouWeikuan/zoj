#include<iostream>
#include<cstring>

using namespace std;
//除以5相当于 除以10,再乘以2
//除以2也类似
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum(const char *);
	void mult(int );
	void div(int);
};
template<int N>
BigNum<N>::BigNum(const char *s){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
}
template<int N>
void BigNum<N>::mult(int m){
	int carry = 0;
	int i;
	for(i=0;i<len;i++){
		carry += d[i] * m;
		d[i] = carry % 10;
		carry /= 10;
	}
	while(carry){
		d[len++] = carry % 10;
		carry /= 10;
	}
}

template<int N>
void BigNum<N>::div(int dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		d[i] = carry / dm;
		carry = carry % dm;
	}
	while(d[--len] ==0){
		;
	}
	len ++;
}
enum {
	Size = 100,
};
char buf[Size];

void fun(){
	cout<<"1 / "<<buf<<" ="<<endl;
	cout<<"0.";
	int i = strlen(buf);
	int zero = 0;
	while(buf[--i] =='0'){
		zero++;
	}
	i++;
	buf[i] = 0;

	BigNum<100> s(buf), t("1");
	int m,d;
	if(s.d[0] ==5){
		d = 5, m = 2;
	} else {
		d = 2, m = 5;
	}
	while(s.d[0] != 1){
		s.div(d);
		t.mult(m);
		zero ++;
	}
	zero -= t.len;
	for(i=0;i<zero;i++)
		cout<<"0";
	for(i=t.len-1;i>=0;i--){
		cout<<t.d[i];
	}
	cout<<endl;
}

int main(){
	cout<<"Problem 4 by team x"<<endl;
	while(cin>>buf){
		cout<<endl;
		fun();
	}
	cout<<"End of problem 4 by team x"<<endl;
	return 0;
}
