#include<iostream>
#include<map>

using namespace std;
char buf[40];
int dig[6];
int fact[6] = {
	100000,
	10000,
	1000,
	100,
	10,
	1
};
map<int,int> table;
map<int,int>::iterator iter;

int calc(int s, int key){
	int i,t;
	if(s > 31){
		return 1; //当前人赢
	}
	iter = table.find(key);
	if(iter != table.end()){
		return iter->second;
	}
	for(i=0;i<6;i++){
		if(dig[i] <=0)
			continue;
		dig[i] --;
		t = i + 1;
		t = calc(s + t, key - fact[i]);
		dig[i] ++;
		if(t == 0){
			return table[key] = 1;
		}
	}
	return table[key] = 0;
}

int fun(){
	int i,p=0,t;
	int sum=0 ,key=444444;
	for(i=0;buf[i];i++){
		t = buf[i] -'0';
		sum += t;
		t --;
		dig[t] --;
		key -= fact[t];
		p = 1 - p;
	}
	t = calc(sum,key);

	if(t == 0){
		return 1-p;	
	}
	return p;
}
char ans[2] = {'A','B'};
int main(){
	int t;
	while(cin.getline(buf,40)){
		for(t=0;t<6;t++){
			dig[t] = 4;
		}
		cout<<buf;
		t = fun();
		cout<<" "<<ans[t]<<endl;
	}
	
	return 0;
}
