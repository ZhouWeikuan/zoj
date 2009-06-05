#include<iostream>
#include<map>
using namespace std;
map<string,int> table ;
const char Max = 'z';

void add(string & s){
	int cur = s.length() -1;
	int i = cur;
	s[i]++;
	if(s[i] <= Max -cur + i)
		return;
	while(s[i] > Max - cur + i){
		i--;
		if(i <0)
			break;
		s[i] ++;
	}
	if( i < 0){
		
		for(i=0;i<=cur;i++){
			s[i] = 'a' + i;
		}
		s.push_back((char)(s[cur]+1));
		return;
	}
	for(;i<cur;i++){
		s[i+1] = s[i] + 1;
	}
}

void init(){
	int num = 1;
	string s = "a";
	do{
		table[s] = num++;
		add(s);
	}while(num <= 83681);
}

int main(){
	string s;
	init();
	map<string,int>::iterator iter;
	while(cin>>s){
		iter = table.find(s);
		if(iter == table.end()){
			cout<<0<<endl;
		} else {
			cout<<iter->second<<endl;
		}
	}
	
	return 0;
}
