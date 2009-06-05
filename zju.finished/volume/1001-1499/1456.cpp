#include<iostream>
#include<vector>
#include<queue>

using namespace std;
enum {
	Size = 50,
};
int N;
int source,sink;
unsigned edge[Size][Size];
unsigned fee[Size];
int save[Size],sp;
int stack[Size], top;
unsigned cost[Size];

int getinput(){
	cin>>N;
	if(N==0)
		return 0;
	int i,j,t;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cin>>edge[i][j];
			edge[i][j] &=0x0ffffff;
		}
	}
	for(i=0;i<N;i++){
		cin>>fee[i];
	}
	return 1;
}
void init(){
	for(int i=0;i<N;i++){
		cost[i] = 0x0ffffff;
	}
}
void print(){
	int i;
	sp --;
	for(i=0;i<sp;i++){
		cout<<(save[i]+1)<<"-->";
	}
	cout<<(save[sp]+1)<<endl;
}
void save_st(){
	sp = top;
	for(int i=0;i<sp;i++){
		save[i] = stack[i];
	}
}
int trace(int node){
	stack[top++] = node;
	if(node == sink){
		save_st();
		--top;
		return 1;
	}
	int i,cur;
	cur = cost[node] + fee[node];
	for(i=N-1;i>=0;i--){
		if(cur + edge[node][i] > cost[i])
			continue;
		cost[i] = cur + edge[node][i];
		trace(i);
	}
	--top;
}

void fun(){
	if(source == sink){
		cout<<"From "<<(sink+1)<<" to "<<(sink+1)<<" :"<<endl;
		cout<<"Path: "<<(sink+1)<<endl;
		cout<<"Total cost : 0"<<endl;
		return;
	}
	
	int cur,i;
	cost[source] = 0;
	top = 0;
	stack[top++] = source;
	for(int i=N-1;i>=0;i--){
		if(i==source)
			continue;
		if(edge[source][i] <= cost[i]){
			cost[i] = edge[source][i];
			trace(i);
		}
	}

	cout<<"From "<<source+1<<" to "<<sink+1<<" :"<<endl;
	cout<<"Path: ";
	print();
	cout<<"Total cost : "<<cost[sink]<<endl;
}

int main(){
	
	while(getinput()){
		cin>>source>>sink;
		while(source>0 && sink>0){
			source--,sink--;
			init();
			fun();
			cout<<endl;
			cin>>source>>sink;
		}
	}

	return 0;
}
