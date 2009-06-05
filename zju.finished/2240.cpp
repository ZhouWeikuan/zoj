#include<iostream>
#include<vector>

using namespace std;
char buf[840];
vector<char> single;
void flushbefore(){
	if(single.size()==0)
		return;
	cout<<1;
	for(int i=0;i<single.size();i++){
		if(single[i] == '1'){
			cout<<1;
		}
		cout<<single[i];
	}
	cout<<1;
	single.clear();
}

void parse(){
	int i = 1;
	int ref = 0;
	if(buf[0]==0)
		return;

	while(buf[i]){
		if(buf[i] == buf[i-1]){
			flushbefore();
			ref ++;
			if(ref >= 8){
				cout<<9<<buf[i];
				ref -= 9;
			}
		} else {
			if(ref){
				cout<<(ref + 1) << buf[i-1];
				ref = 0;
			} else {
				single.push_back(buf[i-1]);
			}
		}
		i ++;
	}
	if(ref ==0){
		single.push_back(buf[i-1]);
		flushbefore();
	} else if(ref > 0){
		cout<<(ref+1)<<buf[i-1];
	}
}

int main(){
	
	while(cin.getline(buf,840)){
		parse();
		cout<<endl;
	}
	
	return 0;
}
