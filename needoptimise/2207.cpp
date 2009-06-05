#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct Node {
	int perm[5];
	int score;
	int pos;
};
Node node[200];

struct cmp {
	int operator()(int &a, int &b){
		if(node[a].score != node[b].score)
			return node[a].score > node[b].score;
		int i;
		for(i=0;i<node[a].pos&&i<node[b].pos;i++){
			if(node[a].perm[i]!= node[b].perm[i]){
				return node[a].perm[i] > node[b].perm[i];
			}
		}
		return node[a].pos > node[b].pos;
	}
};

int matrix[2][5][5];
char buf[8];

void parse(){
	int i,t;
	int bitmap[5] = {0};
	for(i=0;i<5;i++){
		t = buf[i] -'A';
		bitmap[t] = i;
	}
	for(i=0;i<4;i++){
		for(t=i+1;t<5;t++){
			if(bitmap[i] < bitmap[t]){
				matrix[0][i][t]++;
			} else {
				matrix[1][i][t]++;
			}
		}
	}
}

int select(void){
	int start=1,root=0,cur,i,loc;
	node[root].perm[0] = 0;
	node[root].pos = 1;
	node[root].score = 0;

	priority_queue<int,vector<int>, cmp> q;
	q.push(root);

	while(!q.empty()){
		cur = q.top(); q.pop();
		Node &curnode = node[cur];

		if(curnode.pos == 5)
			break;
		for(loc=0;loc<=curnode.pos;loc++){
			node[start].score = curnode.score;
			for(i=0;i<loc;i++){
				node[start].perm[i] = curnode.perm[i];
				node[start].score += matrix[1][curnode.perm[i]][curnode.pos];
			}
			node[start].perm[loc] = curnode.pos;
			node[start].pos = curnode.pos + 1;
			for(i=loc+1;i<node[start].pos;i++){
				node[start].perm[i] = curnode.perm[i-1];
				node[start].score += matrix[0][node[start].perm[i]][curnode.pos];
			}
			q.push(start);
			start++;
		}
	}
	for(i=0;i<5;i++){
		buf[i] = node[cur].perm[i] + 'A';
	}
	buf[5] = 0;
	return node[cur].score;
}

int main(){
	int num;

	cin>>num;
	while(num){
		memset(matrix,0,sizeof(matrix));
		while(num--){
			cin>>buf;
			parse();
		}

		num = select();

		cout<<buf<<" is the median ranking with value "
			<< num <<"."<<endl;

		cin>>num;
	}

	return 0;
}
