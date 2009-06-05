#include<iostream>
using namespace std;
// 与catalan数类似，但注意建立递推关系 
/*
 *
 *  guess,  1  ----> 1				3 * (3n+1)(3n+2)
 *			f(n+1) = f(n) * ------------------------------------
 									(n+2)(n+3)									
 */																
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum(const char *);
	BigNum<N> & operator=(int );
	BigNum<N> & operator=(BigNum<N> & );
	BigNum<N> & operator *=(int);
	BigNum<N> & operator /=(int);
	int cmp(BigNum<N> &);
	template<int O>
	friend ostream& operator<<(ostream& ,BigNum<O>&);
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
BigNum<N> & BigNum<N>::operator=(int n){
	len = 0;
	do {
		d[len++] = n%10;
		n /= 10;
	} while(n>0);
	return *this;
}

template<int N>
BigNum<N> & BigNum<N>::operator=(BigNum<N> & rhs){
	len = rhs.len;
	for(int i=0;i<len;i++){
		d[i] = rhs.d[i];
	}
	return *this;
}

template<int N>
BigNum<N> & BigNum<N>::operator *=(int m){
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
	return *this;
}

template<int N>
BigNum<N> & BigNum<N>::operator /=(int dm){
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
	return *this;
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
ostream& operator<<(ostream& o, BigNum<N>& rhs){
	for(int i=rhs.len-1;i>=0;i--){
		o<<rhs.d[i];
	}
	return o;
}

BigNum<100> tree[62];
void init(){
	tree[0] = 1;
    tree[1] = 1;
	for(int n=1;n<60;n++){
		tree[n+1] = tree[n];
        tree[n+1] *= 3 * (3*n+1);
        tree[n+1] *= 3*n + 2;
        tree[n+1] /= (n+2);
        tree[n+1] /= (n+3);
	}
}

int main(){
	init();
	int num;
	while(cin>>num){
		cout<<tree[num]<<endl<<endl;
	}
	
	return 0;
}
