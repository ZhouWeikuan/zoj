#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>

using namespace std;
typedef unsigned char uchar;

uchar buffer[1024];
int len;

struct Node {
	unsigned int freq:16;
	unsigned int deep:8;
	unsigned int pred:8;
};
map<uchar, Node> table;

struct comp{
	int operator()(uchar a, uchar b){
		return table[a].freq > table[b].freq;
	}
};

priority_queue<uchar, vector<uchar>, comp > myque;

void compute_deep(uchar c){
	Node &n = table[c];
	if(n.deep)
		return ;
	if(n.pred ==0){
		n.deep =1;
	} else {
		compute_deep(n.pred);
		n.deep = table[n.pred].deep + 1;
	}
}

int calc(){
	map<uchar,Node>::iterator iter;	
	int ret = 0;
	for(iter=table.begin();iter!= table.end();iter++){
		compute_deep(iter->first);
		if(iter->first <128 ){
			Node &t = iter->second;
			ret += (t.deep-1) * t.freq;
		}
	}
	return ret;
}

void fun(){
    int i;
    len = 0;    
    table.clear();    
    
    for(i=0;buffer[i];i++){
		table[buffer[i]].freq++;
	}
	len = i;
	if(table.size() < 3){		
		cout<< len*8 <<" "<<len<<" ";
		cout.precision(1);
		cout<<fixed<<8.0<<endl;
		return;
	}
	
	map<uchar,Node>::iterator iter;
	for(iter=table.begin();iter!= table.end();iter++){
		myque.push(iter->first);
	}
	
	uchar first,second;
	uchar start = 128;
	first = myque.top();
	myque.pop();
	second = myque.top();
	myque.pop();
	table[start].freq = table[first].freq + table[second].freq;
	table[first].pred = start;
	table[second].pred = start;
	while(!myque.empty()){
		myque.push(start);
		start ++;
		first = myque.top();
		myque.pop();
		second = myque.top();
		myque.pop();
		table[start].freq = table[first].freq + table[second].freq;
		table[first].pred = start;
		table[second].pred = start;
	}
	table[start].pred = 0;
	int t = calc();
	int num = len * 8;
	cout<<num<<" "<< t <<" ";
	double ratio = num *1.0/t;
	cout.precision(1);	
	cout<<fixed<<ratio<<endl;
}

int main(){
    
    cin>>buffer;
    while(strcmp("END", (const char *)buffer)!=0){
		fun();
		cin>>buffer;
	}
    
    return 0;
}
