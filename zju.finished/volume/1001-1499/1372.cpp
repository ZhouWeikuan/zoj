#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;
enum {
	Size = 52,
};
int matrix[Size][Size];
int mark[Size];
int pnum;

int diff(int i,int j){
	int a = i, b = j;
	while(mark[a] != 0){
		a = mark[a];
	}
	while(mark[b] != 0){
		b = mark[b];
	}
	if(a==b)
		return 0;
	if(a != i)
		mark[i] = a;
	if(b != j)
		mark[j] = b;
	if(a < b){
		mark[b] = a;
	} else {
		mark[a] = b;
	}
	return 1;
}

struct Comp{
	int operator()(const int a, const int b){
		return matrix[a>>8][a&0xff] > matrix[b>>8][b&0xff];
	}
};

int fun(){
	if(pnum <= 1)
		return 0;
	memset(mark, 0 ,sizeof(mark));
	priority_queue<int, vector<int>, Comp > que;
	int i,j;
	for(i=1;i<pnum;i++){
		for(j=i+1;j<=pnum;j++){
			if(matrix[i][j]){
				que.push( (i<<8) + j);
			}
		}
	}
	int cost = 0,t;
	while( !que.empty()){
		t = que.top(); que.pop();
		i = t >>8; j = t &0xff;
		if(diff(i,j)){
			cost += matrix[i][j];
		}
	}
	return cost;
}

int main(){
	int rels;
	int a, b,cost;

	cin>>pnum;
	while(pnum > 0){
		cin>>rels;
		memset(matrix,0,sizeof(matrix));
		while(rels --){
			cin>>a>>b >>cost;
			if(matrix[a][b] == 0 || matrix[a][b] > cost){
				matrix[a][b] = cost;
				matrix[b][a] = cost;
			}
		}
		cout<< fun()<< endl;
	
		cin>>pnum;
	}
	return 0;
}
