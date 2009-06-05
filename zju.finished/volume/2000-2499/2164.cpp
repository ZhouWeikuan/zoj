#include<iostream>

using namespace std;

enum {
	Size = 54,
};
char *before, *after;
char deck[2][Size];

int main(){
	int i;
	int p,c;
	int n,r;
	int left;
	
	cin>>n>>r;
	while(n!=0 || r!=0){
		before = deck[0];
		after = deck[1];
		for(i=0;i<n;i++){
			before[i] = n -i;
		}
		while(r --){
			cin>>p>>c;
			memmove(after, before,sizeof(char)*(p-1));
			memmove(before, before + p-1,sizeof(char)*(c));
			memmove(before+c, after,sizeof(char)*(p-1));
		}
		left = before[0];
		cout<<left<<endl;

		cin>>n>>r;
	}

	return 0;
}
