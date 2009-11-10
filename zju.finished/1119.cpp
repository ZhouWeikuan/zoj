#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;
map<int, vector<int> > edge;
set<int> unvisit;
int failnode;

void travel(int n){
	if(n == failnode)
		return;
	if(unvisit.find(n) == unvisit.end())
		return;
	unvisit.erase(n);
	vector<int> &v = edge[n];
	int i;
	for(i=0;i<v.size();i++){
		travel(v[i]);
	}
}

void fun(){
	map<int,int> spf;
	map<int, vector<int> >::iterator iter;
	vector<int> node;
	for(iter= edge.begin(); iter!= edge.end(); iter++){
		node.push_back(iter->first);
	}
	int i,j;
	int subnum;
	for(i=0;i<node.size();i++){
		failnode = node[i];
		unvisit.clear();
		subnum = 0;
		for(j=0;j<node.size();j++){
			if(i!=j){
				unvisit.insert(node[j]);
			}
		}
		while(!unvisit.empty()){
			subnum ++;
			travel(*(unvisit.begin()));
		}
		if(subnum > 1){
			spf[failnode] = subnum;
		}
	}
	if(spf.size() == 0){
		cout<<"  No SPF nodes"<<endl;
		return;
	}
	map<int,int>::iterator link;
	for(link = spf.begin(); link != spf.end(); link++){
		cout<<"  SPF node "<<link->first<<" leaves "
			<<link->second <<" subnets"<<endl;
	}
}

int main(){
	int tstcase = 0;
	int a,b;
	
	cin>>a;
	while(a != 0){
		if(tstcase)
			cout<<endl;
		edge.clear();
		while(a!=0){
			cin>>b;
			edge[a].push_back(b);
			edge[b].push_back(a);
			cin>>a;
		}
		cout<<"Network #"<<++tstcase<<endl;
		fun();

		cin>>a;
	}
	
	return 0;
}
