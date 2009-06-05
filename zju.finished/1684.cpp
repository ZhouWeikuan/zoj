#include<iostream>
#include<vector>
#include<string>

using namespace std;
char digit[400];
int num;
vector<string> wordlist;

struct Node {
	vector<int> word;
	int ptr[10];
};

Node tree[1000];
int next;
void init(){
	next = 1;
	memset(tree[0].ptr,0,sizeof(tree[0].ptr));
}
int getnext(){
	tree[next].word.clear();
	memset(tree[next].ptr,0,sizeof(tree[next].ptr));
	return next++;
}

int getNum(char c){
	switch(c){
	case 'a': case 'b': case 'c':
		return 2;
	case 'd': case 'e': case 'f':
		return 3;
	case 'g': case 'h': case 'i':
		return 4;
	case 'j': case 'k': case 'l':
		return 5;
	case 'm': case 'n': case 'o':
		return 6;
	case 'p': case 'q': case 'r': case 's':
		return 7;
	case 't': case 'u': case 'v':
		return 8;
	case 'w': case 'x': case 'y': case 'z':
		return 9;
	}
	return 0;
}

void insert(int pos){
	const char *s = wordlist[pos].c_str();
	int cur = 0,t;
	for(int i=0; s[i] ; i++){
		t = getNum(s[i]);
		if(tree[cur].ptr[t] ==0){
			tree[cur].ptr[t] = getnext();
		}
		cur = tree[cur].ptr[t];
	}
	tree[cur].word.push_back(pos);
}
int q[100],top;
vector<string> lines;
void insertline(){
	string s;
	if(top ==0)
		return;
	s += wordlist[q[0]];
	for(int i=1;i<top;i++){
		s+=" ";
		s+=wordlist[q[i]];
	}
	s+=".";
	lines.push_back(s);
}
void output(){
	sort(lines.begin(), lines.end());
	for(vector<string>::iterator i=lines.begin(); i!= lines.end(); i++){
		cout<<*i<<endl;
	}
}

void query(int cur,int s){
	int t;
	if(digit[s] ==0 && cur ==0){
		insertline();
	}
	while(digit[s]){
		t = digit[s] - '0';
		if(tree[cur].ptr[t] == 0)
			return;
		cur = tree[cur].ptr[t];
		for(int i=0; i< tree[cur].word.size(); i++){
			q[top++] = tree[cur].word[i];
			query(0,s+1);
			top --;
		}
		s ++;
	}
}

int main(){
	int t;	
	string s;
	cin>>num;
	while(num){
		init();
		wordlist.clear();
		t = num;
		while(num--){
			cin>>s;
			wordlist.push_back(s);
		}
		num = t;
		sort(wordlist.begin(),wordlist.end());
		for(t = 0; t<num;t++)
			insert(t);
		cin>>digit;
		top = 0;
		lines.clear();
		query(0,0);
		output();
		cout<<"--"<<endl;

		cin>>num;
	}

	return 0;

}
