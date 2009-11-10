#include<iostream>
#include<string>

using namespace std;
enum {
	Line = 0,
	Down = 1,
	Corner = 2,
	Size = 108,
};
string passage[2][Size];
int pos[2];

int matrix[Size][Size];
int point[Size][Size];

int calc(int i,int j){
	if(i>=pos[0] || j>=pos[1]){
		return 0;
	}
	if(matrix[i][j] != -1)
		return matrix[i][j];
		
	if(passage[0][i] == passage[1][j]){
		point[i][j] = Corner;
		return matrix[i][j] = calc(i+1,j+1) + 1;
	}
	int a = calc(i+1,j);
	int b = calc(i,j+1);
	if( a < b ){
		point[i][j] = Line;
		matrix[i][j] = b;
	} else {
		point[i][j] = Down;
		matrix[i][j] = a;
	}
	return matrix[i][j];
}

void fun(){
	int i,j;
	for(i=0;i<pos[0];i++){
		for(j=0;j<pos[1];j++){
			matrix[i][j] = -1;
			point[i][j] = 0;
		}
	}

	calc(0,0);
	
	i = 0,j=0;
	while(i< pos[0] && j<pos[1]){
		switch(point[i][j]){
			case Line:
				j++;
				break;
			case Down:
				i++;
				break;
			case Corner:
				cout<<passage[0][i];
				if(matrix[i][j] > 1){
					cout<<" ";
				}
				i++,j++;
				break;
		}
	}
	cout<<endl;
}

int main(){
	
	while(cin>>passage[0][0]){
		pos[0] = pos[1] = 0;
		while(passage[0][pos[0]] != "#"){
			pos[0]++;
			cin>>passage[0][pos[0]];
		}
		cin>>passage[1][pos[1]];
		while(passage[1][pos[1]] != "#"){
			pos[1] ++;
			cin>>passage[1][pos[1]];
		}
		fun();
	}

	return 0;
}
