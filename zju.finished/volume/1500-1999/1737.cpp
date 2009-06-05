#include<iostream>
#include<string>
#include<map>

using namespace std;
typedef void (*fun)(string &);
map<char, fun> table;
void decode_J(string &str){
	string::iterator i = str.end() -1;
	char c = *i;
	str.erase(i);
	str.insert(str.begin(),c);
}

void decode_C(string &str){
	char c = str[0];
	str.erase(str.begin());
	str.push_back(c);
}

void decode_E(string &str){
	int pos = str.length();
	int start, i;
	if(pos % 2==0){
		pos /= 2;
		start = pos;
	} else {
		pos/=2;
		start = pos + 1;
	}
	char c;
	for(i=0;i<pos;i++, start++){
		c=str[i], str[i] = str[start], str[start] = c;
	}
}

void decode_A(string &str){
	reverse(str.begin(),str.end());
}

void decode_P(string &str){
	char c;
	int i;
	for(i=0;i<str.length();i++){
		if(str[i]<='9' && str[i]>='0'){
			c = str[i] -'0';
			c += 9;
			c %= 10;
			c += '0';
			str[i] = c;
		}
	}
}
void decode_M(string &str){
	char c;
	int i;
	for(i=0;i<str.length();i++){
		if(str[i]<='9' && str[i]>='0'){
			c = str[i] -'0';
			c += 1;
			c %= 10;
			c += '0';
			str[i] = c;
		}
	}
}
void init(){
	table['A'] = &decode_A;
	table['C'] = &decode_C;
	table['E'] = &decode_E;
	table['J'] = &decode_J;
	table['M'] = &decode_M;
	table['P'] = &decode_P;
	table['A'] = &decode_A;
}

char buffer[20];

void process(string &str){
	int pos = strlen(buffer);
	fun ptr;
	while(pos --){
		ptr = table[buffer[pos]];
		ptr(str);
	}
	cout<<str<<endl;
}

int main(){
	int tstcase ;
	string msg;
	
	init();
	cin>>tstcase;
	while(tstcase --){
		cin>>buffer>>msg;
		process(msg);
	}
	return 0;
}
