#include<iostream>
#include<queue>
#include<set>

using namespace std;
int fact[100];
int fnum;
int sumtable[1000008];

struct Node {
	int value;
	int start;
};

void init(){
	int i;
	set<int> table;
	fnum = 1;
	fact[0] = 1;
	fact[1] = 1;
	while(fact[fnum] <= 1000000){
		fnum++;
		fact[fnum] = fact[fnum-1] * fnum;
	}
	Node n,ins;
	queue<Node> q;
	for(i=0;i<fnum;i++){
		n.value = fact[i];
		n.start = i+1;
		q.push(n);
	}
	while(! q.empty()){
		n = q.front(); q.pop();
		table.insert(n.value);
		for(i=n.start;i<fnum;i++){
			ins.value = n.value + fact[i];
			if(ins.value > 1000000){
				break;
			}
			ins.start = i + 1;
			q.push(ins);
		}
	}
	for(set<int>::iterator iter= table.begin(); iter!= table.end();iter++){
		sumtable[*iter] = 1;
	}
}


int main(){
	int n;

	init();

	cin>>n;
	while(n >= 0){
		if(sumtable[n]){
			cout<<"YES\n";
		}else {
			cout<<"NO\n";
		}
		
		cin>>n;
	}
	
	return 0;
}
