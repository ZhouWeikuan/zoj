#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

struct Node {
	char id[108];
	int freq;
};

Node word[1008];
int seq[1008];
int num;
int alpha2digit[26];
map<string, string> table;
map<string, int> save;

struct MyComp{
	int operator()(const int &a, const int &b){
		char *x,*y;
		x = word[seq[a]].id; y = word[seq[b]].id;
		return strcmp(x,y) < 0;
	}
};

void init(){
	alpha2digit['a' -'a'] = 2; alpha2digit['b'-'a'] = 2; alpha2digit['c'-'a'] = 2;
	alpha2digit['d' -'a'] = 3; alpha2digit['e'-'a'] = 3; alpha2digit['f'-'a'] = 3;
	alpha2digit['g' -'a'] = 4; alpha2digit['h'-'a'] = 4; alpha2digit['i'-'a'] = 4;
	alpha2digit['j' -'a'] = 5; alpha2digit['k'-'a'] = 5; alpha2digit['l'-'a'] = 5;
	alpha2digit['m' -'a'] = 6; alpha2digit['n'-'a'] = 6; alpha2digit['o'-'a'] = 6;
	alpha2digit['p' -'a'] = 7; alpha2digit['q'-'a'] = 7; alpha2digit['r'-'a'] = 7; alpha2digit['s' -'a']=7;
	alpha2digit['t' -'a'] = 8; alpha2digit['u'-'a'] = 8; alpha2digit['v'-'a'] = 8;
	alpha2digit['w' -'a'] = 9; alpha2digit['x'-'a'] = 9; alpha2digit['y'-'a'] = 9; alpha2digit['z' -'a']=9;
}

void insert(char *s, int pos, int freq){
	string value(s,pos);
	string key(value);
	int i;
	for(i=0;i<key.length();i++){
		key[i] = alpha2digit[key[i] -'a'] + '0';
	}
	map<string,int>::iterator iter = save.find(key);
	if(iter == save.end() || iter->second < freq){
		table[key] = value;
		save[key] = freq;
	}
}

void parse(int offset, int start, int end){
	int sum,i;
	int a,b;
	if(end <= start)
		return;
	a = seq[start];
	sum = word[a].freq;
	if(word[a].id[offset] == 0){
		insert(word[a].id, offset, sum);
		parse(offset,start+1,end);
		return;
	}
	
	for(i=start+1;i < end; i++){
		b = seq[i];
		if( (word[a].id[offset]) == (word[b].id[offset]) ){
			sum += word[b].freq;
		} else {
			break;
		}
	}
	
	insert(word[a].id,offset+1,sum);
	
	parse(offset+1,start,i);
	parse(offset,i,end);

}

void complete(string & s){
	int i;
	string key;
	map<string, string>::iterator iter;
	for(i=0;s[i] !='1';i++){
		key += s[i];
		iter = table.find(key);
		if(iter != table.end()){
			cout<<iter->second<<"\n";
		}else {
			cout<<"MANUALLY\n";
		}
	}
}
int main(){
	int tstnum, tstcase = 0;
	int i;
	string s;
	init();
	cin>>tstnum;
	while(tstnum--){
		table.clear();
		save.clear();
		cin>>num;
		for(i=0; i<num; i++){
			cin>>word[i].id>>word[i].freq;
			seq[i] = i;
		}
		sort(seq,seq+num, MyComp());
		parse(0,0,num);
		cout<<"Scenario #"<<++tstcase<<":\n";
		cin>>i;
		while(i--){
			cin>>s;
			complete(s);
			cout<<"\n";
		}
		cout<<"\n";
	}

	return 0;
}
