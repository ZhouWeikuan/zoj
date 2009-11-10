#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int parent[28];
int num;
void init(){
	int i;
	for(i=0;i<num;i++)
		parent[i] = i;
}

int insame(int a,int b){
	int pa,pb;
	int t;
	t = a;
	pa = parent[t];
	while(pa != t){
		t = pa;
		pa = parent[t];
	}
	parent[a] = pa;

	t =b ;
	pb = parent[t];
	while(pb != t){
		t = pb; pb = parent[t];
	}
	parent[b] = pb;

	if(pa == pb)
		return 1;
	if(pa < pb){
		parent[pb] = parent[b] = pa;
	} else {
		parent[pa] = parent[a] = pb;
	}
	return 0;
}

struct Node {
	int a,b;
	int value;
};

struct MyComp{
	int operator()(const Node &a, const Node &b){
		return a.value > b.value;
	}
};

void fun(priority_queue<Node,vector<Node>,MyComp> &q){
	int point = num -1;
	int ret = 0;
	while(! q.empty()){
		const Node &n = q.top();
		if(!insame(n.a,n.b)){
			ret += n.value;
			point --;
		}
		
		q.pop();
	}
	cout<<ret<<endl;
}

int main(){
	Node one;
	int i,t;
	char c;
	
	cin>>num;
	while(num){
		init();
		priority_queue<Node, vector<Node>, MyComp> que;
		for(i=0;i<num-1;i++){
			cin>>c>>t;
			one.a = c-'A';
			while(t--){
				cin>>c>>one.value;
				one.b = c-'A';
				que.push(one);
			}
		}
		fun(que);

		cin>>num;
	}

	return 0;
}
