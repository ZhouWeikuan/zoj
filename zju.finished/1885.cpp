#include<iostream>
#include<cmath>
// 数学性强的题目
using namespace std;
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
	BigNum<N> & operator *=(int);
	void operator +=(const BigNum<N> &);
    void println();
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
void BigNum<N>::println(){
	for(int i=len-1;i>=0;i--){
        printf("%d", d[i]);
	}
    printf("\n");
}
int Base, A, B;
BigNum<SIZ> res, tmp;

int fun(){
    if(Base==1||A%B!=0||(A-B)*log(Base*1.0)/log(10.0)>100){
        return -1;
    }
    int cnt = A / B;
    res = 1; tmp = 1;
    for(int i=1; i<cnt; i++){
        for(int j=0;j<B;j++){
            tmp *= Base;
        }
        res += tmp;
    }
    if(res.len > 100) return -1;
    res.println();
    return 1;
}
int main(){

    while(scanf("%d%d%d ", &Base, &A, &B) > 0){
        printf("(%d^%d-1)/(%d^%d-1) ", Base, A, Base, B);
        if(fun()<=0){
            printf("is not an integer with less than 100 digits.\n");
        }
    }
    return 0;
}

