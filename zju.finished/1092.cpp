#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;
enum {
	Size = 32,
};
int num;

struct Node {
	int v;
	double rate;
};

vector<Node> exchange[Size];
double value[Size];

void build_map(){
	int i;
	string first,second;
	int a,b;
	map<string,int> table;
	for(i=0;i<num;i++){
		cin>>first;
		table[first] = i;
		exchange[i].clear();
	}
	Node n;
	cin>>i;
	while(i--){
		cin>>first>>n.rate>>second;
		a = table[first];
		b = table[second];
		n.v = b;
		exchange[a].push_back(n);
	}

}
int calc(int root){
	int cur;
	double val;
	vector<Node>::iterator pn;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(pn=exchange[cur].begin();pn !=exchange[cur].end();pn++){
			val = pn->rate * value[cur];
			if(val > value[pn->v]){
				if(pn->v == root)
					return 1;
				value[pn->v] = val;
				q.push(pn->v);
			}
		}
	}
	return 0;
}

int fun(){
	int i,j;

	for(i=0;i<num;i++){
		for(j=0;j<num;j++)
			value[j] = 0;
		value[i] = 1.0;
		if( calc(i) )
			return 1;
	}
	return 0;
}
int main(){
	int tstcase = 1;
	cin>>num;
	while(num){
		build_map();
		cout<<"Case "<<tstcase++<<": ";
		if(fun()){
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
		cin>>num;
	}

	return 0;
}
