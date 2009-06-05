#include<iostream>
// 使用递推的方式，从n-1推到n的情况
//
using namespace std;
long long int mat[21][200];

void init(){
	int i,lim,j,n,k;
	mat[1][0] = 1;
	for(i=1;i<20;i++){
		lim = i*(i-1)/2;
		for(j=0;j<=lim;j++){
			for(k=0;k<=i;k++){
				mat[i+1][k+j] += mat[i][j];
			}
		}
	}
}

int main(){
	int a,b;
	init();

	cin>>a>>b;
	while(a){
		if(b*2 > a*(a-1)){
			cout<<0<<endl;
		} else {
			cout<<mat[a][b]<<endl;
		}
		cin>>a>>b;
	}
	return 0;
}
