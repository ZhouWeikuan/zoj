#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string,int> tree[100000];
map<string,int>::iterator iter;
int treenum;

int insert(map<string, int> &t, string &s){
	iter = t.find(s);
	if(iter == t.end()){
		t[s] = treenum;
		return treenum++;
	}
	return iter->second;
}

void parse(string &s, int n){
	int pos;
	pos = s.find('\\');
	while(pos != string::npos){
		string one(s.begin(),s.begin()+pos);
		n = insert(tree[n],one);
		s.erase(s.begin(),s.begin()+pos+1);
		pos = s.find('\\');
	}
	insert(tree[n],s);
}

void print(int start,int n){
	map<string,int>::iterator iter;
	string s(start,' ');
	for(iter = tree[n].begin();iter!=tree[n].end(); iter++){
		cout<<s<<iter->first<<endl;
		if(iter->second !=-1){
			print(start+1,iter->second);
		}
	}
	tree[n].clear();
}

int main(){
	int tstcase,node;
	string str;
	
	cin>>tstcase;
	while(tstcase --){
		cin>>node;
		treenum= 1;
		while(node--){
			cin>>str;
			parse(str,0);
		}
		print(0,0);
		if(tstcase)
			cout<<endl;
	}

	return 0;
}
