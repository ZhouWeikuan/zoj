#include<iostream>
#include<string>
#include<set>

using namespace std;

set<string > good, bad;
set<string>::iterator iter;
int num;
int fun(){
    int i,j;
  	string s;
    for(i = 0; i< num; i ++){
		cin>>s;
		iter = bad.find(s);
		if(iter == bad.end()){
			good.insert(s);
		}
		cin>>j;
		while(j--){
			cin>>s;
			iter = good.find(s);
			if(iter != good.end()){
				good.erase(s);
			}
			bad.insert(s);
		}
	}
	for(iter = good.begin(); iter != good.end(); iter++){
		cout<<(*iter)<<endl;
	}
	good.clear();
	bad.clear();
	return 0;
}

int main(){
  	int tstcase = 0;
  	while(cin>>num){
		if(tstcase ++ ){
			cout<<endl;
		}
		fun();
	}
    
    return 0;
}
