#include<iostream>
#include<set>

using namespace std;
enum {
	Un,   	//未涉及
	Not,	//排除
	Low,	//太轻
	High,	//太重
};
struct Node {
	char cmp;
	set<int> left;
	set<int> right;
};
Node tree[100];
int N,K;
set<int>::iterator li,ri;
int test(int cur){
	int i;
	int state = Un;
	Node *p;
	for(i=0;i<K;i++){
		p = &tree[i];
		if(p->cmp == '='){
			if(p->left.find(cur)!= p->left.end() 
				||p->right.find(cur)!=p->right.end()){
				return 0;
			}
		} else if(p->cmp =='<'){
			li = p->left.find(cur);
			ri = p->right.find(cur);
			if(li == p->left.end() && ri==p->right.end()){
				return 0;
			}else if(li != p->left.end()){
				if(state == Un){
					state = Low;
				} else if(state == High){
					return 0;
				}
			} else {
				if(state == Un){
					state = High;
				} else if(state == Low){
					return 0;
				}
			}
		} else {// '>'
			li = p->left.find(cur);
			ri = p->right.find(cur);
			if(li == p->left.end() && ri== p->right.end()){
				return 0;
			} else if(li != p->left.end()){
				if(state == Un){
					state = High;
				} else if(state == Low){
					return 0;
				}
			} else{ // ri!=p->right.end()
				if(state == Un){
					state = Low;
				} else if(state == High){
					return 0;
				}
			}
		}
	}
	return 1;
}

void fun(){
	int i,j,ret = 0;
	cin>>N>>K;
	for(i=0;i<K;i++){
		int t,p;
		cin>>t;
		tree[i].left.clear(); tree[i].right.clear();
		for(j=0;j<t;j++){
			cin>>p;
			tree[i].left.insert(p);
		}
		for(j=0;j<t;j++){
			cin>>p;
			tree[i].right.insert(p);
		}
		cin>>tree[i].cmp;
	}
	for(i=1;i<=N;i++){
		if(test(i)){
			if(ret){
				ret = -1;
				break;
			}else{
				ret = i;
			}
		}
	}
	if(ret <=0){
		cout<<0<<endl;
	}else{
		cout<<ret<<endl;
	}
}

int main(){
	int tstnum;

	cin>>tstnum;
	while(tstnum--){
		fun();
		if(tstnum)
			cout<<endl;
	}

	return 0;
}
