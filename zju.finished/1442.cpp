#include<iostream>
using namespace std;
enum {
    SIZ = 10,
    LEN = 108,
};
int num, val;
int x[SIZ];

template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum<N> & operator=(int );
	BigNum<N> & operator *=(int);
	BigNum<N> & operator +=(const BigNum<N> &);
	BigNum<N> & operator -=(const BigNum<N> &);
    BigNum<N> & operator /=(int dm);
	template<int O>
	friend ostream& operator<<(ostream& ,BigNum<O>&);
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
        carry /= 10; ++i;
    }
    while(i<rhs.len){
        carry += rhs.d[i];
        d[i] = carry % 10;
        carry /= 10; ++i;
    }
    while(carry){
        d[i] = carry % 10;
        carry /= 10; ++i;
    }
    len = i;
}

template<int N>
BigNum<N> & BigNum<N>::operator -=(const BigNum<N> & rhs){
    int i, carry = 0;
    for(i=0; i<len&&i<rhs.len; i++){
        d[i] -= rhs.d[i] + carry;
        carry = 0;
        while(d[i] < 0) {
            d[i] += 10;
            ++carry;
        }
    }
    while(carry){
        if (i < len){
            d[i] -= carry;
        } else {
            d[i] = -carry;
            len = i + 1; 
        }
        carry = 0;
        while(d[i] < 0){
            d[i] += 10;
            ++carry;
        }
        i++;
    }
    while(len >0 && d[len-1] == 0)
        --len;
    if (len ==0){
        d[0] = 0; len = 1;
    }
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
	while(len > 0 && d[len-1] ==0){
		len--;
	}
	return *this;
}

template<int N>
ostream& operator<<(ostream& o, BigNum<N>& rhs){
	for(int i=rhs.len-1;i>=0;i--){
		o<<rhs.d[i];
	}
	return o;
}

void C(int a, int b, BigNum<LEN> &r){
    if (b > a/2){
        b = a - b;
    }
    r = 1;
    int i;
    for (i=a-b+1; i<=a; ++i)
        r *= i;
    for (i=b; i>=1; --i)
        r /= i;
}

int calc(int s, BigNum<LEN> & r){
    int v = val;
    int o = 0;
    r = 0;
    for (int i=0,j=1; i<num; ++i,j<<=1){
        if (s & j){
            v -= x[i] + 1;
            o = 1 - o;
        }
    }
    if (v >=0) {
        C(v+num-1, num-1, r);
    }
    if (o)
        return -1;
    return 1;
}

void fun(){
    if (val < 0 || val > x[num]){
        cout<<0<<endl;
        return;
    }
    int lim = 1<<num;
    BigNum<LEN> s0, s1, tmp;
    s0 = 0; s1 = 0;
    for (int i=0; i<lim; ++i){
        if (calc(i, tmp) >= 0){
            s0 += tmp;
        } else {
            s1 += tmp;
        }
    }
    s0 -= s1;
    cout<<s0<<endl;
}

void readIn(){
    scanf("%d%d ",&num,&val);
    int a;
    x[num] = 0;
    for(int i=0; i<num; i++){
        scanf("%d%d ", &a, &x[i]);
        x[i] -= a;
        x[num] += x[i];
        val  -= a;
    }
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

