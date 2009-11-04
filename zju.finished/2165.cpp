#include<iostream>

using namespace std;

int Row, Col;
int num;
int matrix[24][24];

void fun(int x, int y){
	if(x<0||x>=Row || y<0 || y>= Col)
		return;
	if(matrix[x][y] == 1)
		return;
	num ++;
	matrix[x][y] = 1;
	fun(x-1,y);
	fun(x+1,y);
	fun(x,y-1);
	fun(x,y+1);    
}

int main(){
    int i,j;
    char c;
    int x, y;
    
    cin>>Col>>Row;
    while(Col && Row){
		num = 0;
		for(i=0;i<Row;i++){
			for(j=0;j<Col;j++){
				cin>>c;
				if(c=='.'){
					matrix[i][j] = 0;
				} else if(c =='#'){
					matrix[i][j] = 1;
				} else {
					matrix[i][j] = 0;
					x = i;
					y = j;
				}
			}
		}
		fun(x,y);
		cout<<num<<endl;
		
		cin>>Col>>Row;
	}
    
    return 0;
}
