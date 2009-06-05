#include<iostream>
#include<queue>
using namespace std;

enum Status {
	Build = 0,
	Walk,
	Wait,
	Back,
	Work,	
};
struct Node {
	Status state;
	int clock;
	friend int operator < (const Node &a, const Node &b);
};
int operator < (const Node &a, const Node &b){
	return a.clock > b.clock;
}

typedef priority_queue<Node, vector<Node> >  PQ;

int walktime, worktime, unit, buildtime, num;

int fun(){
    PQ q;
    queue<Node> wq;
    int r = 0, u = 0, digging = 0;
    Node ins, n;
    ins.state = Build, ins.clock = buildtime;
    q.push(ins);
    
    for(;;){
		n = q.top(); q.pop();
		switch(n.state){
			case Build:
				r ++;
				if(r < num){
					ins.state = Build;
					ins.clock = n.clock + buildtime;
					q.push(ins);
				}
				n.state = Walk;
				n.clock += walktime;
				q.push(n);
				break;
			case Walk:
				if(digging ==0){
					n.state = Work;
					n.clock += worktime;
					q.push(n);
					digging = 1;
				} else {
					wq.push(n);
				}				
				break;
			case Work:
				if( ! wq.empty()){
					ins = wq.front(); wq.pop();
					ins.state = Work;
					ins.clock = n.clock + worktime;
					q.push(ins);
				} else {
					digging = 0;
				}
				n.state = Back;
				n.clock += walktime;
				q.push(n);
				break;
			case Back:
				u += unit;
				if(u >= 10000)
					return n.clock;
				n.state = Walk;
				n.clock += walktime;
				q.push(n);
				break;		
			default:
				cout<<"Error !"	<<endl;
				return -1;
				break;
		}
	}
}

int main(){
    
    //freopen("input.txt","r", stdin);
    
    while(cin>>walktime>>worktime>>unit>>num>>buildtime){
		cout<< fun() <<endl;
	}
    
    return 0;
}
