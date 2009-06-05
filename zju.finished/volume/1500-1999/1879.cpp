#include<iostream>
#include<set>

using namespace std;

set<int> table;
int num;

int fun(){
    int pred,cur;
    int n = num;
    int flag = 1;
    cin>>pred;
    n--;
    
    table.clear();
    
    int value;
    while(n --){
		cin>>cur;
		if(flag ==0)
			continue;
		if(cur > pred){
			value = cur- pred;
		} else {
			value = pred - cur;
		}
		pred = cur;
		if(value==0 || value >=num){
			flag = 0;
		}
		if(table.find(value) != table.end()){
			flag = 0;
			continue;
		}
		table.insert(value);
	}
	return flag;
}

int main(){
    int t;
    
    while(cin>>num){
		t = fun();

		if(t){
			cout<<"Jolly"<<endl;
		} else {
			cout<<"Not jolly"<<endl;
		}
	}
    
    return 0;
}
