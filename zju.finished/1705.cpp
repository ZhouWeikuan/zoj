#include<iostream>
#include<string>
#include<map>

using namespace std;
map<string,int> name;
int start = 0;
int conn[120];
struct Fact {
	int up;
	int down;
};
Fact table[120][120];

void init(){
	for(int i=0;i<120;i++)
		conn[i] = i;
}

int getName(string &s){
	map<string, int>::iterator iter;
	iter = name.find(s);
	if(iter != name.end()){
		return iter->second;
	}
	name[s] = start;
	return start++;
}
int GCD(int a,int b){
	int t;
	if(a < b){
		t = a , a = b, b = t;
	}
	while(b > 0){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
Fact & calc(int a, int b, int c){
	if(a == b || b== c)
		return table[a][c];
	Fact &one = table[a][b];
	Fact &two = table[b][c];
	Fact f;
	f.up = one.down * two.down;
	f.down = one.up * two.up;
	int x = GCD(f.up, f.down);
	f.up /= x; f.down /= x;
	table[c][a] = f;
	x = f.up; f.up = f.down; f.down = x;
	return table[a][c] = f;
}

int getParent(int n){
	int p = conn[n];
	int t = conn[p];
	int key;
	Fact f;
	while(p!=t){
		if(table[t][n].up ==0){
			calc(t,p,n);
		}
		p = t;
		t = conn[p];
	}
	return t;
}

void insert(string &a, int m, string &b, int n){
	int pa,pb;
	int na,nb;
	na = getName(a);
	nb = getName(b);
	pa = getParent(na);
	pb = getParent(nb);
	int t = GCD(m,n);
	m /= t;
	n /= t;
	Fact f;
	f.up = m; f.down = n;
	table[na][nb] = f;
	f.down = m, f.up = n;
	table[nb][na] = f;

	if(pa < pb){
		calc(pa,na,nb);
		conn[nb] = pa;
		calc(pa,nb,pb);
		conn[pb] = pa;
	} else {
		calc(pb,nb,na);
		conn[na] = pb;
		calc(pb,na,pa);
		conn[pa] = pb;
	}
}

void query(string &a, string &b){
	int na = getName(a);
	int nb = getName(b);
	int pa = getParent(na);
	int pb = getParent(nb);
	if(pa != pb){
		cout<<"? "<<a<<" = "<<"? "<<b<<endl;
		return;
	}
	Fact &f = calc(na,pa,nb);
	cout<<f.up<<" "<<a<<" = "<<f.down<<" "<<b<<endl;
}

int main(){
	int m,n;
	string a,b;
	char c;

	init();
	
	cin>>c;
	while(c != '.'){
		if(c == '!'){
			cin>>m>>a>>c>>n>>b;
			insert(a,m,b,n);
		} else {
			cin>>a>>c>>b;
			query(a,b);
		}
		cin>>c;
	}

	return 0;
}
