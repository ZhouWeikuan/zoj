#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;
enum {
	N = 204,
};
struct Node {
	int a;
	int b;
	double range;
	struct cmp{
		int operator()(const Node &l, const Node&r){
			return l.range > r.range;
		}
	};
};
struct Point {
	int x;
	int y;
};

int num;
Point pt[N];
int fat[N];

void connect(int a,int b){
	if(a < b){
		fat[b] = a;
	} else {
		fat[a] = b;
	}
}
int getpar(int t){
	int p = fat[t];
	while(p != t){
		fat[t] = fat[p];
		t = p;
		p = fat[p];
	}
	return p;
}

double fun(){
	int i,j,k;
	double t;
	Node green;
	priority_queue<Node,vector<Node>,Node::cmp> q;
	
	for(i=0;i<num;i++){
		fat[i] = i;
		cin>>pt[i].x>>pt[i].y;
		for(j=0;j<i;j++){
			k = pt[i].x - pt[j].x;
			k *= k;
			t = k;
			k = pt[i].y - pt[j].y;
			k *= k;
			t += k;
			t = sqrt(t);
			green.a = i; green.b= j; green.range = t;
			q.push(green);
		}
	}
	while(!q.empty()){
		const Node &one = q.top();
		i = getpar(one.a);
		j = getpar(one.b);
		if(i == j){
			goto end;
		}
		connect(i,j);
		i = getpar(0);
		j = getpar(1);
		if(i==j){
			return one.range;
		}
		
		end: q.pop();
	}
	return 0;
}

int main(){
	int tstcase = 0;

	cin>>num;
	while(num ){
		tstcase ++;
		cout<<"Scenario #"<<tstcase<<endl;
		cout<<"Frog Distance = ";
		cout.setf(ios::fixed); cout.precision(3);
		cout<<fun()<<endl<<endl;

		cin>>num;
	}
	
	return 0;
}
