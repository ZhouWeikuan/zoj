#include<iostream>
#include<algorithm>

using namespace std;
enum {
	Size = 24 * 24 + 1,
};
struct Node {
	int x;
	int y;
};

Node garb[Size];
int pos;
Node *last[60];

int mycomp(const Node &a, const Node &b){
	if(a.x != b.x)
		return a.x > b.x;
	return a.y > b.y;
}

int fun(){
	int num = 0, i ,j;
	if(pos ==0)
		return pos;
	last[num++ ] = &garb[0];
	
	for(i=1;i<pos;i++){
		for(j=0;j<num;j++){
			if(garb[i].x <= last[j]->x && garb[i].y <= last[j]->y){
				last[j] = &garb[i];
				break;
			}
		}
		if(j==num){
			last[num++ ] = &garb[i];
		}
	}
	return num;
}

int main(){
	
	cin>>garb[0].x >> garb[0].y;
	while(garb[0].x >=0 && garb[0].y>=0){
		pos = 0;
		while(garb[pos].x > 0 && garb[pos].y >0){
			pos ++;
			cin>> garb[pos].x >> garb[pos].y;
		}
		sort(garb,garb+pos, mycomp);
		
		cout<< fun() << endl;
		
		cin>>garb[0].x >> garb[0].y;
	}

	return 0;
}
