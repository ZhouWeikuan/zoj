#include<iostream>
#include<algorithm>

using namespace std;

int rope[1008];
int num;

int main(){
	int tstcase;
	int max,t;
	
	cin>>tstcase;

	while(tstcase --){
		cin>>num;
		for(int i=0;i<num;i++){
			cin>>rope[i];
		}
		sort(rope, rope+num);
		max = 0;
		for(int i=num-1;i>=0;i--){
			t = rope[i] * (num-i);
			if(max < t)
				max = t;
		}
		cout<<max<<endl;

	}
	
	return 0;
}
