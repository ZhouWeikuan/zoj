#include<iostream>
#include<map>

//要求有高数度，用概率来算更好
using namespace std;
map<int,int> table;
map<int,int>::iterator iter;

int calc(int diff, int a, int b){
	if(a==0 && b==0)
		return 1;
	int key = (diff<<16	)+ (a<<8) + b;
	iter = table.find(key);
	if(table.end() != iter){
		return iter->second;
	}

	int ret = 0;
	if(diff > 0 && b > 0){
		ret += b * calc(diff-1,a,b-1);
	}
	if(a > 0){
		ret += a * calc(diff+1,a-1,b);
	}
	return ret;
}

int main(){
	int tstnum = 0;
	int a,b;

	cin>>a>>b;
	while(a + b){
		tstnum ++;
		cout<<"Test #"<<tstnum<<":"<<endl;
		if(a < b){
			cout<<0<<endl;
		} else {
			cout<<calc(0,a,b)<<endl;
		}
		cin>>a>>b;
	}

	return 0;
}
