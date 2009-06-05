#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

vector<int> mat[12];
int bitmask[12];
int top;
int num;

int fun(int cur){
	if(cur==0 && top == num)
		return 1;
	if(bitmask[cur] )
		return 0;
	bitmask[cur] = 1;
	top ++;
	int i;
	for(i=0;i<mat[cur].size();i++){
		if(fun(mat[cur][i])){
			return 1;
		}
	}
	bitmask[cur] = 0;
	top -- ;
	return 0;
}

int main(){
	int i,t,tstcase = 0;
	char ch;
	scanf("%d",&num);
	while(num){
		num++;
		memset(bitmask,0,sizeof(bitmask));
		mat[0].clear();
		for(i=1;i< num;i++){
			mat[i].clear();
			do {
				scanf("%d%c",&t,&ch);
				if(i > t){
					mat[t].push_back(i);
					mat[i].push_back(t);
				}
			} while(ch!='\n');
		}
		top = 0;
		t = fun(0);
		cout<<"Case "<<++tstcase<<": Granny can";
		if(t == 0){
			cout<<" not";
		}
		cout<<" make the circuit."<<endl;
		scanf("%d",&num);
	}

	return 0;
}
