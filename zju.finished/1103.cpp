#include<iostream>
#include<queue>
//  移动规则： 第三个棋子移动时，只能按与一二棋子间相同颜色走
using namespace std;
enum {
	Size = 50,
};

int x,y,z;
int num;
char matrix[Size][Size];
char visit[125000];
struct Node {
	int point;
	int step;
};
int fun(){
	if(x==y && y==z)
		return 0;
	
	int key, i;
	Node n;
	n.step = 0;
	n.point = (x<<16) + (y<<8) + (z);
	queue<Node> q;
	memset(visit,0,sizeof(visit));
	key = x * 50 *50 + y*50 + z;
	visit[key] = 1;
	q.push(n);
	
	while(!q.empty()){
		n = q.front(); q.pop();
		x= n.point>>16; y = (n.point>>8)&0xff; z= n.point&0xff;
		n.step ++;
		
		for(i=0;i<num;i++){
			if(matrix[x][i] != matrix[y][z]){
				continue;
			}
			key = (i*2500) + (y*50) + z;
			if(visit[key] ==0){
				visit[key] = 1;
				if(i==y && y==z)
					return n.step;
				n.point = (i<<16) + (y<<8) + (z);
				q.push(n);
			}
		}
		
		for(i=0;i<num;i++){
			if(matrix[y][i] != matrix[x][z]){
				continue;
			}
			key = (x*2500) + (i*50) + z;
			if(visit[key] ==0){
				visit[key] = 1;
				if(i==x && x==z)
					return n.step;
				n.point = (x<<16) + (i<<8) + (z);
				q.push(n);
			}
		}
		
		for(i=0;i<num;i++){
			if(matrix[x][y] != matrix[z][i]){
				continue;
			}
			key = (x*2500) + (y*50) + i;
			if(visit[key] ==0){
				visit[key] = 1;
				if(x==y && y==i)
					return n.step;
				n.point = (x<<16) + (y<<8) + (i);
				q.push(n);
			}
		}

	}
	
	return -1;
}

int main(){
	int i,j;
	
	cin>>num;
	while(num > 0){
		cin>>x>>y>>z;
		x--, y--, z--;
		for(i=0;i<num;i++)
			for(j=0;j<num;j++)
				cin>>matrix[i][j];
		i = fun();
		if( i >= 0){
			cout<<i<<endl;
		} else {
			cout<<"impossible"<<endl;
		}
		
		cin>>num;
	}

	return 0;
}
