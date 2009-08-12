#include<iostream> 

using namespace std;
enum {
    LIM = 40,
    SIZ = 800,
};

template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum<N> & operator=(int );
	BigNum<N> & operator=(BigNum<N> & );
	BigNum<N> & operator *=(int);
	BigNum<N> & operator +=(int);
	BigNum<N> & operator +=(const BigNum<N> &);
	BigNum<N> & operator -=(const BigNum<N> &);
	BigNum<N> & operator /=(int);
	int operator %=(int);
	int cmp(const BigNum<N> &);
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

int primes[LIM] = {2,3,5,7};
int num = 4, val;
BigNum<LIM> tab[SIZ][LIM], tmp;

void initTab(){
    int i, n;
    for (i=0; i<LIM; ++i)
        tab[0][i] = 1;
    for (n=1; n<SIZ; ++n){
        tab[n][0] = 1;
        for (i=0; i<LIM; ++i){
            if (i > 0)
                tab[n][i] = tab[n][i-1];
            int sub = primes[i];
            while(n>= sub){
                if (i>0){
                    tmp = tab[n-sub][i-1];
                    tmp *= primes[i];
                } else {
                    tmp = sub;
                }

                if (tab[n][i].cmp(tmp) < 0)
                    tab[n][i] = tmp;
                sub *= primes[i];
            }
        }
    }
}

void fun(){
    cout<<tab[val][LIM-1]<<endl;
}

void init(){
	int flag;
	for(int n=9; num<LIM; n+=2){
		flag = 0;
		for(int i=0; primes[i]*primes[i]<= n;i++){
			if(n % primes[i] == 0){
				flag = 1;
				break;
			}
		}
		if(flag ==0){
			primes[num++] = n;
		}
	}
}

int main(){
	init();
    initTab();
	while(scanf("%d",&val) > 0){
        fun();
    }
	return 0;
}

