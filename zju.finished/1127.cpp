#include<iostream>
#include<vector>

using namespace std;

vector<int> city[32];
vector<char> result;
int dist[32];
int num;

void update(int n){
	int i,t;
	for(i=0;i<city[n].size();i++){
		t = city[n][i];
		if(dist[n]+1 < dist[t]){
			dist[t] = dist[n] + 1;
			update(t);
		}
	}
}

int getmost(){
	int i, max, p = 0;
	max = 0;
	for(i=0;i<num;i++){
		if(dist[i] > max){
			max = dist[i];
			p = i;
		}
	}
	return p;
}

int main(){
	char start;
	int  fnum;
	cin>>num>>start>>fnum;
	result.clear();
	for(int i=0;i<num;i++){
		city[i].clear();
		dist[i] = 40;
	}
	char a,b;
	while(cin>>a>>b){
		a-='A', b-='A';
		city[a].push_back(b);
		city[b].push_back(a);
	}
	result.push_back(start);
	dist[start -'A' ] = 0;
	fnum --;
	while(fnum){
		update(start-'A');
 		start = getmost() + 'A';
		dist[start-'A'] = 0;
		result.push_back(start);
		fnum --;
	}
	
	cout<<"Program 8 by team X"<<endl;
	cout<<result[0];
	for(int i=1;i<result.size();i++){
		cout<<" "<<result[i];
	}
	cout<<endl<<"End of program 8 by team X"<<endl;
	
	return 0;
}
