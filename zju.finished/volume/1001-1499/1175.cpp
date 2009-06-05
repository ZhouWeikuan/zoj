#include<iostream>
enum {
	Size = 100040,
};
using namespace std;

char buffer[Size];
char result[Size];
int start,end;

void output(int s, int e){
	char save;
	int t;
	while(e - s > 80){
		t = s+ 80;
		save = result[t];
		result[t] = 0;
		cout<<result+s<<endl;
		result[t] = save;
		s = t;
	}
	cout<<result+s<<endl;
}
void fun(){
	int ret = 0;
	start = 0, end --;
	int pos = start;
	char cmd;
	cin>>cmd;
	while(cmd != '#'){
		if(cmd == 'R'){
			if(pos == end){
				pos = start;
			} else {
				pos = end;
			}
		} else {
			result[ret++] = buffer[pos];
			if(pos == end){
				pos --, end --;
			} else {
				pos ++, start ++;
			}
		}
		cin>>cmd;
	}
	end = ret;
	result[end] = 0;
	ret = start = 0;
	output(start,end);
}

int main(){
	int blocknum;
	int lines;
	
	cin>>blocknum;
	while(blocknum --){
		cin>>lines;
		cin.getline(buffer,Size);
		end = 0;
		while(lines -- ){
			cin.getline(buffer+end,Size);
			while(buffer[end]){
				end++;
			}
		}
		fun();
		if(blocknum)
			cout<<endl;
	}

	return 0;
}
