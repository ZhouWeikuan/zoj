#include<iostream>
#include<complex>
using namespace std;
enum {
    SIZ = 100004,
    LIM = 1004,
};

template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum<N> & operator=(int );
	BigNum<N> & operator *=(int);
    void operator *=(const BigNum<N> &);
	void operator /=(int);
	unsigned operator %(unsigned);
};

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
void BigNum<N>::operator /=(int dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		d[i] = carry / dm;
		carry = carry % dm;
	}
	while(len > 0 && d[len-1] ==0){
		len--;
	}
}

template<int N>
unsigned BigNum<N>::operator %(unsigned dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		carry %= dm;
	}
	return carry;
}

unsigned tot[SIZ];
unsigned num, mod = 100000;

void init(){
    BigNum<SIZ> cat;
    cat = 1;
    tot[0] = 0;
    for (int n=1; n<SIZ; ++n){
        cat *= (4*n-2);
        cat /= (n+1);
        tot[n] = tot[n-1];
        tot[n] += cat % mod;
    }
}

int main()
{
    init();
    while(scanf("%d%d", &num, &mod)){
    }
    return 0; 
}

