#include<iostream>

/*解题思路：

       这个题目直接求合理的排序比较烦琐，采用模拟的方法也显然不行。可以先考虑可以实现的概率，再用实际的总次数去乘。

       先把所有的n个拿50的人排好，接下来再把拿100的人插入队列。求可行的概率。

       n个拿50的人有n+1个空位，除了第一个以外，其他的位置都可以，所以概率是n/n+1，在以上的基础下，第2个的的概率是n-1/n（由于是求概率，所以可以把所有的拿50或100的人看成是一样的，在这个前提下可以认为第一个拿50的人和第一个拿100的人一起消失了。为什么可以这么认为？由于在求概率，不去除的化会重复计算，具体读者自己思考）。

同理直到最后一个拿100的插入队列，他成功的概率是n-m+1/n-m+2。

       以上所有都发生，才使最后的队伍满足要求。所以最后成功的概率是n-m+1/n+1。再乘上全部的排列就是答案(m+n)!*(n-m+1)/(n+1)

       这样就可以了吗？不是的，注意题目数据范围，还要使用高精度才可以AC！
       */

using namespace std;
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

BigNum<500> tree[201];
void init(){
	tree[0] = 1;
	for(int i=1;i<201;i++){
		tree[i] = tree[i-1];
		tree[i] *= i;
	}
}

int N,M;

void fun(){
	BigNum<500> r;
	r = tree[N+M];
	r *= (N-M+1);
	r /= (N+1);
	cout<<r<<endl;
}

int main(){
	int tstnum = 0;
	init();	
	
	cin>>N>>M;
	while(N + M){
		tstnum++;
		cout<<"Test #"<<tstnum<<":"<<endl;
		if(N < M){
			cout<<0<<endl;
		} else {
			fun();
		}
		cin>>N>>M;
	}

	return 0;
}
