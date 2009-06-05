#include<iostream>

using namespace std;
struct Point {
	int x;
	int y;
};

Point node[4];
int num;

int judge(int a, int b, int c, int d){
	//中点相同
	if( node[a].x + node[b].x != node[c].x + node[d].x
		|| node[a].y + node[b].y != node[c].y + node[d].y)
		return 0;
	//向量垂直
	int x1,x2,y1,y2;
	x1 = node[a].x - node[b].x;
	y1 = node[a].y - node[b].y;
	x2 = node[c].x - node[d].x;
	y2 = node[c].y - node[d].y;
	if(x1*x2 + y1*y2==0)
		return 1;
	return 0;
}

int fun(){
	if(judge(0,1,2,3))
		return 1;
	if(judge(0,2,1,3))
		return 1;
	if(judge(0,3,1,2))
		return 1;
	return 0;
}

int main(){
	int i, tstcase = 0;
	const char * ans[2] = {"No","Yes"};
	cin>>num;
	while(tstcase++ < num){
		for(i=0;i<4;i++){
			cin>>node[i].x >>node[i].y;
		}
		cout<<"Case "<<tstcase<<":"<<endl;
		i = fun();
		cout<<ans[i]<<endl;
		if(tstcase != num)
			cout<<endl;
	}

	return 0;
}
