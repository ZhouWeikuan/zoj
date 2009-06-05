#include<iostream>
#include<queue>
using namespace std;
enum {
	Size = 6,
};

int coin[Size];
int cent[108];
struct Node {
	int val;
	int step;
};

void fun(){
	int i;
	int cost = 0;
	memset(cent,0,sizeof(cent));
	queue<Node> q;
	Node one;
	one.step = 1;
	for(i=0;i<Size;i++){
		one.val = coin[i];
		cent[one.val] = 1;
		q.push(one);
	}
	while(!q.empty()){
		const Node &n = q.front();
		if(cost < n.step)
			cost = n.step;
		one.step = n.step + 1;
		for(i=0;i<Size;i++){
			one.val = n.val + coin[i];
			if(one.val > 100)
				break;
			if(cent[one.val])
				continue;
			cent[one.val] = one.step;
			q.push(one);
		}
		for(i=0;i<Size;i++){
			one.val = n.val - coin[i];
			if(one.val < 0)
				one.val = -one.val;
			if(one.val ==0||cent[one.val])
				continue;
			cent[one.val] = one.step;
			q.push(one);
		}
		q.pop();
	}

	double s = 0;
	for(i=1;i<=100;i++){
		s += cent[i];
	}
	s /= 100;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<s<<" "<<cost<<endl;
}

int main(){
	int tstcase;

	cin>>tstcase;
	while(tstcase --){
		cin>>coin[0]>>coin[1]>>coin[2]>>coin[3]>>coin[4]>>coin[5];
		fun();
	}

	return 0;
}
