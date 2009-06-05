#include<iostream>
#include<set>

using namespace std;
int remind[5000];
int divor;
int num[10],pos;
struct Node {
	int pred;
	int remind;
	int cur;
};

Node leaf[100000];

void trace(int n){
	if(leaf[n].pred == -1){
		cout<<leaf[n].cur;
		return;
	}
	trace(leaf[n].pred);
	cout<<leaf[n].cur;
}
void fun(){
	if(divor == 0){
		cout<<0<<endl;
		return;
	}
	memset(remind,0,sizeof(int)*divor);
	int start = 0,i;
	for(i=0;i<pos;i++){
		leaf[i].pred = -1; leaf[i].remind=0; leaf[i].cur= num[i];
	}
	start = pos;
	int v,j;
	i = 0;
	for(;i < start;){
		leaf[i].remind *= 10;
		leaf[i].remind += leaf[i].cur;
		v = leaf[i].remind % divor;
		if(leaf[i].remind < divor || v){
			if(remind[v] == 0){
				remind[v] = 1;
				for(j =0;j < pos; j++){
					leaf[start].pred = i; leaf[start].remind = v;
					leaf[start].cur = num[j];
					start++;
				}
			}
		} else {
			break;
		}
		i++;
	}
	if( i == start){
		cout<<0<<endl;
		return;
	}
	trace(i);
	cout<<endl;
}

int main(){	
	int i;
	while(cin>>divor){
		cin>>pos;
		for(i=0;i<pos;i++){
			cin>>num[i];
		}
		sort(num,num+pos);
		fun();
	}
	
	return 0;
}
