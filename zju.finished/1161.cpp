#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//	1) 采用贪心法判断只选择前n个湖时捕鱼量
//	2) 注意捕鱼量为0时情况
//	3) 注意把湖加到队列时，判断是否为零；
//  错误值为4
struct Pool {
	int value;
	int dec;
	int transtime;
	int visit;
};

struct Node {
	int no;
	int value;
};

Pool lake[28];
int save[28];
int lakenum;
int hour;

struct MyComp{
	int operator()(const Node &a, const Node &b){
		if(a.value != b.value)
			return a.value < b.value;
		return a.no > b.no;
	}
};

void fun(){
	int max = -1;
	int current,i,j;
	int lefttime;
	Node one;
	memset(save,0,sizeof(save));
	
	for(i=0;i<lakenum;i++){
		lefttime = hour *12 - lake[i].transtime;
		if(lefttime <= 0)
			continue;
		priority_queue<Node,vector<Node>, MyComp> q;
		for(j=0;j<=i;j++){
			one.no = j; one.value = lake[j].value;
			if(one.value > 0)
				q.push(one);
			lake[j].visit = 0;
		}
		current = 0;
		while(!q.empty() && lefttime --){
			one = q.top(); q.pop();
			current += one.value;
			one.value -= lake[one.no].dec;
			lake[one.no].visit ++;
			if(one.value > 0)
				q.push(one);
		}
		if(lefttime > 0)
			lake[0].visit += lefttime;
		
		if(current > max){
			for(j=0;j<=i;j++){
				save[j] = lake[j].visit;
			}
			max = current;
		}
	}
	cout<<save[0]*5;
	for(i=1;i<lakenum;i++){
		cout<<", "<<save[i]*5;
	}
	cout<<endl;
	cout<<"Number of fish expected: "<<max<<endl;
}

int main(){
	int blocknum,tstcase;
	int i;

	cin>>blocknum;
	while(blocknum--){
		cin>>lakenum;
		tstcase = 0;
		while(lakenum){
			if(tstcase ++)
				cout<<endl;
			cin>>hour;
			for(i=0;i<lakenum;i++){
				cin>>lake[i].value;
			}
			for(i=0;i<lakenum;i++){
				cin>>lake[i].dec;
			}
			lake[0].transtime = 0;
			for(i=1;i<lakenum;i++){
				cin>>lake[i].transtime;
				lake[i].transtime += lake[i-1].transtime;
			}
			fun();
			cin>>lakenum;
		}
		
		if(blocknum)
			cout<<endl;
	}	

	return 0;
}
