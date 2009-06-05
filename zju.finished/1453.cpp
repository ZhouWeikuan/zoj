#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
struct Node {
	int x;
	int y;
	double ang;
};
Node tree[104];
int num;
int save[104], top;

struct cmp{
	bool operator()(const Node &a, const Node &b){
		if( fabs(a.ang - b.ang)<0.00001){
			return a.x < b.x;
		}
		return a.ang < b.ang;
	}
};

int readIn(){
	int least = 0,i;
	cin>>num;
	if(num==0)
		return num;
	for(i=0;i<num;i++){	
		cin>>tree[i].x>>tree[i].y;
		if(tree[i].x < tree[least].x){
			least = i;
		}else if(tree[i].x == tree[least].x 
			&& tree[i].y < tree[least].y ){
			least = i;
		}
	}
	int t;
	t = tree[least].x; tree[least].x = tree[0].x; tree[0].x = t;
	t = tree[least].y; tree[least].y = tree[0].y; tree[0].y = t;
	tree[0].ang = 0;
	for(i=1;i<num;i++){
		tree[i].x -= tree[0].x;
		tree[i].y -= tree[0].y;
		if(tree[i].x ==0){
			if(tree[i].y > 0){
				tree[i].ang = 60000;
			} else {
				tree[i].ang = -60000;
			}
		} else {
			tree[i].ang = tree[i].y;
			tree[i].ang /= tree[i].x;
		}
	}
	tree[0].x = tree[0].y = 0;
	sort(tree+1, tree+num,cmp());
	return num;
}
int direct(int a,int b,int c){
	return (tree[b].x - tree[a].x)*(tree[c].y - tree[a].y) 
			-(tree[c].x - tree[a].x)*(tree[b].y - tree[a].y);
}
double dis(int a, int b){
	double x,y;
	x = tree[a].x - tree[b].x;
	y = tree[a].y - tree[b].y;
	x *= x;
	y *= y;
	x += y;
	return sqrt(x);
}

void fun(){
	if(num==1){
		printf("0.00\n");
		return;
	}
	top = 0;
	save[top++] = 0;
	save[top++] = 1;
	for(int i=2;i<num;i++){
		while(direct(save[top-2],save[top-1],i) < 0){
			top--;
		}
		save[top++] = i;
	}
	double ret = 0;
	for(int i=1;i<top;i++){
		ret += dis(save[i-1],save[i]);
	}
	ret += dis(save[0],save[top-1]);
	printf("%.2lf\n", ret);
}

int main(){

	while(readIn()){
		fun();
	}

	return 0;
}
