#include<iostream>
#include<vector>
#include<list>

using namespace std;
vector<int> rest;
void init(){
	int i,t;
	list<int>::iterator iter;
	list<int> gen;
	for(i=0;i<33900;i++){
		gen.push_back(i+2);
	}
	while(gen.size()){
		iter = gen.begin();
		t = *iter;
		rest.push_back(t);
		iter = gen.erase(iter);
		t --;
		i = 0;
		while(iter != gen.end()){
			if(i == t){
				iter = gen.erase(iter);
				i= 0;
			} else {
				iter ++, i++;
			}
		}
	}
}

int main(){
	int num;	
	init();

	cin>>num;
	while(num){
		num--;
		cout<<rest[num]<<endl;

		cin>>num;
	}

	return 0;
}
