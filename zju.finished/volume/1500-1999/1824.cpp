#include<iostream>
using namespace std;

int row,col;
bool matrix[64][64];
char buffer[100];

enum State{
	North,
	East,
	South,
	West,
};
char position[4] = {'N','E','S','W'};
int move[4][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};

void fun(){
	int x,y;
	int d = North;
	char cmd;	
	cin>>x>>y;
	x --, y --;
	
	cin>>cmd;
	while(cmd != 'Q'){
		switch(cmd){
			case 'R':
				d++;
				d %= 4;
				break;
			case 'L':
				d--;
				d = (d+4)%4;
				break;
			case 'F':
				int nx,ny;
				nx = x + move[d][0];
				ny = y + move[d][1];
				if(matrix[nx][ny] == false){
					x = nx, y = ny;
				}
				break;
		}
		
		cin>>cmd;
	}
	x ++, y ++;
	cout<<x<<" "<<y<<" "<< position[d] <<endl;
}

int main(){
	int i,j;
	while(cin>>row>>col){
		cin.getline(buffer,100);
		for(i=0;i<row;i++){
			cin.getline(buffer,100);
			for(j=0;buffer[j];j++){
				if(buffer[j]=='*'){
					matrix[i][j] = true;
				} else {
					matrix[i][j]= false;
				}
			}
		}
		
		fun();		
		
	}

	return 0;
}
