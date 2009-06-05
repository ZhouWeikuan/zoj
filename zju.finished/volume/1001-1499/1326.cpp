#include<iostream>
#include<vector>
using namespace std;
int poke[20];
int num,guy;
vector<int> pos;

void fun(){
	int flag = 0;
	int i;
	int cur;
	vector<int>::iterator iter;
	for(i=0;i<20 && flag ==0;i++){
		if(pos.size() == guy){
			flag =1 ;
			break;
		}
		iter 	= pos.begin();
		cur		= 1;
		while(iter != pos.end()){
			if(cur == poke[i]){
				iter=pos.erase(iter);
				cur = 1;
				if(pos.size() == guy){
					flag = 1;
					break;
				}
			} else {
				iter ++, cur++;
			}
		}
	}
	iter = pos.begin();
	cout<<*iter;
	for(iter++; iter!=pos.end();iter++){
		cout<<" "<<*iter;
	}
	cout<<endl;
}

int main(){
	int tstcase = 0;
	int i;
	
	while(cin>>num>>guy){
		pos.clear();
		for(i=0;i<num;i++)
			pos.push_back(i+1);
		for(i=0;i<20;i++){
			cin>>poke[i];
		}
		cout<<"Selection #"<<++tstcase<<endl;
		fun();
		cout<<endl;
	}
	return 0;
}
