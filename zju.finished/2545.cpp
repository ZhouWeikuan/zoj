#include<iostream>
#include<map>
#include<cmath>

using namespace std;
map<int,int> table;

void init(){
	int year = 1960;
	unsigned base = 4u;
	double sum = 0.0;
	int start = 0;
	while(year <= 2160){
		while(sum < base){
			start++;
			sum += log2(start);
		}
		table[year] = start-1;
		year += 10;
		base <<=1;
	}
}

int main(){
	int year;
	init();
	cin>>year;
	while(year){
		year /= 10;
		year *= 10;
		cout<<table[year]<<endl;
		cin>>year;
	}
	return 0;
}
