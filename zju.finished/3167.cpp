#include<iostream>
#include<complex>
using namespace std;
enum {
    SIZ = 304,
};

int M, K;

template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum<N> & operator *=(int);
    BigNum<N> & operator=(int n);
    bool meet();
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
bool BigNum<N>::meet(){
    return (len>=K) && (d[K-1] == 7);
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

BigNum<SIZ> tmp;

int main()
{
    int ans;
    while(scanf("%d%d", &K, &M) > 0){
        tmp = M;
        ans = 1;
        while(!tmp.meet()){
            tmp *= M;
            ++ans;
        }
        printf("%d\n", ans);
    }

    return 0; 
}

