#include<iostream>

using namespace std;

char buffer[120];
struct Node {
	union{
		struct Node *link[10];
		int freq;
	};
	Node(){
		int i;
		for(i=0;i<10;i++)
			link[i] = 0;
		freq = 0;
	}
};

Node table;
char stack[10];
int pos = 0,print = 0;

char getMap(char alpha){
	switch(alpha){
		case 'A': 		case 'B':		case 'C':
			return '2';
		case 'D':		case 'E':		case 'F':
			return '3';
		case 'G':		case 'H':		case 'I':
			return '4';
		case 'J':		case 'K':		case 'L':
			return '5';
		case 'M':		case 'N':		case 'O':
			return '6';
		case 'P':		case 'R':		case 'S':
			return '7';
		case 'T':		case 'U':		case 'V':
			return '8';
		case 'W':		case 'X':		case 'Y':
			return '9';
	}
	return '0';
}
void insert(char *s){
	int t;
	Node *p = &table, *q;
	while(*s){
		t = *s -'0';
		if(p->link[t]){
			p = p->link[t];
		}else {
			q = new Node;
			p->link[t] = q;
			p = q;
		}
		s++;
	}
	p->freq ++;
}
int convert(char *s){
	int i = 0,j=0;
	
	while(s[i]){
		if(s[i] != '-'){
			if(s[i] <='Z' && s[i]>='A'){
				s[i] = getMap(s[i]);
			}
			s[j++] = s[i];
		}
		i++;
	}
	s[j] = 0;
	insert(s);
}

void trace(Node *n, int deep){	
	if(deep == 7){
		int t = *(int *) n;
		if(t <2 )
			return;
		cout<<stack[0]<<stack[1]<<stack[2]<<'-'
			<<stack[3]<<stack[4]<<stack[5]<<stack[6]
			<<" "<< t <<endl;
		print ++;
		return;
	}
	int i;
	for(i=0;i<10;i++){
		if(n->link[i]){
			stack[pos ++] = '0' + i;
			trace(n->link[i],deep + 1);
			delete n->link[i];
			pos --;
		}
	}
}

int fun(){
	int i;
	print = pos = 0;
	for(i=0;i<10;i++){
		if(table.link[i]){		
			stack[pos++] = '0' + i;
			trace(table.link[i],1);
			delete table.link[i];
			table.link[i] = 0;
			pos --;
		}
	}
	return print;
}

int main(){
	int tstcase, num;
	cin>>tstcase;
	while(tstcase --){
		pos = 0;
		cin>>num;
		while(num --){
			cin>>buffer;
			convert(buffer);
		}
		
		num = fun();
		if(num == 0){
			cout<<"No duplicates."<<endl;
		}
		
		if(tstcase)
			cout<<endl;
	}
	

	return 0;
}
