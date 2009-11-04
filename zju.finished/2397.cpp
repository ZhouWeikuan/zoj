#include<iostream>
#include<deque>
#include<algorithm>
// compare the first:
//			if A win, delete both the first 
//			if B win, delete A first, B last
//			else wait
// compare the last :
// 			if A win, delete both the last
// 			if B win, delete A first, B last
// 			else wait
// compare the first of A and the last of B
// 			if B win, delte A first, B last
// 			else delete both first.  // the last one and they balance
using namespace std;
int num;
deque<int> A,B;

int fun(){
	sort(A.begin(),A.end(), less<int>());
	sort(B.begin(),B.end(), less<int>());
	int win = 0,n;
	while(n = A.size()){
		n--;
		if(A[0] > B[0]){
			win++;
			A.pop_front(); B.pop_front();
		} else if(A[0] < B[0]) {
			win--;
			A.pop_front(); B.pop_back();
		} else if(A[n] > B[n]){
			win++;
			A.pop_back(); B.pop_back();
		} else if(A[n] < B[n]){
			win--;
			A.pop_front(); B.pop_back();
		} else { // use last to compare first.
			if(A[0] < B[n]){
				win--;
			} 
			A.pop_front(); B.pop_back();
		}
	}

	win *= 200;
	return win;
}
int main(){
	int i,t;
	cin>>num;
	while(num){
		for(i=0;i<num;i++){
			cin>>t;
			A.push_back(t);
		}
		for(i=0;i<num;i++){
			cin>>t;
			B.push_back(t);
		}
		t = fun();
		cout<<t<<endl;

		cin>>num;
	}

	return 0;
}
