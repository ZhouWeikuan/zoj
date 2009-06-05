#include<iostream>
#include<queue>

using namespace std;
int N,A,B;
int board[84][84];
int eval[84][84];
struct Node {
	int x;
	int y;
	int step;
	struct cmp {
		int operator()(const Node &a, const Node &b){
			return a.step > b.step;
		}
	};
};
typedef priority_queue<Node,vector<Node>, Node::cmp> mypq;

void getInput(){
	int i,j;
	char ch;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cin>>ch;
			if(ch=='W'){
				board[i][j] = 1;
			} else if(ch =='B'){
				board[i][j] = 2;
			} else { // 'U'
				board[i][j] = 0;
			}
		}
	}
}

void addNode(mypq &q, Node &one, int v){
	if(board[one.x][one.y] == v){
		if(eval[one.x][one.y] > one.step){
			eval[one.x][one.y] = one.step;
			q.push(one);
		}
	}else if(board[one.x][one.y] == 0){
		one.step ++;
		if(eval[one.x][one.y] > one.step ){
			eval[one.x][one.y] = one.step;
			q.push(one);
		}
	}
}

void getPathB(){
	mypq q;
	Node one;
	int i,j;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			eval[i][j] = 99999999;
		}
	}

	one.x = 0;
	for(i=0;i<N;i++){
		one.y = i;
		if(board[0][i] == 2){
			one.step = 0;
			eval[0][i] = 0;
			q.push(one);
		} else if(board[0][i] == 0){
			one.step = 1;
			eval[0][i] = 1;
			q.push(one);
		}
	}
	while(!q.empty()){
		Node cur = q.top();
		if(cur.step > eval[cur.x][cur.y]){
			goto end;
		}
		if(cur.x == N-1){
			B = cur.step;
			return;
		}
		if(cur.x > 0){ // above
			one.x = cur.x -1; one.y = cur.y;
			one.step = cur.step;
			addNode(q,one,2);
		}
		if(cur.x < N-1){ //below
			one.x = cur.x + 1; one.y = cur.y;
			one.step = cur.step;
			addNode(q,one,2);
		}
		if(cur.y > 0){ // left
			one.y = cur.y -1; one.x = cur.x;
			one.step = cur.step;
			addNode(q,one,2);
		}
		if(cur.y < N-1){ // right
			one.y = cur.y + 1; one.x = cur.x;
			one.step = cur.step;
			addNode(q,one,2);
		}

	end:
		q.pop();
	}
	B = -1;
}

void getPathA(){
	mypq q;
	Node one;
	int i,j;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			eval[i][j] = 99999999;
		}
	}

	one.y = 0;
	for(i=0;i<N;i++){
		one.x = i;
		if(board[i][0] == 1){
			one.step = 0;
			eval[i][0] = 0;
			q.push(one);
		} else if(board[i][0] == 0){
			one.step = 1;
			eval[i][0] = 1;
			q.push(one);
		}
	}
	while(!q.empty()){
		Node cur = q.top();
		if(cur.step > eval[cur.x][cur.y]){
			goto end;
		}
		if(cur.y == N-1){
			A = cur.step;
			return;
		}
		if(cur.x > 0){ // above
			one.x = cur.x -1; one.y = cur.y;
			one.step = cur.step;
			addNode(q,one,1);
		}
		if(cur.x < N-1){ //below
			one.x = cur.x + 1; one.y = cur.y;
			one.step = cur.step;
			addNode(q,one,1);
		}
		if(cur.y > 0){ // left
			one.y = cur.y -1; one.x = cur.x;
			one.step = cur.step;
			addNode(q,one,1);
		}
		if(cur.y < N-1){ // right
			one.y = cur.y + 1; one.x = cur.x;
			one.step = cur.step;
			addNode(q,one,1);
		}

	end:
		q.pop();
	}
	A = -1;
}

int main(){
	cin>>N;
	while(N){
		getInput();
		getPathA();
		if(A  != 0){
			getPathB();
		}
		if(A == 0){
			cout<<"White has a winning path."<<endl;
		} else if(B == 0){
			cout<<"Black has a winning path."<<endl;
		} else if(A == 1){
			cout<<"White can win in one move."<<endl;
		} else if (B == 1){
			cout<<"Black can win in one move."<<endl;
		} else {
			cout<<"There is no winning path."<<endl;
		}
		cin>>N;
	}
	
	return 0;
}
