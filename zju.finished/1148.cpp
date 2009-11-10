#include<iostream>
#include<queue>
#include<vector>

enum {
	Size = 80,
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3,
};
using namespace std;
char bitmap[Size][Size];
int visit[Size][Size];

struct Node {
	unsigned int direct:8;
	unsigned int row:8;
	unsigned int col:8;
	unsigned int step:32;
};

struct MyComp {
	int operator()(const Node &a, const Node &b){
		return a.step > b.step;
	}
};
int width,height;

void fun(){
	int tstcase = 0;
	int sw,sh,ew,eh;
	int find;
	Node one;

	cin>>sw>>sh>>ew>>eh;
	while(sw){
		if(bitmap[sh][sw] !='X' || bitmap[eh][ew]!='X'){
			cout<<"Pair "<<++tstcase<<": impossible."<<endl;
			cin>>sw>>sh>>ew>>eh;
			continue;
		}
		priority_queue<Node,vector<Node>, MyComp > q;
		find = 0;
		memset(visit,0,sizeof(visit));
		visit[sh][sw] = 1;
		one.row = sh-1,one.col=sw,one.step =1,one.direct=Up;
		q.push(one);
		one.row = sh,one.col=sw-1,one.step =1,one.direct=Left;
		q.push(one);
		one.row = sh+1,one.col=sw,one.step =1,one.direct=Down;
		q.push(one);
		one.row = sh,one.col=sw+1,one.step =1,one.direct=Right;
		q.push(one);
		while(!q.empty()){
			Node n;
			one = q.top(); q.pop();
			sh = one.row; 
			sw = one.col;
			if(sw == ew && sh == eh){
				find = 1;
				break;
			}
			if(bitmap[sh][sw] == 'X'){
				visit[sh][sw] = one.step;
				continue;
			} else if(visit[sh][sw]){
				continue;
			}
			visit[sh][sw] = one.step;
			
			n.row = sh - 1; n.col = sw;  n.direct = Up;
			n.step = one.step + (one.direct != Up);
			if(n.row <= height && 
					(visit[n.row][n.col] ==0|| one.step < visit[n.row][n.col]))
				q.push(n);
			
			n.row = sh; n.col = sw -1;  n.direct = Left;
			n.step = one.step + (one.direct != Left);
			if(n.col <= width && 
					(visit[n.row][n.col] ==0|| one.step < visit[n.row][n.col]))
				q.push(n);

			n.row = sh +1 ; n.col = sw;  n.direct = Down;
			n.step = one.step + (one.direct != Down);
			if(n.row <= height && 
					(visit[n.row][n.col] ==0|| one.step < visit[n.row][n.col]))
				q.push(n);

			n.row = sh ; n.col = sw + 1;  n.direct = Right;
			n.step = one.step + (one.direct != Right);
			if(n.col <= width && 
					(visit[n.row][n.col] ==0|| one.step < visit[n.row][n.col]))
				q.push(n);
		}
		cout<<"Pair "<<++tstcase<<": ";
		if(find){
			cout<<one.step<<" segments."<<endl;
		} else{
			cout<<"impossible."<<endl;
		}
		/*
		for(int i=0;i<=height;i++){
			for(int j=0;j<=width;j++){
				printf("%02d", visit[i][j]);
			}
			printf("\n");
		}
		*/
		cin>>sw>>sh>>ew>>eh;
	}

}

int main(){
	int i,j;
	int tstcase = 0;
	
	cin>>width>>height;
	while(width){
		memset(bitmap,0,sizeof(bitmap));
		cin.getline(bitmap[0],Size);
		for(i=1;i<= height;i++){
			cin.getline(&bitmap[i][1],Size);
		}
		width++, height++;
		cout<<"Board #"<<++tstcase<<":"<<endl;
		fun();
		cout<<endl;
		cin>>width>>height;
	}

	return 0;
}
