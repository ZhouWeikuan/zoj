#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

map<char , int > table[50];
set<char>  leave[50];
vector<int>  down[50];

int tnum;
char buffer[40];
int mask[50];

void add(int n, int v){
	if(buffer[0] =='.')
		return;
	int i;
	for(i=0; buffer[i];i++){
		table[n][buffer[i]] = v;
	}
	if(v < 0)
		return;
	for(i=0;buffer[i];i++)
		leave[n].insert(buffer[i]);
}

void output(int i){
	cout<<":";
	set<char>::iterator iter;
	for(iter=leave[i].begin(); iter!= leave[i].end(); iter++){
		cout<<*iter;
	}
	cout<<":"<<endl;
}

void fun(){
	int from,to,i;
	queue<int> q;

	memset(mask,0,sizeof(mask));
	cin>>from>>to;
	while(from && to){
		from --, to --;
		down[from].push_back(to);
		q.push(from);
		mask[from] = 1;
		cin>>from>>to;
	}
	set<char>::iterator f,st;
	map<char,int>::iterator t;
	while(!q.empty()){
		from = q.front(); q.pop();
		mask[from] = 0;
		for(i=0;i<down[from].size(); i++){
			to = down[from][i];
			for(f=leave[from].begin(); f!= leave[from].end(); f++){
				t = table[to].find(*f);
				if(t->second<0)
					continue;
				st = leave[to].find(*f);
				if(st==leave[to].end()){
					leave[to].insert(*f);
					if(mask[to] ==0){
						q.push(to);
						mask[to] = 1;
					}
				}
			}
		}

	}
	
	for(to =0; to < tnum; to++){
		output(to);
	}
}

int main(){
	int tstcase;
	int i;
	
	cin>>tstcase;
	//tstcase = 1;
	while(tstcase --){
		cin>>tnum;
		for(i=0;i<tnum;i++){
			table[i].clear();
			leave[i].clear();
			down[i].clear();
			
			cin>>buffer;
			add(i,1);
			cin>>buffer;
			add(i,-1);
		}
		
		fun();
		if(tstcase)
			cout<<endl;
	}

	return 0;
}
