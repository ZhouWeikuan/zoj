#include<iostream>
#include<string>
#include<map>
#include<queue>

using namespace std;
struct Node {
	string ref;
	int age;
	int diff;
};
struct People {
	string name;
	int age;	
};

struct MyComp {
	int operator()(const People &a, const People &b){
		if(a.age != b.age)
			return a.age < b.age;
		return a.name > b.name;
	}
};

map<string, Node> table;

int calc(map<string, Node>::iterator it){
	if(it->second.age)
		return it->second.age;
	it->second.age = calc(table.find(it->second.ref))-it->second.diff;
	return it->second.age;
}

void fun(){
	map<string, Node>::iterator iter;
	for(iter = table.begin(); iter!=table.end();iter++){
		calc(iter);
	}
	iter = table.find("Ted");
	table.erase(iter);
	
	People p;
	priority_queue<People, vector<People>, MyComp> que;
	for(iter = table.begin(); iter!=table.end();iter++){
		p.name = iter->first;
		p.age = iter->second.age;
		que.push(p);
	}
	while(!que.empty()){
		const People &peo = que.top();
		cout<<peo.name<<" "<<peo.age<<endl;
		que.pop();
	}
}

void getinput(){
	Node one;
	string name;
	one.age=0;
	int num;
	cin>>num;
	while(num--){
		cin>>one.ref>>name>>one.diff;
		table[name] = one;
	}
	one.ref="";
	one.age = 100;
	table["Ted"] = one;
}
int main(){
	int tstcase,tstnum=0;
	cin>>tstcase;
	while(tstcase --){
		cout<<"DATASET "<<++tstnum<<endl;
		table.clear();
		getinput();
		fun();
	}

	return 0;
}
