#include<iostream>
#include<cmath>
//向量计算 + 角度计算 
using namespace std;
int cx,cy;
double radius;
const double eps=1e-7;
struct Point {
	double ang;
};

int num, base;
Point tree[320];

int cmp(Point *a, Point *b){
	if(a->ang < b->ang)
		return -1;
	else if(a->ang > b->ang )
		return 1;
	return 0;
}

int readIn(){
	int x,y,j=0;
	cin>>cx>>cy>>radius;
	if(radius < 0)
		return 0;
	radius *= radius;
	base = 0;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>x>>y;
		x -= cx; y-= cy;
		if(x*x + y*y <= radius){
			if(x ==0 ){
				if(y==0){
					base ++;
				} else {
					tree[j].ang = M_PI/2;
				}
			} else if(y==0) {
				if(x > 0)
					tree[j].ang = 0;
				else 
					tree[j].ang = M_PI;
			} else {
				tree[j].ang = y;
				tree[j].ang /= x;
				if(tree[j].ang < 0){
					tree[j].ang = atan(tree[j].ang) + M_PI;
				} else {
					tree[j].ang = atan(tree[j].ang);
				}

			}
			if(y < 0){
				tree[j].ang += M_PI;
			}
			j++;
		}
	}
	num = j;
	return 1;
}
int find(double v){
	int low = 0,high=num;
	int mid;
	while(low < high){
		mid = (low + high)/2;
		if(tree[mid].ang <= v){
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	while(mid >=0&& tree[mid].ang>v){
		mid--;
	}
	while(mid < num && tree[mid].ang <= v + eps){
		mid++;
	}
	return mid;
}
int fun(){
	qsort(tree,num,sizeof(Point), (int (*)(const void*,const void*))cmp);
	int ret = 0,t;
	double lim = 2 * M_PI;
	for(int i=0; i< num &&tree[i].ang+eps<=lim;i++){
		t = find(tree[i].ang + M_PI);
		if(t -i > ret){
			ret = t-i;
		}
		if(t < num && tree[t].ang < lim){
			lim = tree[t].ang;
		}
	}
	ret += base;
	return ret;
}

int main(){

	while(readIn()){
		cout<<fun()<<endl;
	}
	return 0;
}
