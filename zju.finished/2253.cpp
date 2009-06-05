#include<iostream>
#include<string>
#include<map>
// 使用动态规划超时，只能使用杨式图表了
// 公式为:  (N*M)!/sum(i+j-1), sum(i+j-1)表示当(1<=i<=n&&1<=j<=m)时的
//                          所有值的乘积
using namespace std;
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum<N> & operator=(int );
	BigNum<N> & operator *=(int);
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
		printf("%d", d[i]);
	}
    printf("\n");
}

BigNum<200> mat;

void setup(int n, int m){
    mat = 1;
    int lim = n * m, i;
    for( i=1; i<=lim; i++){
        mat *= i;
    }
    for(i=1; i<=n; ++i){
        for(lim=1; lim<=m; lim++){
            mat/=(i+lim-1);
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    while(n && m){
        if(n > m) swap(n, m);
        setup(n, m);
        mat.print();
        scanf("%d%d",&n,&m);
    }
    return 0;
}

