#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 408,
};

template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
        d[0] = 0;
		len = 1;
	}
	BigNum<N> & operator =(const char a[]);
	BigNum<N> & operator=(BigNum<N> & );
	BigNum<N> & operator *=(int);
	BigNum<N> & operator +=(int);
	BigNum<N> & operator +=(const BigNum<N> &);
	BigNum<N> & operator -=(const BigNum<N> &);
	void div(const BigNum<N> &, BigNum<N> &);
	BigNum<N> & operator /=(int);
    void operator *=(const BigNum<N> &);
	int operator %=(int);
	int cmp(const BigNum<N> &);
	template<int O>
	friend ostream& operator<<(ostream& ,BigNum<O>&);
};

template<int N>
void BigNum<N>::div(const BigNum<N> &rhs, BigNum<N> &rem) {
    int i = 0;
    rem = "0";
    BigNum<N> tmp;
    tmp = "0";
    for (i=len-1; i>=0; --i){
        tmp *= 10;
        rem *= 10;
        rem += d[i];
        while(rem.cmp(rhs) >= 0){
            tmp += 1;
            rem -= rhs;
        }
    }
    *this = tmp;
}

template<int N>
BigNum<N> & BigNum<N>::operator=(const char s[]){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
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
BigNum<N> & BigNum<N>::operator +=(int carry){
    int i;
    for(i=0;i<len && carry;i++){
        carry += d[i];
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
}

template<int N>
BigNum<N> & BigNum<N>::operator -=(const BigNum<N> & rhs){
    if (this->cmp(rhs) < 0){ // assume this >= rhs
        throw "smaller than ...";
    }
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
        if (i>=len){
            d[i] = 0;
            ++len;
        }
        d[i] -= carry;
        carry = 0;
        while(d[i] < 0){
            d[i] += 10;
            ++carry;
        }
        ++i;
    }
    while(len > 0 && d[len-1] == 0)
        --len;
    if (len ==0){
        len = 1;
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
int BigNum<N>::operator %=(int dm){
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
	return carry;
}

template<int N>
int BigNum<N>::cmp(const BigNum<N> &rhs){
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

char buf[SIZ];
BigNum<SIZ> a, b, r, *tmp;
BigNum<SIZ> zero, one;

bool gcd(BigNum<SIZ> *a, BigNum<SIZ> *b){
    BigNum<SIZ> *rem = &r;
    if (a->cmp(*b) < 0){
        swap(a, b);
    }
    while(b->cmp(zero) != 0){
        a->div(*b, *rem);
        tmp = a; 
        a = b;
        b = rem;
        rem = tmp;
    }
    cout<<*a<<endl;
}

void fun(){
    gcd(&a, &b);
}

int readIn(){
    if (scanf("%s", buf) < 0)
        return 0;
    a = buf;
    scanf("%s", buf);
    b = buf;
    return 1;
}

int main()
{
    int tst = 0;
    zero = "0"; one = "1";
    while(readIn() > 0){
        if (tst++)
            cout<<endl;
        fun();
    }
    return 0; 
}

