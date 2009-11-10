#include<iostream>
#include<vector>
using namespace std;
/*	注意奇偶数移的位置不同	*/
typedef unsigned long long ullong;
int disknum;
ullong step;

void calc(int n, ullong step, vector<int> &a, vector<int> &b, vector<int> &c){
	if(n <=0)
		return;
	ullong lim = 1llu << (n-1);
	if(step < lim){
		a.push_back(n);
		calc(n-1,step,a,c,b);
	} else {
		c.push_back(n);
		calc(n-1,step-lim,b,a,c);
	}
}

void print(const char *str, vector<int> &v){
	cout<<str;
	vector<int>::iterator i;
	if(v.size()==0)
		cout<<" ";
	for(i=v.begin(); i!=v.end();i++){
		cout<<" "<<*i;
	}
	cout<<endl;
}

int fun(){
    vector<int> A,B,C;
	
	if(disknum %2 == 1)
		calc(disknum,step,A,C,B);
	else 
		calc(disknum,step,A,B,C);
	print("A:", A);
	print("B:", B);
	print("C:", C);
}

int main(){
	int tstcase = 0;
	while(cin>>disknum>>step){			
		fun();
		cout<<endl;
	}
	
    return 0;
}
