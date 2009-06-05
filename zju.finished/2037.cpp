//大整数乘法！
#include<iostream>
#include<set>

using namespace std;
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum(const char *);
	BigNum& operator=(const char *);
	BigNum& operator=(int );
	BigNum& operator=(BigNum<N> &);
	void mult(int );
	void div(int);
	int cmp(BigNum<N> &);
	template<int O>
	friend ostream& operator<<(ostream &,BigNum<O> &);
};
template<int N>
BigNum<N>::BigNum(const char *s){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
}
template<int N>
BigNum<N> & BigNum<N>::operator=(const char *s){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
	return *this;
}

template<int N>
BigNum<N> & BigNum<N>::operator=(int n){
	len = 0;
	do {
		d[len++ ] = n % 10;
		n /= 10;
	} while(n > 0);
	return *this;
}

template<int N>
BigNum<N> & BigNum<N>::operator=(BigNum<N> &rhs){
	len = rhs.len;
	for(int i=0;i<len;i++){
		d[i] = rhs.d[i];
	}
	return *this;
}
template<int N>
void BigNum<N>::mult(int m){
	int carry = 0;
	int i;
	for(i=0;i<len;i++){
		carry += d[i] * m;
		d[i] = carry % 10;
		carry /= 10;
	}
	while(carry){
		d[len++] = carry % 10;
		carry /= 10;
	}
	if(len > N){
		cout<<"Stack OverFlow...."<<endl;
	}
}

template<int N>
void BigNum<N>::div(int dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		d[i] = carry / dm;
		carry = carry % dm;
	}
	while(d[--len] ==0){
		;
	}
	len ++;
}

template<int N>
int BigNum<N>::cmp(BigNum<N> &rhs){
	if(len != rhs.len)
		return len - rhs.len;
	for(int i= len-1;i>=0;i--){
		if(d[i] != rhs.d[i])
			return d[i] - rhs.d[i];
	}
	return 0;
}

template<int N>
ostream& operator<<(ostream &o,BigNum<N> &rhs){
	for(int i=rhs.len-1;i>=0;i--){
		o<<rhs.d[i];
	}
	return o;
}

enum {
	Size = 1004,
};
typedef BigNum<100> myType;
struct Node {
	myType val;
	set<int> div;
};
set<int>::iterator it;

Node tree[Size];
void init(){
	char buf[2] = "0";
	tree[0].val = buf;
	for(int i=1;i<=4;i++){
		buf[0] = i + '0';
		tree[i].val = buf;
		tree[i].div.insert(i);
	}
}

void mycopy(set<int> &d, set<int> &s){
	for(it=s.begin();it!=s.end();it++){
		d.insert(*it);
	}
}

void calc(int n){
	if(tree[n].val.len > 0)
		return;
	int save = 0;
	myType val;
	
	for(int i=1;i<n;i++){
		int left = n - i;
		calc(left);
		it = tree[left].div.find(i);
		if(it!= tree[left].div.end())
			continue;
		myType t = tree[left].val;
		t.mult(i);
		if(t.cmp(val) > 0){
			val = t;
			save = i;
		}
	}
	if(save ==0){
		tree[n].div.insert(n);
		tree[n].val = n;
	} else {
		mycopy(tree[n].div, tree[n-save].div);
		tree[n].div.insert(save);
		tree[n].val = val;
	}
}

int main(){
	int num,n;

	init();
	cin>>num;
	while(num--){
		cin>>n;
		calc(n);
		//cout<<tree[n].val<<endl;
		it = tree[n].div.begin();
		cout<<*it;
		it++;
		for(;
			it!=tree[n].div.end();
			it++){
			cout<<" "<<*it;
		}
		cout<<endl;
		if(num)
			cout<<endl;
	}

	return 0;
}
