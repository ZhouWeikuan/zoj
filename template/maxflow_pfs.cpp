#include<iostream>
#include<queue>
#include<vector>

using namespace std;

enum {
	N = 20,
};

int num, s,t;
int pred[N];
int minimum[N];
int matrix[N][N];
int mark[N];

struct MyComp {
	int operator()(const int& a, const int& b){
		return minimum[a] < minimum[b];
	}
};

int pfs(priority_queue<int,vector<int>, MyComp > &q){
	int n,i;
	while(! q.empty()){
		n = q.top(); q.pop();
		if(n == t){
			break;
		}
		for(i=0;i<num;i++){
			if(!mark[i] && matrix[n][i]){
				mark[i] = 1;
				q.push(i);
				pred[i] = n;
				minimum[i] = minimum[n] > matrix[n][i]?matrix[n][i]:minimum[n];
			}
		}
	}
	if(n != t)
		return 0;
	int d = minimum[n];
	while(n != s){
		i = pred[n];
		matrix[i][n] -= d;
		matrix[n][i] += d;
		n = i;
	}
	return d;
}

int maxflow(){
	int i;
	priority_queue<int,vector<int>, MyComp > q;
	
	memset(mark,0,sizeof(mark));
	for(i=0;i<num;i++){
		if(matrix[s][i]){
			mark[i] = 1;
			q.push(i);
			pred[i] = s;
			minimum[i] = matrix[s][i];
		}
	}
	i = 0;
	if(! q.empty()){
		i = pfs(q);
	}
	return i;
}

int main(){
	int d = 0, sum = 0;
	int a,b,c;
	cin>>d>>num>>s>>t;

	while(d --){
		cin>>a>>b>>c;
		matrix[a][b] = c;
	}	
	while(d = maxflow()){
		sum += d;
	}
	cout<<sum<<endl;
}
