#include<iostream>
using namespace std;
enum {
    SIZ = 64,
};
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
	BigNum<N> & operator +=(BigNum<N> &);
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
BigNum<N> & BigNum<N>::operator +=(BigNum<N> &rhs){
    int i =0; int carry = 0;
    while(i<len && i<rhs.len){
        carry += d[i] + rhs.d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(i<len){
        carry += d[i];
        d[i] = carry % 10; carry /= 10;
        i++;
    }
    while(i<rhs.len){
        carry += rhs.d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(carry){
        d[i] = carry % 10; carry /= 10;
        i++;
    }
    if(len < i)
        len = i;
    return *this;
}

template<int N>
ostream& operator<<(ostream& o, BigNum<N>& rhs){
	for(int i=rhs.len-1;i>=0;i--){
		o<<rhs.d[i];
	}
	return o;
}

BigNum<30> f[SIZ][4];
void init(){
    f[0][0] = f[0][1] = f[0][2] = f[0][3] = 1;
    for(int i=1;i<SIZ;i++){
        f[i][0] = f[i-1][2];
        f[i][0] += f[i-1][1];
        f[i][0] += f[i-1][0];
        f[i][1] =  f[i-1][1];
        f[i][1] += f[i-1][0];
        f[i][2] = f[i-1][0];
        f[i][3] = 1;
    }
}

int main(){
    init();
    int n;
    while(cin>>n){
        cout<<f[n][0]<<endl;
    }
    return 0;
}
