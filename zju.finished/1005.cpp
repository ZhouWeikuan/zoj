#include<iostream>
#include<set>

using namespace std;
enum {
	FillA = 0,
	FillB = 1,
	EmptyA = 2,
	EmptyB = 3,
	PourAB = 4,
	PourBA = 5,
};
set<int> table;
int op[2000];
int pos;

int Ca,Cb,N;

int fun(int a, int b){
	int key = (a<<16) + b;
	if(table.find(key) != table.end())
		return 0;
	if(a == N || b == N)
		return 1;
	table.insert(key);
	if(a < Ca){ // FillA
		op[pos ++] = FillA;
		if(fun(Ca,b)){
			return 1;
		}
		pos --;
	}
	if(b < Cb){ // FillB
		op[pos ++] = FillB;
		if(fun(a,Cb)){
			return 1;
		}
		pos --;
	}
	if(a >0){ // EmptyA
		op[pos ++] = EmptyA;
		if(fun(0,b)){
			return 1;
		}
		pos --;
	}
	if(b > 0){// EmptyB
		op[pos ++] = EmptyB;
		if(fun(a,0)){
			return 1;
		}
		pos --;
	}
	if(a > 0){//PourAB
		op[pos ++] = PourAB;
		int nb = a + b, na=0;
		if(nb > Cb) {
			na = nb - Cb;
			nb = Cb;
		}
		if(fun(na,nb)){
			return 1;
		}
		pos --;
	}
	if(b > 0){	//PourBA
		op[pos ++] = PourBA;
		int na = a + b, nb=0;
		if(na > Ca){
			nb = na - Ca;
			na = Ca;
		}
		if(fun(na,nb)){
			return 1;
		}
		pos --;
	}
	
	return 0;
}
void print(int n){
	switch(n){
		case FillA:
			cout <<"fill A"<<endl;
			break;
		case FillB:
			cout <<"fill B"<<endl;
			break;
		case EmptyA:
			cout <<"empty A"<<endl;
			break;
		case EmptyB:
			cout <<"empty B"<<endl;
			break;
		case PourAB:
			cout <<"pour A B"<<endl;
			break;
		case PourBA:
			cout <<"pour B A"<<endl;
			break;
	}
}

int main(){
	
	while(cin>>Ca>>Cb>>N){
		pos = 0;
		table.clear();
		fun(0,0);
		for(int i=0;i<pos;i++){
			print(op[i]);
		}
		cout<<"success"<<endl;
	}

	return 0;
}
