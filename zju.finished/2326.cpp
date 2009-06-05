#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>

using namespace std;
struct Node {
	int a;
	int b;
	double val;

	struct cmp {
		int operator()(const Node&a, const Node&b){
			return a.val > b.val;
		}
	};
};

double totalvalue;
int num;
vector<int> con;
map<string,int> table;

void init(){
	con.clear();
	table.clear();
	int start = 0,i;
	string name;
	cin>>num;
	i = num;
	while(i--){
		cin>>name;
		table[name] = start;
		con.push_back(start);
		start ++;
	}
}

int getparent(int a){
	int t = a;
	int p = con[t];
	while(p != t){
		t = p;
		p = con[t];
	}
	con[a] = p;
	return p;
}

int merge(int a, int b){
	int pa = getparent(a);
	int pb= getparent(b);
	if(pa == pb)
		return 0;
	if(pa < pb){
		con[pb] = con[a] = con[b] = pa;
	} else {
		con[pa] = con[a] = con[b] = pb;
	}
	return 1;
}

double fun(){
	string sa,sb;
	int n;
	priority_queue<Node, vector<Node>, Node::cmp> q;
	Node no;
	cin>>n;
	while(n--){
		cin>>sa>>sb>>no.val;
		no.a = table[sa];
		no.b = table[sb];
		q.push(no);
	}

	double dis = 0;
	while(num > 1){
		const Node &nod = q.top();
		if(merge(nod.a, nod.b)){
			num--;
			dis += nod.val;
			if(dis > totalvalue){
				dis = -1;
				return dis;
			}
		}
		q.pop();
	}
	return dis;
}

int main(){
	double ret;
	while(cin>>totalvalue){
		init();
		ret = fun();
		if(ret < 0){
			cout<<"Not enough cable"<<endl;
		} else {
			cout.setf(ios::fixed);
			cout.precision(1);
			cout<<"Need "<< ret <<" miles of cable"<<endl;
		}
	}

	return 0;
}
