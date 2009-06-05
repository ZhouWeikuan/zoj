#include<iostream>
#include<map>

using namespace std;

int Z,I,M,L;

void fun(){
	map<int, int> table;
	static int casenum = 1;
	int pos = 0;
	
	do{
		table[L] = pos++;
		L = Z*L+I;
		L %= M;
	}while(table.find(L) == table.end());
	
	pos -= table[L];
	
	cout<< "Case "<< casenum++<<": "<<pos <<endl;
}

int main(){
	
	cin>>Z>>I>>M>>L;
	while(Z !=0 || I!= 0 || M!=0 || L!=0){
		fun();
		cin>>Z>>I>>M>>L;
	}
	return 0;
}
