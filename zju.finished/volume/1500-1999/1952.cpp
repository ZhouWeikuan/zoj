#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;

enum {
	Size = 204,
};

map<string, int> table;
int N,R;
int start, end;
map<int,int> matrix[Size];
queue<int> que;
int mark[Size];

int fun(){
	int cur;
	int i;
	int t;
	int n;
	map<int,int>::iterator iter;
	memset(mark,0,sizeof(int)*Size);
	mark[start] = 100000;
    que.push(start);
    while(! que.empty()){
		cur = que.front();		
		que.pop();
		if(cur== end)
			continue;
		for(iter=matrix[cur].begin(); iter!= matrix[cur].end(); iter++){
			n = iter->first;
			t = mark[cur] < iter->second? mark[cur] : iter->second;
			if(mark[n] < t) {
				mark[n] = t;
				que.push(n);
			}			
		}		
	}
	return mark[end];
}

int main(){
    int index;
    string a,b;
    int ton;
    int tstcase = 0;
    
    cin>>N>>R;
    while(N && R){
		table.clear();
		index = 0;
		while(R -- ){
			cin>>a>>b>>ton;
			if(table.find(a) == table.end()){
				matrix[index].clear();
				table[a] = index ++;
			}
			if(table.find(b) == table.end()){
				matrix[index].clear();
				table[b] = index ++;
			}
			int second = table[b];
			int first = table[a];
			matrix[first][second] = ton;
			matrix[second][first] = ton;
		}
		cin>>a>>b;
		if(table.find(a) == table.end()){
			matrix[index].clear();
			table[a] = index ++;
		}
		if(table.find(b) == table.end()){
			matrix[index].clear();
			table[b] = index ++;
		}
		start = table[a];
		end = table[b];
		ton = fun();
		tstcase ++;
		cout<<"Scenario #"<<tstcase<<endl;
		cout<<ton<<" tons"<<endl<<endl;
		
		cin>>N>>R;	
	}
    
    return 0;
}
