#include<iostream>
#include<map>

// 每次均设某个数最后取出，则...
//
using namespace std;

int card[100];
int num;
map<int,int> table;
map<int,int>::iterator iter;

int fun(int s, int e){
	if(e -s <2)
		return 0;
	int key = (s<<16) + e;
	iter = table.find(key);
	if(iter != table.end()){
		return iter->second;
	}
	int i;
	int mini = 0x7fffffff,score;
	for(i=s+1; i<e;i++){
		score = fun(s,i) + fun(i,e) + card[s]*card[i]*card[e];
		if(score < mini){
			mini=score;
		}
	}
	
	table[key] = mini;
	return mini;
}

int main(){
	int i;
	
	while(cin>>num){
        for(i=0;i<num;i++){
            cin>> card[i];
        }
		table.clear();
        cout<< fun(0,num-1) << endl;
    }
	return 0;
}
