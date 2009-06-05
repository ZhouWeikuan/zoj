#include<iostream>
#include<map>
#include<set>
// 使用的是动态规划 
using namespace std;
enum {
	N = 44,
};
int pile[4][N];
int num;
map<unsigned,int> table;
map<unsigned,int>::iterator iter;
set<int> pocket;

int fun(int a,int b,int c,int d){
	unsigned key = (a<<24) + (b<<16) + (c<<8) + d;
	iter = table.find(key);
	if(iter != table.end()){
		return iter->second;
	}
	int ret = 0,t;
	if(a < num){
		t = pile[0][a];
		if(pocket.find(t)!=pocket.end()&& pocket.size()<=4){
			pocket.erase(t);
			ret = 1 + fun(a+1,b,c,d);
			pocket.insert(t);
		} else if(pocket.size() < 5){
			pocket.insert(t);
			ret = fun(a+1,b,c,d);
			pocket.erase(t);
		} 
	}
	if(b < num){
		int tmp = 0;
		t = pile[1][b];
		if(pocket.find(t) != pocket.end() && pocket.size() <=4){
			pocket.erase(t);
			tmp = 1 + fun(a,b+1,c,d);
			pocket.insert(t);
		} else if(pocket.size() < 5){
			pocket.insert(t);
			tmp = fun(a,b+1,c,d);
			pocket.erase(t);
		}
		if(ret < tmp)
			ret = tmp;
	}
	if(c < num){
		int tmp = 0;
		t = pile[2][c];
		if(pocket.find(t) != pocket.end() && pocket.size() <= 4){
			pocket.erase(t);
			tmp = 1 + fun(a,b,c+1,d);
			pocket.insert(t);
		} else if(pocket.size() < 5){
			pocket.insert(t);
			tmp = fun(a,b,c+1,d);
			pocket.erase(t);
		}
		if(ret < tmp)
			ret = tmp;
	}
	if(d < num){
		int tmp = 0;
		t = pile[3][d];
		if(pocket.find(t) != pocket.end() && pocket.size() <= 4){
			pocket.erase(t);
			tmp = 1 + fun(a,b,c,d+1);
			pocket.insert(t);
		} else if(pocket.size() < 5){
			pocket.insert(t);
			tmp = fun(a,b,c,d+1);
			pocket.erase(t);
		}
		if(ret < tmp)
			ret = tmp;
	}

	return table[key] = ret;
}

int main(){
	int i;
	cin>>num;
	while(num){
		table.clear();
		pocket.clear();
		for(int i=0;i<num;i++){
			cin>>pile[0][i]>>pile[1][i]>>pile[2][i]>>pile[3][i];
		}
		num = fun(0,0,0,0);
		cout<<num<<endl;
		cin>>num;
	}
	
	return 0;
}
