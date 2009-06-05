#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef struct {
	int value;
	int count;	
}Node ;

struct mycompare{
	int operator()(const Node & a, const Node &b){
		return b.value < a.value;
	}
};

map<int,int> mask;
vector<Node> number;
int sum[16];
int stack[16];
int spointer;

int total, pos;
int printnum;

void print_stack(){
	int i;
	cout<<stack[0];
	for(i=1;i<spointer;i++){
		cout<<'+'<<stack[i];
	}
	cout<<endl;
}

void run(int left, int index){	
	if(left ==0){
		print_stack();
		printnum ++;
		return;
	}
	if(index>= number.size()|| left < 0){
		return;
	}
	if(left > sum[index]){
		return;
	}	
	int i = 0,j;
	int n = number[index].count * number[index].value;
	
	for(i=0;i<number[index].count;i++){
		stack[spointer ++ ] = number[index].value;
	}	
	
	for(i=0;i<=number[index].count;i++){
		run(left - n, index+1);
		n -= number[index].value;
		spointer --;
	}
	spointer ++;	
}


void fun(){	
	printnum = 0;
	if(total == 0){
		return;
	}
    mask.clear();
    number.clear();      
    spointer = 0;    
    
    int n= 0,i;
    int t;
    Node node = {0,1};
    for(i=0;i<pos;i++){
		cin>> t;
		if(mask.find(t) != mask.end()){
			number[ mask[t] ].count ++;
		} else {
			node.value =t ;
			number.push_back(node);
			mask[t] = n;
			n ++;
		}
	}
    pos = n;
    mycompare c;
    sort(number.begin(), number.end(),c);
	sum[pos] = 0;
	for(i=pos-1;i>=0;i--){
		n = 0;
		for(t=0;t<number[i].count;t++){
			n += number[i].value;
		}
		sum[i] = sum[i+1] + n;
	}
	 
    run(total,0);
}

int main(){
    
    cin>>total>>pos;
    while(pos){
		cout<<"Sums of " << total << ":" << endl;
		fun();
		if(!printnum){
			cout<<"NONE"<<endl;
		}
		cin>>total>>pos;		
	}
    
    return 0;
}
