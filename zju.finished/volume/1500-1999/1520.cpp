#include<iostream>
#include<map>

using namespace std;
int M,L;
int boxnum;
int box[2004];
map<unsigned int,int> table;
map<unsigned int,int>::iterator iter;;

int calc(int now, int mindt, int lilka){
	if(now < 0)
		return 1;
	unsigned int key = (now<<22) + (mindt<<11) + (lilka);
	iter = table.find(key);
	if(iter != table.end()){
		return iter->second >= 0;
	}

	if(mindt >= box[now] && calc(now-1,mindt-box[now], lilka)){
		table[key] = 0;
		return 1;
	}
	if(lilka >= box[now] && calc(now-1,mindt,lilka-box[now])){
		table[key] = 1;
		return 1;
	}
	return 0;
}

int top;
int stack[2008];
void traceback(int now, int m, int l){
	if(now < 0)
		return;
	unsigned key = (now<<22) + (m<<11) + (l);
	
	iter = table.find(key);
	if(iter->second ==0){
		stack[top++] = now;
		traceback(now-1,m-box[now],l);
	} else {
		traceback(now-1,m,l-box[now]);
	}
}

void fun(){
	table.clear();
	if(calc(boxnum-1,M,L)){
		top = 0;
		traceback(boxnum-1,M,L);
		cout<<top<<" ";
		for(int i=top-1;i>=0;i--){
			cout<<stack[i]+1<<" ";
		}
		cout<<endl;
	} else {
		cout<<"Impossible to distribute"<<endl;
	}
}

int main(){
	
	cin>>M>>L;
	while(M+L){
		cin>>boxnum;
		for(int i=0;i<boxnum;i++)
			cin>>box[i];
		fun();

		cin>>M>>L;
	}

	return 0;
}
