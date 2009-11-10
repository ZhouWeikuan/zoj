#include<iostream>
#include<map>

using namespace std;

map<int,int> table;
int N,Q;

int main(){
	int i;
	int n,t;
	int max, mp;
	
	cin>>N>>Q;
	while(N ){
		table.clear();
		for(i=0;i<N;i++){
			cin>>n;
			while(n--){
				cin>>t;
				table[t] ++;
			}
		}
		map<int,int>::iterator iter;
		max = mp = 0;
		for(iter= table.begin(); iter!= table.end(); iter++){
			if(iter->second >= Q){
				if(iter->second > max){
					max = iter->second;
					mp = iter->first;
				}
			}
		}
		if(max){
			printf("%d\n", mp);
		} else {
			printf("0\n");
		}
		cin>>N>>Q;
	}

	return 0;
}
