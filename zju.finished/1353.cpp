#include<iostream>
//递归分解法
using namespace std;
long long mat[240][240];

void calc(int n){
	if(mat[n][0]!=0)
		return;
	long long sum = 1;
	int bi=n/2,left;
	mat[n][n] = sum;
	for(int i=n-1;i>bi;i--){
		mat[n][i] = sum;
	}
	for(int i=bi;i>=1;i--){
		left = n - 2*i;
		if(left==0){
			sum++;
		} else {
			calc(left);
			sum += mat[left][i];
		}
		mat[n][i] = sum;
	}
	mat[n][0] = sum;
}

int main(){
	int num;

	cin>>num;
	while(num){
		calc(num);
		cout<<num<<" "<<mat[num][0]<<endl;
		cin>>num;
	}

	return 0;
}
