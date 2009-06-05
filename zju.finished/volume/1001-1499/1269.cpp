#include<iostream>

using namespace std;
//  ret value indicate :
//  	> 0  a valid result 
//		==0  not valid and may continue
//		< 0 a unvalid result and break immediately;
int calc(int p, int n){
	int left = p;
	int ret = 1;
	while(left){
		if(n%p !=1 )
			ret = 0;
		n = n - n/p - 1;
		if(n < 0)
			return -1;
		left --;
	}
	if(n%p !=0 || ret == 0)
		return 0;
	return 1;
}

void fun(int num){
	int result = 1;
	int i = 1,t;
	for(i++; i< 10; i++){
		t = calc(i,num);
		if(t > 1){
			result = i;
			break;
		} else if(t ==1){
			result = i;
		} else if(t ==0) {
			;
		} else {
			break;
		}
	}
	if(result > 1){
		cout<<result<<" people and 1 monkey" <<endl;
	} else {
		cout<<"no solution"<<endl;
	}
}

int main(){
	int num;

	cin>>num;
	while(num > 0){
		cout<<num<<" coconuts, ";
		fun(num);

		cin>>num;
	}

	return 0;
}
