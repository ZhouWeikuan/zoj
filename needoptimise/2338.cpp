#include<iostream>
#include<queue>


// 构造法，分叉出不同的结点，每个结点的可分叉不同 
using namespace std;

struct Node {
	int childnum;	
	int child[80];
	int peg;
	int newpeg;
	int code;	
	int type;
};

Node disk[80];
int disknum, pegnum;
int peg[80][80];
int top[80];

int mark_code(int n){
	int i;
	int ret = 0;
	Node *cur = &disk[n];
	cur->code = disknum--;
	
	for(i=0;i<cur->childnum;i++){
		ret += mark_code(cur->child[i]);
	}
/*	cout<<" cur : "	<< disk[n].code <<endl <<"child: ";
	for(i=0;i<cur->childnum;i++){
		cout<<disk[cur->child[i]].code<<" ";
	}
	cout<<endl; 			*/
	
	ret *= 2;
	ret += 1;
	return ret;
}

void init(){	
	int finish = 1;
	int child;
	int start = 1;
	int i;
	
	Node *cur = &disk[0];
	Node *next;
	queue<int> q;
	
	cur->childnum = 0;
	cur->peg = 1;	
	cur->type = pegnum - 2;
	cur->newpeg = pegnum;
	
	q.push(0);
	while(finish < disknum){
		i = 0;
		cur = &disk[q.front()]; q.pop();
		child = 0;
		while(finish < disknum && child < cur->type){
			next = &disk[start];
			cur->child[cur->childnum++ ] = top[i++] = start ++;
			next->type = ++child;
			next->peg = 1;
			finish ++;
			next->childnum = 0;			
		}
		while(i > 0){
			q.push(top[--i]);
		}
	}
	
	for(i=1;i<=pegnum;i++){
		top[i] = -1;		
	}
	for(i=disknum;i>0;i--){
		peg[1][++top[1]] = i;
	}
	i = disknum;
	start = mark_code(0);		
	disknum = i;
	cout<<start<<endl;
}

int available(int pno, int val){
	int t = top[pno];
	return (t <0 || peg[pno][t] > val);
}

void do_move(int n){
	int i,p=1;
	int t;
	
	for(i=disk[n].childnum-1;i>=0; i--){
		t = disk[n].child[i];
		for(p=1;p<=pegnum;p++){
			if(p==disk[n].newpeg )
				continue;
			if(available(p,disk[t].code)){
				break;
			}
		}
		disk[t].newpeg = p;
		do_move(t);
	}
	
	p = disk[n].newpeg;
	cout<<"move "<<disk[n].code<<" from "<<disk[n].peg<<" to "<< p;
	
	peg[disk[n].peg][top[disk[n].peg]-- ] = 0;
	disk[n].peg = p;
	
	if(top[p] >= 0){
		cout<<" atop "<< peg[p][top[p]];
	}
	cout<<endl;	
	
	peg[p][++top[p]] = disk[n].code;
	
	for(i=0;i<disk[n].childnum; i++){
		t = disk[n].child[i];		
		disk[t].newpeg = p;
		do_move(t);
	}
	
}

int main(){
	int tstcase;
	cin>>tstcase;
	while(tstcase --){
		cin>>disknum>>pegnum;
		init();
		do_move(0);
		
		if(tstcase)
			cout<<endl;
	}
	
	return 0;
}
