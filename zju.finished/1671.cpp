#include<iostream>
#include<queue>
// BFS
using namespace std;
int width,height;
int matrix[8][8];
int bitmask[8][8];
int ox,oy;

struct Node {
	unsigned char x;
	unsigned char y;
	unsigned char hp;
	unsigned int step;
};
struct MyComp{
	int operator()(const Node&a, const Node&b){
		return a.step > b.step;
	}
};

int fun(){
	Node one;
	one.x = ox, one.y = oy; one.hp=6; one.step = 0;
	memset(bitmask,0,sizeof(bitmask));
	bitmask[ox][oy] = 6;
	priority_queue<Node,vector<Node>, MyComp> q;
	q.push(one);
	int x,y;
	while(!q.empty()){
		one = q.top(); q.pop();

		x = one.x, y = one.y; 

		if(matrix[x][y]==3){
			return one.step;
		}else if(matrix[x][y] == 4){
			one.hp = 6;
		}
		if(--one.hp ==0)
			continue;
		
		one.step++;
		if(x>0 && matrix[x-1][y] && bitmask[x-1][y] < one.hp){
			one.x = x-1; one.y = y;
			q.push(one);
			bitmask[x-1][y] = one.hp;
		}
		if(x<height-1 && matrix[x+1][y] && bitmask[x+1][y] < one.hp){
			one.x = x+1; one.y = y;
			q.push(one);
			bitmask[x+1][y] = one.hp;
		}
		if(y>0 && matrix[x][y-1] && bitmask[x][y-1] < one.hp){
			one.x = x; one.y = y-1;
			q.push(one);
			bitmask[x][y-1] = one.hp;
		}
		if(y<width-1 && matrix[x][y+1] && bitmask[x][y+1] < one.hp){
			one.x = x; one.y = y+1;
			q.push(one);
			bitmask[x][y+1] = one.hp;
		}
	}

	return -1;
}

int main(){
	
	cin>>width>>height;
	while(width+height){
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				cin>>matrix[i][j];
				if(matrix[i][j] == 2){
					ox = i, oy= j;
				}
			}
		}
		cout<<fun()<<endl;

		cin>>width>>height;
	}

	return 0;
}
