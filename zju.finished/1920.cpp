#include<iostream>
#include<cctype>
using namespace std;
char buf[100];

int getChar(char c){
	if(c <='9' && c>='0'){
		c-='0';
	}else if(c <='z' && c >='a'){
		c -='a';
		c += 10;
	}else {
		c = -1;
	}
	return c;
}

int fun(){
	int base = 0;
	int ret,t = 0;
	int s = 0;
	int mark = 0;
	while(isdigit(buf[s])){
		base *= 10;
		base += getChar(buf[s]);
		s ++;
	}
	if(buf[s] ==0)
		return 1;
	do {
		if(base > 16 || base <= 0)
			return 0;
		ret = t = 0;
		if(buf[s] != '#')
			return 0;
		s ++;
		t = getChar(buf[s]);
		mark = s;
		while(t>=0 && t < base){
			ret *= base;
			ret += t;
			if(ret > 100)
				ret = 100;
			s ++;
			t = getChar(buf[s]);
		}
		if(t > base)
			return 0;
		if(buf[s] == '#')
			s++;
		else
			return 0;
		if(s - mark < 2)
			return 0;
		base = ret;
	} while(buf[s]!=0);
	return 1;
}

int main(){
	int tstcase,t;
	const char *ans[2] = {"no","yes"};
	cin>>tstcase;
	while(tstcase --){
		cin>>buf;
		t = fun();
		cout<<ans[t!=0]<<endl;
	}

	return 0;
}
