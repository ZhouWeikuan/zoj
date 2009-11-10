#include<iostream>
#include<map>

using namespace std;
map<int,int> visit;
map<int,int> tree;
multimap<int,int> edge;
int nodenum,place;
char buffer[256];

int calc(int node){
	int value = 0;
	int t;
	if(node == place)
		return 1;
	if(visit.find(node) != visit.end())
		return 0;
	visit[node] = 0;
	multimap<int,int>::iterator first,last;
	first = edge.lower_bound(node);
	last  = edge.upper_bound(node);
	for(;first!=last; first++){
		t = calc(first->second);
		value += t;
		if(t == 1){
			tree[node] = first->second;
		}
	}

	visit[node] = value;
	return value >0;
}
int fun(){
	int t = 0;
	int save;
	multimap<int,int>::iterator first,last;
	first = edge.lower_bound(0);
	last = edge.upper_bound(0);
	visit[0] = 0;
	for(;first!=last;first++){
		save = calc(first->second);
		t += save;
		if(t > 1)
			return 0;
		if(save ){
			tree[0] = first->second;
		}
	}
	visit[0] = t;
	save = t = 0;
	while(visit[t] == 1){
		save = t;
		t = tree[t];
	}
	if(visit[t] == 0)
		return save;
	return t;
}

int main(){
	int blocknum;
	int fro, to;
	char tmp,ch;

	cin>>blocknum;
	//blocknum = 1;
	while(blocknum --){
		visit.clear(); tree.clear(); edge.clear();
		
		cin>>nodenum>>place;
		cin.getline(buffer,256);
		cin.getline(buffer,256);
		while(buffer[0] != 0){
			sscanf(buffer,"%d%d",&fro,&to);
			edge.insert(make_pair(fro,to));
			cin.getline(buffer,256);
		}
		place = fun();
		cout<<"Put guards in room "<<place<<".\n";
		
		if(blocknum)
			cout<<("\n");
	}
	return 0;
}
