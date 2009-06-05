#include<cstdio>
#include<queue>
#include<vector>

using namespace std;
struct Node {
	int id;
	int time;
	int period;
};

Node tree[1008];
struct cmp{
	int operator()(const int &a, const int &b){
		if(tree[a].time != tree[b].time)
			return tree[a].time > tree[b].time;
		return tree[a].id > tree[b].id;
	}
};
priority_queue<int, vector<int>, cmp> q;

int main(){
	char buf[20];
	int i = 0;
	int num;
	
	scanf("%s",buf);
	while(buf[0]!= '#'){
		scanf("%d %d", &tree[i].id, &tree[i].period);
		tree[i].time = tree[i].period;
		q.push(i);
		i++;

		scanf("%s",buf);
	}
	scanf("%d",&num);

	while(num--){
		i = q.top(); q.pop();
		printf("%d\n",tree[i].id);
		tree[i].time += tree[i].period;
		q.push(i);
	}

	return 0;
}
