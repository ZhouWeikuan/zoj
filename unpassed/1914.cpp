// wrong answer
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;
const double MaxValue = 10000000000.0;
double mat[504][504];
struct Point {
	double x,y;
};
struct cmp {
	bool operator()(const int &a, const int &b){
		return mat[a>>8][a&0x0ff] > mat[b>>8][b&0x0ff];
	}
};
int snum,pnum;
Point pnt[504];
int    pred[504];
double getDis(Point &a, Point &b){
	double t = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	return sqrt(t);
}
int getPar(int a){
	int p = pred[a];
	int t = pred[p];
	while(t!= p){
		p = t;
		t = pred[p];
	}
	pred[a] = t;
	return t;
}
int conn(int a, int b){
	int pa = getPar(a);
	int pb = getPar(b);
	if(pa == pb)
		return 0;
	int t = pa<pb?pa:pb;
	pred[pa] = t;
	pred[pb] = t;
	return 1;
}

double fun(){
	int i,j;
	double d;
	priority_queue<int,vector<int>,cmp> q;
	for(i=0;i<pnum;i++){
		pred[i] = i;
		for(j=0;j<i;j++){
			q.push((i<<8) + j);
		}
	}
	pnum -= snum;
	while(pnum){
		i = q.top(); q.pop();
		j = i &0x0ff; i>>=8;
		if(conn(i,j)){
			if(--pnum==0){
				return mat[i][j];
			}
		}
	}
}

int main(){
	int tstcase;
	int i,j;
	cin>>tstcase;
	while(tstcase--){
		cin>>snum>>pnum;
		for(i=0;i<pnum;i++){
			cin>>pnt[i].x>>pnt[i].y;
			for(j=0;j<i;j++){
				mat[i][j] = getDis(pnt[i],pnt[j]);
			}
		}
		double t = fun();
		printf("%.2lf\n",t);
	}
	return 0;
}
