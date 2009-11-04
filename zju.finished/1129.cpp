#include<iostream>
#include<set>
#include<map>
#include<string>
#include<vector>

using namespace std;
char buffer[280];
int paper, query;
int num;
map<int, set<int> > table;
map<int, int> erdos;
map<string, int> Index;

void init(){
	string s="Erdos, P.";
	table.clear(); erdos.clear(); Index.clear();

	num = 0;
	Index[s] = num;
	erdos[0] = 0;
	num++;
}

int get_Index(string &s){
	map<string, int>::iterator iter;
	iter = Index.find(s);
	if(iter != Index.end())
		return iter->second;
	Index[s] = num;
	return num++;
}

void parse(){
	vector<int> author;
	int i,last =0 ;
	int key;
	while(1){
		for(i=last; buffer[i] != ',';i++){
			;
		}
		i++;
		for(;buffer[i] != ',' && buffer[i] !=':';i++)
			;
		string str(buffer+last, buffer+i);
		key = get_Index(str);
		author.push_back(key);
		if(buffer[i] ==':')
			break;
		last = i+2;
	}
	for(i=0;i<author.size();i++){
		for(last=0;last<author.size();last++){
			table[author[i]].insert(author[last]);
		}
	}
}

void do_query(){
	string str(buffer);
	int key = get_Index(str);
	map<int,int>::iterator iter = erdos.find(key);
	if(iter == erdos.end()){
		cout<<buffer<<": "<<"infinity"<<endl;
		return;
	}
	cout<<buffer<<": "<<iter->second<<endl;
}

void assign_value(){
	int from;
	int low;
	set<int> update;
	update.insert(0);
	while(update.size()){
		from = *(update.begin());
		update.erase(from);
		set<int> &s = table[from];
		set<int>::iterator iter;
		map<int,int>::iterator v;
		low = erdos[from] + 1;
		for(iter = s.begin(); iter!=s.end(); iter++){
			v = erdos.find(*iter);
			if(v == erdos.end()|| v->second > low){
				erdos[*iter] = low;
				update.insert(*iter);
			}
		}
	}
}

int main(){
	int tstcase = 0;
	
	cin>>paper>>query;	
	while(paper){
		cin.getline(buffer,280);
		init();
		while(paper--){
			cin.getline(buffer,280);
			parse();
		}
		
		assign_value();
		
		cout<<"Database #"<<++tstcase<<endl;
		while(query--){
			cin.getline(buffer,280);
			do_query();
		}
		
		cout<<endl;
		cin>>paper>>query;	
	}
	
	return 0;
}
