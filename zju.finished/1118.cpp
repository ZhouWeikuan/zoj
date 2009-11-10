#include<iostream>
#include<map>
#include<string>

using namespace std;

int num;
int dim;
int dot[1000];
map<string,int> table;
string fro, to;

int get_key(string &s){
	map<string,int>::iterator iter = table.find(s);
	if(iter!= table.end()){
		return iter->second;
	}
	table[s] = num;
	dot[num] = num;
	return num++;
}

int reachable(string &first, string &second){
	int i,ret = 0;
	int pos = first.length();
	for(i=0;i<pos;i++){
		ret += first[i]!= second[i];
		if(ret > 1)
			return 0;
	}
	return ret == 1;
}

int get_parent(int node){
	int p = dot[node];
	while(p != node){
		node = p;
		p = dot[node];
	}
	return p;
}
void combine(int a, int b){
	int pa = get_parent(a);
	int pb = get_parent(b);
	if(pa == pb){
		;
	} else if(pa < pb){
		dot[pb] = pa;
	} else {
		dot[pa] = pb;
		pa = pb;
	}
	dot[a] = pa;
	dot[b] = pa;
}
int travel(){
	int a = get_key(fro);
	int b = get_key(to);
	a = get_parent(a);
	b = get_parent(b);
	
	return a==b;
}

void get_end(string &key){
	key = "";
	int i,v;
	for(i=0;i<dim;i++){
		cin>>v;
		key += 'A' + v;
	}
}

int main(){
	string first,last;
	int value,i;
	int a,b;
	int tstcase = 0;
	
	cin>>dim;
	while(dim){
		table.clear();
		num = 0;
		get_end(fro);
		get_end(to);
		cin>>value;
		while(value != -1){
			first = last = "";
			first += 'A' + value;
			for(i=1;i<dim;i++){
				cin>>value;
				first += 'A' + value;
			}
			a = get_key(first);
			for(i=0;i<dim;i++){
				cin>>value;
				last += 'A' + value;
			}
			b = get_key(last);
			if(reachable(first,last))
				combine(a,b);
			cin>>value;
		}
		cout<<"Maze #"<<++tstcase <<" can";
		if(!travel()){
			cout<<"not";
		}
		cout<<" be travelled"<<endl;

		cin>>dim;
	}
	
	return 0;
}
