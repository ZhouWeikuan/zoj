#include<iostream>
#include<queue>

/*

 这样吧，对于N<=50的情况，可以用计算机穷举。
 让后只要证明对于N>=51,M=N时可以走到就可以了。
 找到同N奇偶性相同的最大平方数k^2.所以k^2 > N/2
 移动方案为
 1+3+5+...+(2k-1)
   -(2k+1)+(2k+3)
     -(2k+5)+(2k+7)
	   - ...
	   直到到达位子N，容易看出没有越界

 */
using namespace std;
enum {
	Size = 51,
};
struct Node {
	int lim;
	int cur;
	int step;
};
int save[Size];

void init(){
	Node n = {1,1,3};
	queue<Node> q;
	q.push(n);
	while(!q.empty()){
		Node one = q.front(); q.pop();
		if(one.cur <= 50){
			if(save[one.cur] ==0 || ( save[one.cur] > one.lim)) {
				save[one.cur] = one.lim;
			} else {
				continue;
			}
		}
		if(one.lim >=200)
			continue;
		n.step = one.step + 2;
		//sub
		if(one.cur > one.step ){
			n.cur = one.cur - one.step; 
			n.lim = one.lim ;
			q.push(n);
		}
		// add
			
		n.cur = one.cur + one.step;
		n.lim = one.lim < n.cur?n.cur:one.lim;
		q.push(n);
	}
}

int main(){
	int n,m;
	init();
	int i;
	/*
	for(i=1;i<=50;i++){
		cout<<save[i]<<endl;
	}
	*/
	cin>>n>>m;
	while(n + m){
		if(m>=50 || save[m] <= n){
			cout<<"Let me try!"<<endl;
		} else {
			cout<<"Don't make fun of me!"<<endl;
		}
		cin>>n>>m;
	}
	
	return 0;
}
