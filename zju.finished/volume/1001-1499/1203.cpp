#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int dot[108];
double cord[108][2];
int num;

struct Node {
	int key;
	double value;
};
struct MyComp{
	int operator()(const Node &a, const Node &b){
		return a.value > b.value;
	}
};

priority_queue<Node, vector<Node>, MyComp> que;

void init(){
	for(int i=0;i<num;i++){
		dot[i] = i;
	}
}

double dis(int i,int j){
	double a,b;
	a = cord[i][0] - cord[j][0];
	b = cord[i][1] - cord[j][1];
	a*=a;
	b*=b;
	a += b;
	a = sqrt(a);
	return a;
}

int getparent(int k){
	int child = k;
	int p = dot[child];
	while(p != child){
		child = p;
		p = dot[child];
	}
	dot[k] = p;
	return p;
}
int join(int a,int b){
	a = getparent(a);
	b = getparent(b);
	if(a == b){
		return 0;
	}
	if(a < b){
		dot[b] = a;
	}else {
		dot[a] = b;
	}
	return 1;
}

void fun(){
	static int tstcase = 0;
	init();
	num --;
	int i,j;
	double ret = 0;
	while(num){
		const Node &one = que.top();
		i = one.key &0x0ffff;
		j = one.key>>16;
		if(join(i,j)){
			num--;
			ret += one.value;
		} 
		que.pop();
	}
	while(!que.empty()){
		que.pop();
	}
	if(tstcase)
		cout<<endl;
	printf("Case #%d:\n",++tstcase);
	printf("The minimal distance is: %.02lf\n",ret);
}

int main(){
	int key;
	int i,j;
	Node one;

	cin>>num;
	while(num){
		for(i=0;i<num;i++){
			cin>>cord[i][0]>>cord[i][1];
			for(j=i-1;j>=0;j--){
				one.key = (i<<16)+j;
				one.value = dis(i,j);
				que.push(one);
			}
		}
		fun();
		cin>>num;
	}
	
	return 0;
}
