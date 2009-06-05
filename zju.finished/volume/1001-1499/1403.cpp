#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
char buffer[32];
int pos;
int num;

int visit[32];
int stack[10];
int top;

int dfs(int deep, int sign, int v){
	if(deep==5 ){
		return (v == num);
	}
	int i,t;
	int nv;
	for(i=0;i<pos;i++){
		t = buffer[i] - 'A';
		if(visit[t] == 1)
			continue;
		visit[t] = 1;
		nv = 1;
		stack[top++] = t;
		for(int j=0;j<=deep;j++){
			nv *= (t+1);
		}
		if( dfs(deep +1, sign *-1, v + sign * nv)){
			return 1;
		}
		--top;
		visit[t] = 0;
	}
	return 0;
}

int fun(){
	int i,t;
	int flag = 0;
	top = 0;
	memset(visit,0,sizeof(visit));
	pos = strlen(buffer);
	sort(buffer,buffer+pos, greater<char>());
	for(i=0;i<pos;i++){
		t= buffer[i] -'A';
		visit[t] = 1;
		stack[top++] = t;
		if(dfs(1,-1, t+1)){
			flag = 1;
			break;
		}
		--top;
		visit[t] = 0;
	}
	if(flag ==0)
		return 1;
	for(i=0;i < 5;i++){
		printf("%c", 'A' + stack[i]);
	}
	
	printf("\n");
	return 0;
}

int main(){
	
	cin>>num>>buffer;
	while(num){
		if(fun()){
			cout<<"no solution"<<endl;
		}

		cin>>num>>buffer;
	}
	
	return 0;
}
