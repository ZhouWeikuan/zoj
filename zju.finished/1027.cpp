#include<iostream>
#include<map>

using namespace std;

map<unsigned, int> table;

char first[120];
char second[120];
int matrix[5][5] = {
	{0,-3,-4,-2,-1},
	{-3,5,-1,-2,-1},
	{-4,-1,5,-3,-2},
	{-2,-2,-3,5,-2},
	{-1,-1,-2,-2,5}
};

int calc(int i, int j){
	unsigned key = (i<<16)+j;
	if(table.find(key) != table.end()){
		return table[key];
	}
	if(first[i]==0 || second[j] ==0){
		if(first[i] ==0){
			if(second[j]==0){
				table[key] = 0;
				return 0;
			} else {
				table[key] = calc(i,j+1) + matrix[0][second[j]];
				return table[key];
			}
		} else {
			table[key] = calc(i+1,j) + matrix[0][first[i]];
			return table[key];
		}
	}
	int t = calc(i+1,j) + matrix[0][first[i]];
	int s = calc(i,j+1) + matrix[0][second[j]];
	if(s > t)
		t = s;
	s = calc(i+1,j+1) + matrix[first[i]][second[j]];
	if(s > t)
		t = s;
	table[key] = t;
	return t;
}
void preprocess(char *s){
	int i;
	for(i=0;s[i];i++){
		switch(s[i]){
			case 'A':
				s[i] = 1;
				break;
			case 'C':
				s[i] = 2;
				break;
			case 'G':
				s[i] = 3;
				break;
			case 'T':
				s[i] = 4;
				break;
		}
	}
}

int main(){
	int tstcase;
	int m,n;

	cin>>tstcase;
	while(tstcase --){
		cin>>m>>first;
		cin>>n>>second;
		preprocess(first);
		preprocess(second);
		table.clear();
		m = calc(0,0);
		cout<<m<<endl;
	}

	return 0;
}
