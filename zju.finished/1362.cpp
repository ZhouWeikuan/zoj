#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;
int mask[1004];
int cards[54];
deque<int> d;
int player,card;

int fun(){
	d.clear();
	int i,ret =0;
	for(i=player*card;i>0;i--){
		if(mask[i] ==0){
			d.push_back(i);
		}
	}
	sort(cards,cards+card,greater<int>());
	for(i=0;i<card;i++){
		if(cards[i] > d[0]){
			ret++;
			for(int j=1;j<player;j++){
				d.pop_back();
			}
		} else {
			d.pop_front();
			for(int j=2;j<player;j++){
				d.pop_back();
			}
		}
	}
	return ret;
}

int main(){
	int i,tstnum=0;

	cin>>player>>card;
	while(player){
		memset(mask,0,sizeof(mask));
		for(i=0;i<card;i++){
			cin>>cards[i];
			mask[ cards[i] ] = 1;
		}
		cout<<"Case "<<++tstnum<<": ";
		cout<<fun()<<endl;

		cin>>player>>card;
	}

	return 0;
}
