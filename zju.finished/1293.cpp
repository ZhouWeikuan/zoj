#include<iostream>

using namespace std;

int num;
int compress(){
	int t = num>>1;
	t = num - t;
	return t;
}
int uuencode(){
	int t = num>>1;
	t += num&0x01;
	t += num;
	return t;
}
int split(){
	int t;
	int ret;
	ret = num/62;
	t = num %62;
	ret += t>0;

	return ret;
}

int putfloppy(){
	int t = num%30000;
	int ret = num/30000;
	ret += t>0;
	return ret;
}

void fun(){
	static int tstcase = 0;
	num = compress();
	num = uuencode();
	num = split();
	num = putfloppy();
	cout<<"File #"<<++tstcase<<endl;
	cout<<"John needs "<<num<<" floppies."<<endl;
}

int main(){
	
	cin>>num;
	while(num){
		fun();
		cout<<endl;
		cin>>num;
	}

	return 0;
}
