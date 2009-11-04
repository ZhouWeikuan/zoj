#include<iostream>

using namespace std;
struct Tree {
	int father;
	int child;
};

Tree tree[260];
int data[260];
int num;

void init(){
	int i;
	int node = 1<<num;
	for(i=1;i<=node;i++){
		tree[i].father = tree[i].child = 0;
		data[i-1] = i;
	}
	int j,t;
	node >>=1;
	while(node){
		j=0;
		for(i=0;i<node;i++){
			cin>>t;
			if(t == data[2*i]){
				tree[data[2*i+1]].father = t;
				tree[t].child += 1 + tree[data[2*i+1]].child;
			} else {
				tree[data[2*i]].father = t;
				tree[t].child += 1+ tree[data[2*i]].child;
			}
			data[j++] = t;
		}
		node>>=1;
	}
}

int getparent(int node){
	int ret = 0;
	int p = tree[node].father;
	while(p){
		ret ++;
		node = p;
		p = tree[node].father;
	}
	return ret;
}

void fun(){
	int tst;
	int node;
	int fnum;
	int total = 1<<num;
	cin>>tst;
	while(tst--){
		cin>>node;
		fnum = getparent(node);
		cout<<"Player "<<node<<" can be ranked as high as "
			<<(fnum+1)<<" or as low as "<<(total-tree[node].child)<<"."<<endl;
	}
}

int main(){
	int tstcase = 0;
	
	cin>>num;
	while(num){
		if(tstcase++)
			cout<<endl;
		init();
		fun();
		cin>>num;
	}

	return 0;
}
