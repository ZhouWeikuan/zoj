#include<set>
#include<iostream>

using namespace std;

int  num;
int pos;
int retnum, figure;

void fun(){
	int i,t;
	set<int> mark;
	int quot;
	
	for(figure = 1; figure < 10; figure++){
		retnum = 1;
		quot = figure % num; 
		if(quot ==0){
			return ;
		}
		mark.clear();
		while(mark.find(quot) == mark.end()){
			mark.insert(quot);
			quot *= 10;
			quot += figure;
			quot %= num;
			retnum++;
			if(quot ==0){
				return;
			}
		}


	}
	
	retnum = -1;
	return ;	
}

int main(){
	int t;
	while(cin>>num){
		if(num < 0)
			cout<<"-1"<<endl;
		else if(num ==0)
			cout<<"0 1"<<endl;
		else {
			fun();
			if(retnum > 0)
				cout<<(figure) <<" " <<(retnum) <<endl;
			else 
				cout<<"-1"<<endl;
		}
	}	

	return 0;
}
