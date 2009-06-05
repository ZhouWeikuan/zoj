#include<iostream>
#include<complex>
using namespace std;

typedef complex<double> val_t;
const val_t I = val_t(0, 1);
const double PI = asin(1.0)*2;
const double eps = 1.0e-7;

int rev(int i, int n){
    int d = 0;
    for(int sz=1; sz<n; sz<<=1)
    {
        d<<=1;
        if(i&sz){
            d |= 1;
        }
    }
    return d;
}

void bit_reverse_copy(val_t *s, val_t *d, int n) {
    for(int i=0; i<n; i++){
        d[rev(i, n)] = s[i];
    }
}

val_t * iterative_fft(val_t *a, val_t *A, int n) {
    bit_reverse_copy(a, A, n);

    val_t wm = exp(PI*I);
    for(int m=1; m<n; m<<=1){
        for(int k=0; k<n; k+=2*m){
            val_t w = 1.0;
            for(int j=0; j<m; j++){
                val_t t = w*A[k+j+m];
                A[k+j+m] = A[k+j] - t;
                A[k+j] += t;
                w *= wm;
            }
        }
        wm = sqrt(wm);
    }
    return A;
}

val_t * iterative_inverse_fft(val_t *a, val_t *A, int n) {
    bit_reverse_copy(a, A, n);

    val_t wm = exp(-PI*I);
    for(int m=1; m<n; m<<=1){
        for(int k=0; k<n; k+=2*m){
            val_t w = 1.0;
            for(int j=0; j<m; j++){
                val_t t = w*A[k+j+m];
                A[k+j+m] = A[k+j] - t;
                A[k+j] += t;
                w *= wm;
            }
        }
        wm = sqrt(wm);
    }
    return A;
}

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
	BigNum<N> & operator +=(int);
	BigNum<N> & operator +=(const BigNum<N> &);
	BigNum<N> & operator /=(int);
    void operator *=(const BigNum<N> &);
	int operator %=(int);
	int cmp(BigNum<N> &);
	template<int O>
	friend ostream& operator<<(ostream& ,BigNum<O>&);
};

template<int N>
void BigNum<N>::operator *= (const BigNum<N> &r){
    int n = len > r.len ? len : r.len;
    val_t a[N*2] = {0};
    val_t b[N*2] = {0};
    val_t t[N*2] = {0};
    val_t *x, *y;
    int i, siz;

    for(i=0; i<len; i++){
        a[i].real() = static_cast<double> (d[i]);
    }
    for(i=0; i<r.len; i++){
        b[i].real() = static_cast<double> (r.d[i]);
    }
    for(siz=1; siz<n; siz<<=1)
        ;
    siz<<=1;
    
    x = iterative_fft(a, t, siz);
    y = iterative_fft(b, a, siz);
    for(int i=0; i<siz; i++){
        y[i] *= x[i];
    }

    x = iterative_inverse_fft(y, x, siz);
    len = siz;
    for(i=siz-1; i>=0; i--){
        x[i] /= siz;
        d[i] = (int)round(x[i].real());
    }
    while(len>=1 && d[len-1]==0){
        len--;
    }
    for(i=len-1; i>=0; i--){
        printf("%d, ", d[i]);
    }
    printf("\n");
}

template<int N>
BigNum<N>::BigNum(const char *s){
    extern int strlen(const char *);
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

int main()
{
    int i;
    BigNum<100> a, b;
    scanf("%d ", &a.len);
    for(i=0; i<a.len; i++){
        scanf("%d ", &a.d[i]);
    }
    scanf("%d ", &b.len);
    for(i=0; i<b.len; i++){
        scanf("%d ", &b.d[i]);
    }
    a *= b;

    return 0; 
}
