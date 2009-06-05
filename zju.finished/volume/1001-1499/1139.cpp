#include<iostream>

using namespace std;

struct Rect {
	int minx;
	int miny;
	int maxx;
	int maxy;
};

Rect point[10000];
int num;

int fun(){
	int i,j;
	int ret = 0;
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			if(i==j)
				continue;
			if(point[j].minx <= point[i].minx 
				&&point[j].miny <= point[i].miny
				&&point[j].maxx >= point[i].maxx
				&&point[j].maxy >= point[i].maxy){
				ret ++;
				break;
			}
		}
	
	}
	return ret;
}

int main(){
	int i;
	while(cin>>num){
		for(i=0;i<num;i++){
			cin>>point[i].minx>>point[i].maxx
			   >>point[i].miny>>point[i].maxy;
		}
		cout<<fun()<<endl;
	}

	return 0;
}
