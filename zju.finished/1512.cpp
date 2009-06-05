#include<iostream>
using namespace std;
// 递推法，当n-1个城市已经确定好方案时，再加入第n个城市，应该怎么办？
enum {
    SIZ = 108,
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
	BigNum<N> & operator +=(const BigNum<N> &);
	BigNum<N> & operator /=(int);
	void print();
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
void BigNum<N>::print(){
	for(int i=len-1;i>=0;i--){
		printf("%d",d[i]);
	}
    printf("\n");
}
BigNum<44> mat[SIZ][SIZ];

void init(){
    mat[1][0] = mat[1][1] = 1;
    int i,j;
    for(i=2; i<=100; i++){
        mat[i][i] = 1; // if none of below have
        for(j=1; j<i; j++){
            mat[i][j] = mat[i-1][j];
            mat[i][0] += mat[i][j];
            mat[i][j] *= (i-j);
            mat[i][i] += mat[i][j];
            mat[i][j] /= (i-j);
        }
        mat[i][0] += mat[i][i];
    }
}

int main(){
    int t;
    init();
    while(scanf("%d", &t) > 0){
        mat[t][0].print();
    }
    return 0;
}

