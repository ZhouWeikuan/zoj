#include<iostream>
#include<map>
#include<set>

using namespace std;
struct Node {
	unsigned id;
	char type;
};

set<unsigned> block;
map<unsigned, Node> lock;
map<unsigned, Node>::iterator iter;

void fun(){
	Node one;
	unsigned item;

	cin>>one.type;
	while(one.type != '#'){
		cin>>one.id>>item;
		if(block.find(one.id)!= block.end()){
			cout<<"IGNORED"<<endl;
		} else {
			iter = lock.find(item);
			if(iter == lock.end()){
				lock[item] = one;
				cout<<"GRANTED"<<endl;
			} else {
				if(iter->second.id != one.id 
					||iter->second.type=='X'
					|| one.type == 'X'){
					cout<<"DENIED"<<endl;
					block.insert(one.id);
				} else {
					cout<<"GRANTED"<<endl;
				}
			}
		}
		
		cin>>one.type;
	}
}

int main(){
	int tstcase;
	//cin>>tstcase;
	tstcase =1;
	while(tstcase --){
		block.clear();
		lock.clear();
		fun();
		if(tstcase) {
			cout<<endl;
		}
	}

	return 0;
}
