#include<iostream>
#include<map>

using namespace std;
map<int,int> tree;

int fun(){
	if(tree.size() ==0)
		return 1;
	int zeronum = 0;
	map<int,int>::iterator iter;
	for(iter=tree.begin(); iter!= tree.end(); iter++){
		if(iter->second == 0){
			zeronum ++;
		}else {
			if(iter->second !=1){
				return 0;
			}
		}
	}
	return zeronum==1;
}

int main(){
	int a, b;
	int tstcase =1;

	cin>>a>>b;
	while(a !=-1 && b != -1){
		tree.clear();
		while(a !=0 && b != 0){
			tree[a] = tree[a];
			tree[b] ++;
			cin>>a>>b;
		}

		cout<<"Case "<<tstcase++ <<" is ";
		if(fun() == 0)
			cout<<"not ";
		cout<<"a tree."<<endl;
		
		cin>>a>>b;
	}

	return 0;
}
