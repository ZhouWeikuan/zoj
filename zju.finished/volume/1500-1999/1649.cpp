#include<iostream>
#include<queue>
using namespace std;
int row,col;
int mat[208][208];
unsigned bitmask[208][208];
int ox,oy;

struct Node{
	unsigned char  x;
	unsigned char  y;
	unsigned short step;
};

struct Comp{
	int operator()(const Node &a, const Node&b){
		return a.step > b.step;
	}
};

int fun(){
	memset(bitmask,-1,sizeof(bitmask));
	priority_queue<Node, vector<Node>,Comp> q;
	Node old;
	old.step = 0, old.x=ox, old.y=oy;
	bitmask[ox][oy]=0;
	q.push(old);
	unsigned step,x,y;
	while(! q.empty()){
		old = q.top(); q.pop();
		x = old.x, y = old.y, step = old.step;
		if(mat[x][y]==1) // #
			continue; 
		if(mat[x][y] == 5) // x
			step++;
		else if(mat[x][y]== 4)  // r
			return step;
		step ++;
		if(x>0 && step < bitmask[x-1][y] ){
			old.x = x-1, old.y = y , old.step = step;
			q.push(old);
			bitmask[x-1][y] = step;
		}
		if(x<row-1 && step<bitmask[x+1][y]){
			old.x = x+1, old.y = y , old.step = step;
			q.push(old);
			bitmask[x+1][y]=step;
		}
		if(y>0 && step < bitmask[x][y-1]){
			old.x = x, old.y=y-1, old.step = step;
			q.push(old);
			bitmask[x][y-1] = step;
		}
		if(y<col-1 && step < bitmask[x][y+1]){
			old.x = x, old.y = y+1, old.step = step;
			q.push(old);
			bitmask[x][y+1] = step;
		}
	}
	return -1;
}

int main(){
	char ch;
	
	while(cin>>row>>col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>ch;
			switch(ch){
				case '#':
					ch = 1;
					break;
				case '.':
					ch = 0; break;
				case 'a':
					ch = 3; 
					ox = i, oy = j;
					break;
				case 'r':
					ch = 4; break;
				default:
					ch = 5; break;
			}
			mat[i][j] = ch;
		}
	}
		ox = fun();
		if(ox == -1){
			cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
		} else {
			cout<<ox<<endl;
		}
	}

	return 0;
}
