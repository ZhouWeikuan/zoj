#include<iostream>
#include<queue>

using namespace std;
int val[4] = {
	25,
	10,
	5,
	1
};
struct Node {
	int stat[4];
	int count;
};
Node tree[508];

void init(){
	int i,cur,t,v;
	for(i=1;i<=500;i++)
		tree[i].count = 1000;
	queue<int> q;
	for(i=0;i<4;i++){
		v = val[i];
		tree[v].count = 1;
		tree[v].stat[i] = 1;
		q.push(v);
	}
	while(!q.empty()){
		cur = q.front(); q.pop();
		t = tree[cur].count + 1;
		for(i=0;i<4;i++){
			v = cur + val[i];
			if(v > 500 || t >= tree[v].count)
				continue;
			tree[v] = tree[cur];
			tree[v].stat[i]++;
			tree[v].count ++;
			q.push(v);
		}
	}
}

int main(){
	int num,t,i,v;
	init();
	
	cin>>num;
	for(i=0;i<num;i++){
		cin>>v;
		cout<<i+1<<" ";
		cout<<tree[v].stat[0]<<" "<<"QUARTER(S), "
			<<tree[v].stat[1]<<" "<<"DIME(S), "
			<<tree[v].stat[2]<<" "<<"NICKEL(S), "
			<<tree[v].stat[3]<<" "<<"PENNY(S)"
			<<endl;
	}
	return 0;
}
