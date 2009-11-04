#include<iostream>
#include<map>
using namespace std;
int Guess,Life;

map<int,int> table;
map<int,int>::iterator iter;
int fun(int g, int l){
	int key = (g<<16) + l;
	iter = table.find(key);
	if(iter != table.end()){
		return iter->second;
	}
	int ret;
	if(g==0){
		ret = 0;
		goto end;
	}
	if(l==0){
		ret = g;
		goto end;
	}
	ret = 1 + fun(g-1,l) + fun(g-1,l-1);
	
end:
	table[key] = ret;
	return ret;
}

int main(){
	int tstcase=0;
	cin>>Guess>>Life;
	while(Guess + Life){
		cout<<"Case "<<++tstcase<<": "<<fun(Guess,Life)<<endl;
		cin>>Guess>>Life;
	}

	return 0;
}
