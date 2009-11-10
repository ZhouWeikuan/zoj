#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Node {
	string name;
	int solved;
	int fee;
};

vector<Node> team;

struct MyComp {
	int operator()(const Node &a, const Node &b){
		if(a.solved != b.solved)
			return a.solved > b.solved;
		return a.fee < b.fee;
	}
};

int main(){
	Node n;
	int tnum, sub, finish;
	
	cin>>tnum;
	while(tnum --){
		cin>>n.name;
		n.fee = n.solved = 0;
		for(int i=0;i<4;i++){
			cin>>sub>>finish;
			if(finish){
				n.solved ++;
				n.fee += (sub -1) * 20 + finish;
			}
		}
		team.push_back(n);
	}	

	sort(team.begin(), team.end(), MyComp());
	int i = 0;
	cout<<team[i].name <<" "<<team[i].solved <<" "<< team[i].fee<<endl;

	return 0;
}
