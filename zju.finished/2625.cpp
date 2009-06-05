#include<iostream>
using namespace std;
enum {
    SIZ = 204,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	void operator=(int );
	void operator=(const BigNum<N> & );
	void operator *=(int);
	void operator +=(const BigNum<N> &);
	void print();
};
template<int N>
void BigNum<N>::operator=(int n){
	len = 0;
	do {
		d[len++] = n%10;
		n /= 10;
	} while(n>0);
}

template<int N>
void BigNum<N>::operator=( const BigNum<N> & rhs){
	len = rhs.len;
	for(int i=0;i<len;i++){
		d[i] = rhs.d[i];
	}
}

template<int N>
void BigNum<N>::operator +=( const BigNum<N> & rhs){
    int i, carry = 0;
    for(i=0; i<len&&i<rhs.len; i++){
        carry += d[i] + rhs.d[i];
        d[i] = carry % 10;
        carry /= 10;
    }
    while(i<len){
        carry += d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(i<rhs.len){
        carry += rhs.d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(carry){
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    len = i;
}

template<int N>
void BigNum<N>::operator *=(int m){
	int carry = 0, i;
	for(i=0;i<len;i++){
		carry += d[i] * m;
		d[i] = carry % 10;
		carry /= 10;
	}
	while(carry){
		d[len++] = carry % 10;
		carry /= 10;
	}
}

template<int N>
void BigNum<N>::print(){
	for(int i=len-1;i>=0;i--){
		printf("%d", d[i]);
	}
    printf("\n");
}

BigNum<SIZ> f[101];

void init(){
    f[0] = 0, f[1] = 0, f[2] = 1, f[3] = 3;
    BigNum<SIZ> t;
    for(int i=4; i<101; i++){
        f[i] = f[i-1];
        f[i] *= i-1;
        t = f[i-2];
        t *= i-2;
        f[i] += t;
    }
}

int main(){
    int v;

    init();
    while( scanf("%d", &v) > 0){
        f[v].print();
    }

    return 0;
}

