#include<iostream>
#include<cstdio>

using namespace std;

int box[30]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,
	89,97,101,103,107,109,113};
int input[30];

struct Num {
	int len;
	int data[30];
	
	int readin();
	void output();
	void add(const Num &);
};

int Num::readin(){
	int t = 0;
	int d;
	char ch;
	do {
		scanf("%d%c",&d,&ch);
		if(feof(stdin))
			return 0;
		input[t++] = d;
	} while(ch==',');
	len = t;
	
	for(int i=0;i<len;i++){
		data[i] = input[--t];
	}
	return 1;
}
void Num::output(){
	int i;
	for(i=len-1;i>0;i--){
		printf("%d,",data[i]);
	}
	printf("%d\n",data[0]);
}

void Num::add(const Num &b){
	int t = 0;
	while(t < b.len && t < len){
		data[t] += b.data[t];
		t ++;
	}
	while(t < b.len){
		data[t] = b.data[t];
		t++;
	}
	while(t < len){
		t = len;
	}
	int i=0, carry = 0;
	
	while(i < t){
		while(data[i] >= box[i] ){
			carry ++;
			data[i] -= box[i];
		}
		i ++;
		if(i == t ){
			if(carry){
				t ++;
				data[i] = carry;
			}
		} else {
			data[i] += carry;			
		}
		carry = 0;
	}
	len = t;
}

int main(){
	Num a,b;  
    
    while(a.readin()){
    	b.readin();
    	a.add(b);
    	a.output();
    }
    
    return 0;
}
