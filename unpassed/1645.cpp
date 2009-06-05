#include<iostream>
#include<set>
#include<queue>

using namespace std;
struct Node {
	int parent;
	int level;
	int ref;
};

Node tree[108];
int N,K;

struct MyComp {
	int operator()(const int &a, const int&b){
		return tree[a].level < tree[b].level;
	}
};

int fun(){
	int i;
	set<int> leaf;
	priority_queue<int,vector<int>, MyComp> q;
	for(i=0;i<N;i++){
		if(tree[i].ref==0){
			q.push(i);
		}
	}
	int t,cur,p,ret=0;
	while(!q.empty()){
		t = K;
		while(!q.empty() && t--){
			cur = q.top(); q.pop();
			p = tree[cur].parent;
			if(p!=-1 && --tree[p].ref ==0){
				leaf.insert(p);
			}
		}
		ret ++;
		for(set<int>::iterator iter=leaf.begin();
				iter!=leaf.end();iter++){
			q.push(*iter);
		}
		leaf.clear();
	}
	return ret;
}

int main(){
	int a,b,t;
	cin>>N>>K;
	while(N+K){
		for(a=0;a<N;a++){
			tree[a].parent = -1;
			tree[a].level = 0;
			tree[a].ref = 0;
		}
		t = N;
		while(t-->1){
			cin>>a>>b;
			a--,b--;
			tree[a].parent=b;
			tree[b].ref++;
			tree[a].level = tree[b].level + 1;
		}
		a = fun();
		cout<<a<<endl;

		cin>>N>>K;
	}

	return 0;
}
