#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int mat[108][108];
int num;

void fun(){
	int i,j;
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			mat[i][j]	=	1;
		}
	}
	for(i=0;i<num;i++){
		mat[i][i] = 0;
	}
	mat[num-1][num-1] = 100;
	mat[num-1][0] = 0;
	for(i=0;i<num;i++){
		cout<<mat[i][0];
		for(j=1;j<num;j++){
			cout<<" "<<mat[i][j];
		}
		cout<<endl;
	}
}

int main(){
	
	while(cin>> num){
		fun();
	}

	return 0;
}
