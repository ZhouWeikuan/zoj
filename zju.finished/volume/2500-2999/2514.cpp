#include<iostream>
#include<string>

using namespace std;
struct Node {
	string team;
	string pass;
};

Node tree[1008];
int treenum, pos;
int point[1008];

int getinput(){
	pos = 0;
	cin>>treenum;
	for(int i=0;i<treenum;i++){
		cin>>tree[i].team>>tree[i].pass;
	}
	return treenum;
}

void changepass(){
	int i;
	string::iterator iter;
	bool change;
	for(i=0;i<treenum;i++){
		change = false;
		for(iter=tree[i].pass.begin(); iter!=tree[i].pass.end(); iter++){
			switch(*iter){
				case '1':
					*iter = '@';
					change=true;break;
				case '0':
					*iter = '%';
					change=true;break;
				case 'l':
					*iter = 'L';
					change = true;break;
				case 'O':
					*iter = 'o';
					change=true;
					break;
				default:
					break;
			}
		}
		if(change==true){
			point[pos++] = i;
		}
	}
}

void output(){
	if(pos==0){
		cout<<"No account is modified."<<endl;
		return;
	}
	cout<<pos<<endl;
	Node *p;
	for(int i=0;i<pos;i++){
		p = &tree[point[i]];
		cout<<p->team<<" "<<p->pass<<endl;
	}
}
int main(){

	while(getinput()){
		changepass();
		output();
	}

	return 0;
}
