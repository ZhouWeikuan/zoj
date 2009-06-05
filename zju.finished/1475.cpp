#include<iostream>
using namespace std;
enum {
    SIZ = 208,
    LEN = 420,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len  = 1;
        d[0] = 0;
	}
	void operator=(int );
	void operator=(const BigNum<N> & );
	void operator *=(int);
	const BigNum<N> & operator *(int);
	BigNum<N> & operator +=(const BigNum<N> &);
    void print();
};

static BigNum<LEN> tmp;

template<int N>
void BigNum<N>::operator=(int n){
	len = 0;
	do {
		d[len++] = n%10;
		n /= 10;
	} while(n>0);
}

template<int N>
void BigNum<N>::operator=(const BigNum<N> & rhs){
	len = rhs.len;
	for(int i=0;i<len;i++){
		d[i] = rhs.d[i];
	}
    d[len] = 0;
}

template<int N>
const BigNum<N> & BigNum<N>::operator *(int carry){
    tmp = *this;
    tmp *= carry;
    return tmp;
}

template<int N>
BigNum<N> & BigNum<N>::operator +=( const BigNum<N> & rhs){
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
    d[len] = 0;
}

template<int N>
void BigNum<N>::operator *=(int m){
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
    d[len] = 0;
}

template<int N>
void BigNum<N>::print(){
	for(int i=len-1;i>=0;i--){
		printf("%d", d[i]);
	}
    printf("\n");
}

BigNum<LEN> m[SIZ];
BigNum<LEN> save[2][SIZ];

void init(){
    int pre = 0, cur = 1;
    m[1] = 1;
    save[pre][1] = 1;
    for(int n=2;n<=200;n++){
        for(int i=1;i<n;i++){
            // append in the middle
            save[cur][i+1] += save[pre][i] * (i+1);
            // add to list.
            save[cur][i] += save[pre][i] * i;
        }
        m[n] = 0;
        for(int i=1;i<=n;i++){
            m[n] += save[cur][i];
            save[pre][i] = 0;
        }
        pre = cur;
        cur = 1 - pre;
    }

}

int main(){
    init();
    int n;

    while(cin>>n && n > 0){
        m[n].print();
    }

    return 0;
}

