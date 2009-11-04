#include<iostream>
#include<set>

using namespace std;
char buffer[16000008];
int len;

struct Comp {
	int operator()(const int &a, const int& b){
		return strncmp(&buffer[a],&buffer[b],len) < 0 ;
	}
};

set<int,Comp> substr;

void fun(){
	int i;
	for(i=0;i<len;i++){
		if(buffer[i] ==0 ){
			cout<<0<<endl;
			return;
		}
	}
	substr.clear();
	for(i=0;buffer[i+len]; i++){
		substr.insert(i);
	}
	substr.insert(i);
	cout<<substr.size()<<endl;
}

int main(){
	int blocknum,kind;
	cin>>blocknum;

	while(blocknum--){
		cin>>len>>kind;
		cin>>buffer;
		fun();
		if(blocknum)
			cout<<endl;
	}

	return 0;
}
